Design Principles
=================

pntOS was designed to enable maximum flexibility and usage in a wide variety of
scenarios. Among the design goals of pntOS is enabling the development of:

1. Performant solutions with low overhead compared to stovepipe
   implementations.
2. Isolated systems, where components are isolated from each other for
   security/reliability reasons, and communicate through verified pipes.
3. Arbitrary concurrency models, including single-threaded,
   multi-threaded, multi-process, and fully remote systems.
4. Polyglot systems, where vendors have mature and tested code but are
   developing in different programming languages and still want to interoperate
   with each other.
5. Real-time systems, with a particular eye on the ability to reuse components
   of pntOS systems in safety critical applications if they were designed
   carefully.

To achieve these goals, many compromises were selected:

1. **Low-level C API.** The lowest level API that the components of pntOS speak is the
   C89 APIs exposed for plugins into `pntosd`. *Every* plugin into pntOS must
   ultimately implement one of these C89 APIs. The choice of C89 was made to
   enable performance-sensitive implementations to make direct function calls
   between plugins with zero copy overhead. In addition, C89 is the least common
   denominator that is available to virtually all modern programming languages
   via an FFI. For systems that don't need this low-level capability-- such as
   systems which want to isolate all plugins in their own separate processes--
   C89 plugins will be written for pntOS which support e.g. RPC plugins over
   sockets.

2. **Controller-based Architecture with IOC.** In `pntosd`, there exists a central
   controller which receives a set of plugins from the loader and then
   determines everything else. This controller is required to supply a set of
   :struct:`PntosMediator` to each plugin, and the plugin must communicate
   back to the plugin using the function pointers on this struct. This inversion
   of control (IOC) design, while complicated, is designed to allow any
   concurrency model the user wants. For example, if the desired concurrency
   model is to have plugins isolated on separate hardware, the plugins can be
   loaded on separate computers and each plugin can be passed a
   :struct:`PntosMediator` which is actually a shim that opens sockets to
   communicate to the remote plugin resting on another computer. On the other
   hand, if the desired concurrency model is to maximize performance, the plugins
   can be passed a :struct:`PntosMediator` which contain direct pointers to
   the local function exposed by the dispatching plugin, yielding a direct
   function invocation (probably with some amount of locking to prevent data
   races, and a virtual indirection which is unavoidable with dynamic plugin
   architectures). Thus the :struct:`PntosMediator` combined with an
   arbitrary controller implementation is the abstraction that allows any number
   of concurrency models to re-use plugins written for pntOS.

3. **Reference-counted memory.** There are a number of ways to share memory
   through an API boundary in C. The two most common approaches are to 1) force
   the caller to allocate the memory for you, such that the callee can fill out
   preallocated memory instead of deciding on how to allocate or deallocate, and
   2) allow each function callee to allocate internally but give a unified
   interface for users to indicate to each other that they no longer need the
   memory, and that the original allocator should free the memory.

   In the case of pntOS, our desire to support a performant (i.e. zero-copy)
   solution where different plugins are written in different languages makes the
   first approach problematic. In particular, suppose the controller was the
   allocator of all memory, and made an arbitrary choice to use `jemalloc` to
   allocate all memory in `pntosd`. Suppose further that a pntOS plugin writer
   already had a mature codebase written in C++ using `new` to allocate its
   memory, and another plugin writer had a mature codebase written in Java which
   stored its memory on the JVM heap. Because approach 1 mandates that all
   plugins would return results into memory that the controller allocated with
   `jemalloc`, these plugins would necessarily have to copy their results into
   the memory segments provided to them by the controller, which would cause
   performance issues with large allocations such as image data. Attempting to
   return e.g. Java or C++ memory directly to the controller would lead to
   memory corruption when the controller tried to free that memory.

   We therefore use the second approach in pntOS. In particular, all memory that
   is passed through a pntOS API boundary and may be retained by the receiver
   gets the memory stapled with a function pointer that tells the receiver how
   they can indicate to the original allocator that they no longer need the
   memory. In order to allow memory to be passed through multiple API boundaries
   simultaneously, a full reference counting approach is implemented
   (:member:`~PntosManagedMemory::inc_ref` as well as
   :member:`~PntosManagedMemory::dec_ref`). In the case where a plugin doesn't
   care about potential performance issues, it can simply copy the memory it
   received from pntOS into a container on its own heap and then call
   :member:`~PntosManagedMemory::dec_ref` on the pntOS memory it receives,
   allowing for both performant and simple plugins. See :doc:`memory` for more
   information on how to properly cleanup memory when writing a pntOS plugin.
