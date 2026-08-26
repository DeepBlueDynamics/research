.. _memory:

Memory Management in pntOS
==========================

In pntOS, memory is passed between plugin boundaries quite often, sometimes
transferring ownership of memory from one plugin to another and sometimes not.
In general it is unsafe to deallocate memory using a different library than the
allocator used. In addition, it becomes difficult to reason about who owns the
memory and which plugin is responsible for cleaning up the memory to prevent a
leak.

Data is shared between two plugins in pntOS by calling function pointers
defined on a structure implemented by a different plugin. For example, consider
the following struct:

.. code-block:: c
    :linenos:

    typedef struct PntosFoo {
        PntosManagedMemory* memory;
        void (*do_work)(int a);
        void (*more_work)(PntosString* s);
        void (*other_work)(char* s);
        void (*stateful_work)(struct PntosFoo* self, PntosString* s);
    } PntosFoo;

In pntOS, the struct :code:`PntosFoo` might be populated by plugin A and then passed
to plugin B for usage. In this case, plugin B might have a :code:`PntosFoo *
foo` which it may use to request plugin A to do work. Suppose that plugin B used
its pointer to a :code:`PntosFoo` in the following manner:

.. code-block:: c
    :linenos:

    // Code running in plugin B
    void plugin_b_main() {
        // Plugin B receiving a copy of a `PntosFoo` from plugin A, via some
        // call to the controller
        PntosFoo * foo = controller->get_foo(controller);

        // Ask plugin A to do work
        foo->do_work(5);
        // Ask plugin A to do more work
        foo->more_work(pntos_string_new("hi"));
        // Ask plugin A to do other work
        foo->other_work("hi");
        // Ask plugin A to do other work, passing in the struct as context
        foo->stateful_work(foo, pntos_string_new("hi"));
    }

Now the question can be asked: who owns the memory for the pointers passed to
:code:`more_work`, :code:`other_work`, and :code:`stateful_work`? Who cleans up
those allocations? To answer this question, pntOS has a set of core memory management rules
regarding memory handling.

Memory Manager Core Rules
-------------------------

When memory passes across a pntOS API boundary -- such as in the above example
where a function pointer was defined by one plugin but invoked by another -- a
set of rules dictates the memory ownership and management burdens for both
caller and callee. The first rule in the below list that matches is the one that
applies in a given situation:

1. If a parameter has the same type as the struct the function pointer is
   defined in and is named :code:`self`, then the parameter is a context object and it
   is **non-retained**. The memory is owned by the caller and the callee only
   has a temporary reference to it, valid for the duration of the function call.
   In the above example :code:`struct PntosFoo* self` qualifies because it is
   named :code:`self` and is being passed into a method that is contained in a struct
   of type :code:`PntosFoo` (the same type as the parameter).

2. If a parameter's type begins with the name :code:`Pntos` and the parameter is a pointer, then the
   parameter has a **pntOS Managed Type** and **ownership of a local reference to the memory is
   being transferred to the callee**. In this case, the callee has a memory management burden to
   inform the original allocator when it is done using it. In the above example both
   :code:`PntosString* s` references qualify, as they are pointers of type :struct:`PntosString`,
   which begins with :code:`Pntos`.

3. All other parameters are **non-retained**. The memory is owned by the caller
   and the callee only has a temporary reference to it, valid for the duration
   of the function call. In the above example, both the :code:`char * s` and
   :code:`int a` parameters qualify, as they meet none of the other conditions.

For cases where the parameters are non-retained, the memory must not be retained
by the callee after the function has returned. The parameter may be used for the
duration of the function call, and is guaranteed to be valid until the function
returns.

For pntOS managed types, a reference to the object is being transferred to the callee, and the
callee now has the burden to inform the original allocator when it is done using the memory. The
callee cannot deallocate these objects directly, as it does not know what allocation method was used
to create the memory by the original plugin. In the next section we will discuss how callees inform
the original allocator when they are done using pntOS managed types.

Handling pntOS Managed Memory Created by Another Plugin
-------------------------------------------------------

When a pntOS managed type is passed between plugins in pntOS, the function
caller passes ownership of a local reference to the memory to the callee, along with
the burden to indicate when it is done using the memory and that it is
available for cleanup. This is because it is unsafe to deallocate
memory using a different library than the allocator used, and because pntOS
plugins can be implemented in a variety of different languages (and zero-copy
data sharing between plugins is a design goal). So no alloc/free function pair can
be guaranteed to be the right one to use on a given piece of memory. Thus the
callee does not directly know how to clean up the memory it has been given, and
instead a mechanism is needed for the receiver to indicate back to the original
allocator of the memory that it should clean up the memory using the correct
function.

pntOS uses a reference counting mechanism in order to allow a plugin to indicate
to an original allocator that it no longer needs access to a pntOS managed type
that it has received from another plugin. A pntOS managed type will always have
a pointer to a :struct:`PntosManagedMemory` as its first field (or as the first
field of its first field, etc., recursively). When a plugin has received a
managed pntOS type, it innately receives a single local reference to that memory. When
the plugin is done with that memory, it may access the parameter's first field
(a :struct:`PntosManagedMemory * <PntosManagedMemory>`) and call the
:member:`~PntosManagedMemory::dec_ref` function on the
:struct:`PntosManagedMemory` struct in order to indicate that the plugin no
longer will refer to that memory again.


.. note::
    These rules do **not** apply to data being passed around *inside* a
    plugin. Plugins are free to manage memory internally however is convenient
    for the plugin. For example, a manual memory language like C++ may choose to
    use RAII internally, and wrap those objects in ref-counted pntOS wrappers
    which destruct the RAII object when the pntOS refcount goes to zero. A
    refcounted language like Python might choose to match its refcounted objects
    to pntOS' refcounters. A garbage collected language may choose to hint a GC
    collect when a large object runs out of pntOS references. The only time
    wrappers into pntOS managed objects are needed is when memory is passing a
    pntOS API boundary (i.e. being passed to another plugin).

Recalling our example from the previous section, plugin A might implement
:code:`more_work` like this:

.. code-block:: c
    :linenos:

    void more_work(PntosString* s) {
        // Do something with `s`
        ...
        // Tell original allocator we are done with this reference
        s->memory->dec_ref(s);
    }

:code:`more_work` does not save a copy of the pointer :code:`s`, therefore the function
decrements the reference count to the memory of :code:`s`.

Alternatively, if :code:`more_work` actually wanted to save off a copy of the pointer
:code:`s`, then the following would be valid:

.. code-block:: c
    :linenos:

    PntosString* my_s;
    void more_work(PntosString* s) {
        // Save off `s` for usage outside of the function call. This is
        // valid because PntosString is a pntOS managed type, so `more_work`
        // has ownership of a reference to it indefinitely
        my_s = s;
    }
    void later_on() {
        // At some future point, we release our reference to `s` when we no
        // longer need it.
        my_s->memory->dec_ref(my_s)
        my_s = NULL;
    }

:code:`more_work` does not decrement the reference count to the memory of :code:`s`
until :code:`later_on` when it is done with the pointer copy, :code:`my_s`.

Note that the memory management burden applies to *all* managed memory acquired
across a pntOS API boundary from another plugin. This includes return values. In
our example from the previous section we may note that in :code:`plugin_b_main`,
plugin B received a :code:`PntosFoo` from plugin A, and :code:`PntosFoo` is a
managed type. Thus, we can fix up our implementation of :code:`plugin_b_main` to
decrement the reference to :code:`PntosFoo` when we are done with it:

.. code-block:: c
    :linenos:

    // Code running in plugin B
    void plugin_b_main() {
        // Object acquired by a call into another plugin's function pointer,
        // Thus the returned `Pntos` object is managed by us. We have one implicit
        // reference to `foo` which we must release when we are done with it
        PntosFoo * foo = controller->get_foo(controller);

        foo->do_work(5);
        foo->more_work(pntos_string_new("hi"));
        foo->other_work("hi");
        foo->stateful_work(foo, pntos_string_new("hi"));

        // Let the original allocator plugin know we will no longer use foo
        foo->memory->dec_ref(foo);
    }

Because the pntOS managed types are actually using a full-fledged reference
counting system, the plugin may also call the paired
:member:`~PntosManagedMemory::inc_ref` function to obtain another reference
to the :code:`foo` memory. This is useful when plugins want to do a zero-copy
passing of memory to another plugin, and they need to give that plugin its own
reference. Refer to the API documentation for :struct:`PntosManagedMemory` for
more information.


.. note::
    Recursive managed memory is always managed by the outer-most memory manager.
    When the outer-most memory manager is freeing memory, it must call
    :code:`dec_ref` on any nested types with a PntosManagedMemory field.
    For example, if you were to receive a pointer to the following struct:

    .. code-block:: c

        struct PntosBar {
            PntosManagedMemory* memory;
            PntosString* string;
        }

        void do_work(struct PntosBar* bar) {
            /* Do stuff with bar, decrement reference count when done */
            bar->memory->dec_ref(bar);
        }

    According to the core memory management rules, when you are done with :code:`do_work` you might
    be tempted to decrement your local reference to :code:`PntosBar` itself as well as the
    :code:`string` field, since both of them are pntOS managed types. However, this is
    **incorrect**. Because :code:`do_work` was passed a managed type :code:`PntosBar`, the first
    field of that instance (i.e. :code:`bar->memory`) is *responsible for managing all of the memory
    inside of that instance*. Thus, the only burden on the :code:`do_work` method is to call
    :code:`bar->memory->dec_ref`, and it is up to the :code:`PntosBar` to handle all of the internal
    memory inside of :code:`PntosBar`, including calling :code:`string->memory->dec_ref`. This
    scheme allows flexibility so that plugins can compose memory that are passed in several
    different calls to different plugins and are managed on a timeline known to the plugin internally.

    It is also possible to detach :code:`string` from :code:`bar` and store it, for example if
    :code:`PntosBar` had many other fields and only :code:`string` needed to persist beyond the
    call to :code:`do_work`, for example:

    .. code-block:: c

        struct PntosBar {
            PntosManagedMemory* memory;
            PntosString* string;
        }

        void do_work(struct PntosBar* bar) {
            /* Save off another reference of bar->string */
            bar->string->memory->inc_ref(bar->string);
            PntosString* another_reference = bar->string;

            /* Do stuff with bar, decrement reference count when done */
            bar->memory->dec_ref(bar);

            /* another_reference is still valid after bar is destroyed */
            printf("%s\n", another_reference->data);
            /* Decrement reference count when done */
            another_reference->memory->dec_ref(another_reference);
        }
