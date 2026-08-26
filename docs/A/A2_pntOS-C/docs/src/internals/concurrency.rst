Concurrency
===========

pntOS is designed to allow for concurrent operation of different plugins.
Indeed, different plugins are free to use their own concurrency primitives
internally. Because each plugin may be using its own set of threads, processes,
coroutines, or other primitives internally, some rules must be established on
how these plugins interact with each other.

Definitions
###########


Fundamentally, pntOS plugins interact with resources handed to them by the
controller (see the pntOS :ref:`Introduction` for more information on the overall
pntOS architecture). For example, when a non-|Controller plugin| is first loaded into pntOS,
the :member:`~PntosCommonPlugin::init_plugin` call provides a pointer to a
|Mediator| struct, which may be used by that plugin to request information from
the system. Similarly, the |Orchestration plugin| is handed a set of plugins in
the :member:`~PntosOrchestrationPlugin::init_orchestration_plugin` call, which
the |Orchestration plugin| is free to use in the future to access system
resources. A plugin using a function on the |Mediator| it was given and the
|Orchestration plugin| using a plugin from the list of plugins it was given are
both examples of plugins using system resources given to them by the system.

Conversely, when the |Controller plugin| starts up it is handed a set of raw
plugins collected by the loader. The |Controller plugin| wants to use these
plugins, but it first must ensure that it adheres to the rules and expectations
of these plugins. For example, before the |Controller plugin| may start using
functionality on a |Transport plugin|, it is required to call
:member:`~PntosCommonPlugin::init_plugin` on that |Transport plugin|. When the
|Controller plugin| accesses a raw plugin or a resource returned by a raw
plugin, that constitutes the pntOS system accessing a plugin resource. The above
example of the |Controller plugin| calling :member:`~PntosCommonPlugin::init_plugin` on a
|Transport plugin| is an example of the system accessing a plugin resource.

Thus, we can say that the |Controller plugin| is acting as the "pntOS System" and
managing the concurrency and data access between plugins. We will now consider
both of these use cases individually:

1. What responsibilities do non-|Controller plugin|\ s have in accessing system
   resources
2. What responsibilities does the |Controller plugin| plugin have in accessing plugin resources


Plugin Accessing System Resources
#################################

Plugins may access system resources at any time. For example, they are free to
call functions on the |Mediator| and on a :class:`PntosKeyValueStore` instance. If they
make such accesses *concurrently*, they are subject to the following rules:

1. Concurrent access of each system resource from separate threads owned and
   created by the plugin is allowed.
2. Concurrent access of system resources from separate processes is **forbidden**.
   For example, if a plugin called :code:`fork()`, it cannot access the |Mediator| from
   both processes. Access of system resources is only allowed from the
   originating process that the system resources were given to the plugin in.
3. Concurrent access of system resources **may be processed in any order**. The
   system reserves the right to:

   a. Block on a system resource access request while waiting for another call to complete.
   b. Execute system resource access requests in a different order than they
      were made by the plugin.
   c. Utilize each thread that a system resource access request was made on to
      do other work. For example, if a registry key is set using
      :member:`~PntosKeyValueStore::set_str`, the system may in the middle of
      that call process its :member:`~PntosKeyValueStore::request_notify`
      observers, using that thread to invoke callbacks on other plugins.
   d. Utilize any thread-local storage on the thread that a system resource
      access request was made for any purpose.

   One method of accessing system resources is to have a dedicated system
   resource thread which sequences and makes all system resource requests.
   Concurrent access from multiple threads is also possible as long as the above
   rules are observed. Note that the first two rules make any such concurrent
   accesses a race condition.

4. Concurrent access of system resources using other concurrency primitives
   (such as coroutines) is *unspecified* and must be coordinated with a
   participating controller. For example, a controller might share a coroutine
   access pool with other plugins, but only if all plugins opt-in. Plugins must
   support falling back to a non-participation mode, where other concurrency
   primitives are not utilized to make concurrent accesses of system resources.

Controller Accessing Plugin Resources
#####################################

The system may access resources on a plugin or returned by a
plugin (or recursively returned by a resource previously returned by a plugin)
at any time. Such accesses are usually made by the |Controller plugin| accessing
plugin memory or functions, and are subject to the following rules:

1. Access to a plugin resource must be on a *single* thread, and concurrent
   accesses to plugin resources are **forbidden**. Thus, a controller must
   carefully control requests made to plugins by the |Mediator| and other
   inter-plugin communications.
2. Access to plugin resources may be made on any thread available to the system.
3. Plugin resources may be accessed from within any process and are not
   necessarily used within the same process that loaded the plugin, however each
   plugin must only be called from **one** process. For example, the controller
   is free to :code:`fork()` once per plugin and use each plugin in a separate
   process, but it must not call the *same* plugin from within both the original
   process *and* the :code:`fork()`\ ed process.
4. Concurrent access of plugin resources using other concurrency primitives
   (such as coroutines) is *unspecified* and must be coordinated with a
   participating plugin. For example, a controller might share a coroutine
   access pool with other plugins, but only if all plugins opt-in. Plugins must
   support falling back to a non-participation mode, where other concurrency
   primitives are not utilized to make concurrent accesses of plugin resources.

Any of the above rules may be overridden by an API specification. For example,
the registry allows for :class:`PntosKeyValueStore` accesses to be made
concurrently, and the :class:`PntosUiPlugin` requires the main thread to be used
under certain conditions.

Simultaneous Controller and Plugin Accesses
###########################################

In the last two sections, we discussed the rules for the |Controller plugin|
accessing plugin resources and the plugin accessing system resources. However,
what if these two things happen simultaneously? That is, a |Controller plugin|
accesses a plugin resource while at the same time the plugin accesses a system
resource?

In general, such behavior is *allowed*, meaning that:

1. Plugins must expect that one of their functions may be accessed even if they
   are currently requesting something from the system. The plugin must **not**
   block on the system accessing one of its functions until its current
   request to the system is complete.
2. The |Controller plugin| must expect the plugin to request something from the
   system even if the controller is currently waiting for a call it has made to
   the plugin to complete. The |Controller plugin| must **not** block on the
   plugin request until after the |Controller plugin|'s request to the plugin is
   complete.

Taken in whole, this allows for calls one direction to initialize a call the other
direction. For example, if the |Controller plugin| asks plugin A to perform a task,
plugin A may call back into the mediator while it is trying to perform that
task. An example use case is that plugin A may need to get a config value from
the registry to complete its task. The mediator must dispatch the request for a
registry config immediately, as waiting for plugin A's task to complete before
processing the new config variable would result in a deadlock. In particular,
plugin A would be waiting for its config variable to complete the task and the
|Controller plugin| would be waiting for the task to complete before giving A
its config variable.

Callback Triggering and Call Loops
##################################

Because pntOS is a general framework without specific workflow requirements in
data routing between plugins, care must be taken to avoid responsibility loops.
For example, suppose that in the implementation of a |Mediator|, the system uses
a |Registry Plugin| to implement the :code:`mediator->registry` functionality.
Further suppose that in the implementation of a |Registry Plugin|, the
:member:`~PntosKeyValueStore::set_str` call simply called back into the
|Mediator|'s :code:`mediator->registry`. We would now be in an infinite loop:
the |Mediator| uses the |Registry plugin| and the |Registry plugin| uses the
|Mediator| function, continuing to call each other until a stack overflow
occurs.

While this example is simple and avoidable, there are many possible races,
deadlocks, and starvation conditions that can arise in the implementation of the
mediator if plugins are allowed to call any mediator resources at any time.
Consider for example the following call chain that might occur when the
|Controller plugin| requests something from plugin A:

    Controller -> Plugin A -> Mediator -> Plugin B -> Mediator -> Plugin A

Plugin A calling the mediator for Plugin B's functionality is reasonable, and
Plugin B calling the mediator for Plugin A's functionality is reasonable, but in
totality we would have a broken system, as by the concurrency rules in the
previous sections the system may not call into Plugin A twice.

The solution to this issue is isolation of responsibilities. In general, the
following rules must be followed:

1. Plugins must not call back into functions which they are responsible for
   implementing. For example, a |Registry plugin| may not access the |Mediator|'s
   :code:`mediator->registry`. Similarly, the |Orchestration plugin| must not
   call into :code:`request_solutions`, and the |Transport plugin| must not call
   into :member:`~PntosMediator::broadcast_aspn_message`.
2. Callbacks must not use |Mediator| resources. For example, when the callback
   function to :member:`~PntosKeyValueStore::request_notify` is invoked, the
   callback may not access the |Mediator| inside the callback.

Mutability of Received Resources
################################

In general, resources delivered by a plugin to the system or by the system to a
plugin may be shared by multiple plugins, including the original plugin that
produced it retaining a copy. pntOS utilizes a reference counting mechanism to
capture how many references to a resource are retained by any particular
plugin.

By default, all plugins must assume that resources are being shared. Thus if a
|PntosString| is returned by a function call to another plugin, the receiver
plugin must assume that the :member:`~PntosString::data` memory is being
utilized by multiple plugins and **cannot be modified or mutated**. However, for
memory which is managed by a |PntosManagedMemory|, the receiver plugin may
attempt to call the :member:`PntosManagedMemory::num_refs` member of
|PntosManagedMemory|. If the function pointer is non-NULL and the returned value
is 1, then there exists no other reference to the managed memory and therefore
the receiver plugin is free to mutate the memory contained in the |PntosString|.

This leads us to the following set of rules all plugins must follow:

1. All memory passed to another plugin which the originating plugin does not
   retain a reference to must be **mutable**. If the originating plugin wants to
   use a C string literal in a string field, then it must either copy it first
   to mutable memory or retain a reference such that no other plugin will ever
   see a 1 return from :member:`PntosManagedMemory::num_refs`.
2. Data in a :code:`Pntos*` struct must not be mutated unless
   :member:`PntosManagedMemory::num_refs` is 1.
3. If memory is returned with nested structs which are managed by nested
   |PntosManagedMemory| managers, **mutation of the nested memory is never
   allowed**. This is because:

   a. Each |PntosManagedMemory| retains its own reference count and therefore
      the outer and inner |PntosManagedMemory| both constitute a potential
      reference held by another plugin
   b. There is no way to atomically test :member:`PntosManagedMemory::num_refs`
      for both the outer and inner |PntosManagedMemory|, and sequential testing
      would constitute a TOCTOU vulnerability.

PIP and Controller
##################

The |PIP| and |Controller plugin| work closely to handle system resources
concurrently in pntOS. Because of this close relationship, there is no way to
prescriptively lay out a set of rules the |PIP| and |Controller plugin| must
adhere to in order to avoid races, deadlocks, and other undesirable effects.
Instead, for concurrent implementations, the |PIP| must be designed to work
specifically with a chosen |Controller plugin|, and document the way that it
coordinates concurrency with the |Controller plugin|.


.. |Mediator| replace:: :class:`Mediator <PntosMediator>`
.. |Orchestration plugin| replace:: :class:`Orchestration plugin <PntosOrchestrationPlugin>`
.. |PIP| replace:: :class:`PIP<PntosPlatformIntegrationPlugin>`
.. |Transport plugin| replace:: :class:`Transport plugin <PntosTransportPlugin>`
.. |Registry plugin| replace:: :class:`Registry plugin <PntosRegistry>`
.. |PntosString| replace:: :class:`PntosString`
.. |PntosManagedMemory| replace:: :class:`PntosManagedMemory`
.. |Controller plugin| replace:: :class:`Controller plugin <PntosControllerPlugin>`
