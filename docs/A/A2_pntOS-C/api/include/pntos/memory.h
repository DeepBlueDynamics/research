#pragma once

#include <pntos/annotations.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

PNTOS_ASSUME_NONNULL_BEGIN

/**
 * In pntOS, memory is passed between plugin boundaries quite often, sometimes transferring
 * ownership of memory from one plugin to another. In general it is unsafe to deallocate memory
 * using a different library than the allocator used. In addition, it becomes difficult to reason
 * about who owns the memory and which plugin is responsible for cleaning up the memory to prevent a
 * leak.
 *
 * To solve this problem, all managed memory which may pass between plugins is stapled with
 * `PntosManagedMemory` which contains abstracted memory management functions.
 *
 * The memory will be allocated by a single plugin (the "original allocator"), who will be
 * responsible for cleaning up the memory when no other plugins are using it.
 *
 * When a plugin receives a new struct via a pntOS API call which contains a `PntosManagedMemory`
 * first field, it has a single local reference to the struct. The receiver plugin may then call
 * PntosManagedMemory.inc_ref to inform the original allocator that the receiver needs another local
 * reference to the memory. After a single call to PntosManagedMemory.inc_ref, a receiver plugin
 * would have 2 local references to the memory.
 *
 * When the receiver no longer needs the memory it should call PntosManagedMemory.dec_ref until it
 * holds zero local references to the memory. If no other plugins are holding a reference, the
 * original allocator will see 0 global references and should clean up the memory. Therefore, it
 * is unsafe for a plugin to call any function pointers on the PntosManagedMemory struct after calls
 * to PntosManagedMemory.dec_ref have released all of the plugin's references.
 *
 * When a receiver plugin needs to pass the memory onwards to another plugin, it transfers one of
 * its local references to the plugin. Therefore, if it needs to retain a local reference it should
 * call PntosManagedMemory.inc_ref to request another reference from the original allocator before
 * passing the data along.
 *
 * For example, suppose plugin A passes a `Foo* foo` as a parameter to a function call implemented
 * by plugin B. if `foo`'s first (recursive) field is `PntosManagedMemory*`, then plugin B now knows
 * that it has a memory management burden. In particular, when plugin B no longer needs or
 * references `foo` or any memory contained in `foo`, plugin B should call
 * `foo->memory->dec_ref(foo)` to tell the original allocator (likely plugin A) that plugin B will
 * not be using `foo` anymore.
 *
 * In code this example might look like:
 *
 *     struct Foo {
 *         PntosManagedMemory * memory;
 *         // Other fields...
 *     };
 *
 *     // This function implemented by plugin B, called by plugin A
 *     //
 *     // On the function call, plugin B receives a single implicit reference to foo,
 *     // and so has the innate burden to call foo->memory->dec_ref(foo) when it no
 *     // longer retains a reference to `foo`.
 *     void operate_on_foo(Foo * foo) {
 *         ...
 *         // Tell foo it needs to increment reference counter before passing onto another receiver.
 *         foo->memory->inc_ref(foo);
 *
 *         // The other receiver is responsible for decrementing foo, implicitly
 *         // receives a single reference (the one we just acquired with `inc_ref(foo)`)
 *         forward_to_another(foo);
 *         ...
 *         // Tell foo to release the current reference that plugin B has.
 *         foo->memory->dec_ref(foo);
 *     }
 *
 * A structure that includes a field of type PntosManagedMemory uses that PntosManagedMemory
 * instance to control the lifetime of all its members, including recursive memory referenced by its
 * members, unless those members have their own PntosManagedMemory instances attached. If a receiver
 * plugin decrements its reference count to 0 on such a struct, it should no longer use any memory
 * it obtained from that struct unless that memory has its own PntosManagedMemory attached.
 *
 * This approach is loosely based on memory sharing strategies used in the linux kernel and glib.
 */
typedef struct PntosManagedMemory {
	/**
	 * Increment the reference count for the struct pointed to by the parameter.
	 * `ref_counted_struct` is a pointer to the parent struct which contains the
	 * `PntosManagedMemory` field.
	 */
	void (*inc_ref)(void* ref_counted_struct);
	/**
	 * Decrement the reference count for the struct pointed to by the parameter.
	 * `ref_counted_struct` is a pointer to the parent struct which contains the
	 * `PntosManagedMemory` field.
	 */
	void (*dec_ref)(void* ref_counted_struct);
	/**
	 * @return The number of global references held to \p ref_counted_struct. If the return value of
	 * the function is 1, then the caller has the only reference to \p ref_counted_struct. A
	 * returned value of 0 indicates that this method is unsupported.
	 *
	 * @param ref_counted_struct a pointer to the parent struct which contains the
	 * `PntosManagedMemory` field.
	 */
	size_t (*num_refs)(void* ref_counted_struct);
} PntosManagedMemory;

#ifdef __cplusplus
}
#endif

PNTOS_ASSUME_NONNULL_END
