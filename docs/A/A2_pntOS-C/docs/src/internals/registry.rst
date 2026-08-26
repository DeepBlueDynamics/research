pntOS Registry Overview
=======================

One goal of pntOS is to enable extensible and flexible communication between
plugins. For example, a particular implementation of a state modeling plugin for a
camera may want to have a configurable setting for focal length. In addition, a
separate GUI plugin may want to display the value being used for the camera's
focal length, allow the user to modify the focal length, and communicate that
change back to the state modeling plugin.

One simple approach to solving this problem would be to enumerate all the
possible configuration values that any plugin might need, and encode them into a
set of statically typed structures as part of the pntOS API. However, this
quickly becomes infeasible as developers add new plugin implementations to the
system, as each one will have specific nuanced needs for configuration and
shared data between other plugins.

pntOS instead solves this problem by introducing a data registry which is
available to all plugins to store values, retrieve values, and listen for
changes to values by other plugins. Any pntOS plugin has access to the registry
by accessing the :struct:`PntosRegistry` pointer on the :struct:`PntosMediator`
struct that was passed to it during initialization.

By creating a shared plugin that can store, retrieve, and provide a way to listen
for changes, the pntOS :struct:`PntosRegistry` supports the following use cases.

#. Loading configuration data at startup
#. Communicating and recording runtime information during pntOS operation
#. An alternative method for
   inter-plugin-communication for scenarios the current API does not support


Keys, Values, and Groups
------------------------

The :struct:`PntosRegistry` (or pointer to one) is a structure which a plugin
may use to store or retrieve values from the Registry. The Registry is shared
with all other plugins. When a plugin wants to store a value in the registry, it
must follow the API and first access the group, then set the value associated
with the key within that group. For example, a plugin called MyPlugin might
want to store the number of messages it has received so far (for example, 2)
into a group ``my_plugin/config`` and key ``num_messages_received``.

The plugin would operate on the :struct:`PntosRegistry` pointer it has available
on the :struct:`PntosMediator` to start a batch for the group
``my_plugin/config``, and use the :member:`~PntosKeyValueStore::set_int`
function on the :struct:`PntosKeyValueStore` it returned with
``num_messages_received`` as the key, and ``2`` as the value.

Example:

.. code-block:: c
    :linenos:

    PntosRegistry* registry = <access registry pointer through mediator>;
    PntosKeyValueStore* kv_store = registry->batch_start(registry,"my_plugin/config");
    kv_store->set_int(kv_store,"num_messages_received",2);
    kv_store->batch_end(kv_store);


While conceptually a :struct:`PntosKeyValueStore` is similar to a traditional
key-value (k-v) store, one difference is the addition of a ``group`` string. Whereas
a traditional k-v store has a single key that identifies values, a
:struct:`PntosKeyValueStore` has a pair of strings (group, key). The reason for
this is because the pntOS registry could be used for passing large amounts
of data between various plugins at high data rates, and a monolithic
implementation of a single k-v store for all of those transactions would pose a
bottleneck risk to overall system performance. By splitting the lookup key from
the group, the registry can be implemented to more efficiently segment data
access by group, isolating different physical data stores by group. This
approach allows plugins to better optimize performance, as efficient registry
implementations can isolate registry access by group. Thus a plugin
that needs to communicate a large volume of data at high data rates might select
an isolated group for those keys.

Concurrency Summary
-------------------

The behavior and structure for accessing groups, the associated concurrency
rules, and the resulting behavior should be shared by all
:struct:`PntosRegistryPlugin` plugins. A detailed description of the concurrency
rules and requirements for pntOS can be found in the :ref:`Concurrency` section of the
documentation.

Below is a summary of concurrency related behaviors that impact registry design
and usage (assuming a threaded model).

* As stated in the API, a :struct:`PntosKeyValueStore` is accessed via a
  :member:`~PntosRegistry::batch_start` call on a :struct:`PntosRegistry`
  with a "group" argument

* The :struct:`PntosKeyValueStore` returned
  from :member:`~PntosRegistry::batch_start` is safe to access from a single
  thread

* :struct:`PntosKeyValueStore`\ s returned from different
  :member:`~PntosRegistry::batch_start` calls with different groups can be
  accessed by different threads concurrently

Example, a :member:`~PntosRegistry::batch_start` call with "group1" and a
:member:`~PntosRegistry::batch_start` call with "group2" could have one thread
accessing the "group1" :struct:`PntosKeyValueStore` and one thread accessing the
"group2" :struct:`PntosKeyValueStore`.

Counter example: the "group1" :struct:`PntosKeyValueStore` can not be accessed
by two threads concurrently.

Raw Operations
--------------

While one goal of the :struct:`PntosKeyValueStore` is to provide an efficient mechanism for storing
values of a specific type which can be retrieved exactly as stored, another goal is to permit direct
interaction with the :struct:`PntosRegistry`\'s data representation specified in
:member:`~PntosKeyValueStore::data_format`.  This is the purpose of
:member:`~PntosKeyValueStore::set_raw` and :member:`~PntosKeyValueStore::get_raw`.  It may be noted
that these resemble :member:`~PntosKeyValueStore::get_str` and
:member:`~PntosKeyValueStore::set_str`.  While :code:`set_str` is guaranteed to store a string to
the registry that one can get back precisely with :code:`get_str`, :code:`set_raw` differs in that
it does implementation-specific (following :member:`~PntosKeyValueStore::data_format`) maintenance
to the group, which could modify anything in the group in an arbitrary way.  Similarly,
:code:`get_raw` can return the value of a key or an entire group, formatted to conform to the data
format.  In an effort to support any data format and to avoid requiring the user to escape the data,
:code:`set_raw` accepts a length which permits the use of :code:`\0` throughout its parameter
:code:`bytes`.  :code:`get_raw` also returns a length in the returned :struct:`PntosByteArray`.

.. note::
   While the user of :code:`set_raw` and :code:`get_raw` is required to interact with the data
   format, the implementation of the registry is free to use whatever backing storage mechanism
   makes sense to the implementation.

Examples
^^^^^^^^

For instance, if :member:`~PntosKeyValueStore::data_format` is set to
:member:`~PntosKeyValueStoreDataFormat::PNTOS_KV_STORE_INI`, this would declare the data format in
use is the INI file format.

.. code-block:: c
    :linenos:

    PntosKeyValueStore* store = registry->batch_start(registry, "my_group");
    char* my_double_array = "1.0;2.3;4.1";
    store->set_raw(store, "my_key", my_double_array, strlen(my_double_array));

.. note::
   The implementation of the registry may allow for the retrieval of the key set with
   :code:`set_raw` by other functions, such as :member:`~PntosKeyValueStore::get_double_array`.

An example of the capability of :code:`set_raw` to set an entire group is shown here:

.. code-block:: c
    :linenos:

    PntosKeyValueStore* store = registry->batch_start(registry, "my_group");
    char* my_group = "A=1.0;2.3;4.1\nB=my string\n";
    store->set_raw(store, NULL, my_group, strlen(my_group));
