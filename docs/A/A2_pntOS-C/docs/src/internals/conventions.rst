Conventions
===========

This page documents various conventions within pntOS. :ref:`Types` documents conventions which limit
the ways pntOS uses a type so the user can understand what it represents without any additional
information. :ref:`Inheritance` describes the conventions pntOS uses to implement inheritance as a
pattern in C.

Types
-----

For clarity and ease-of-use, pntOS uses the following conventions in its API:

* ``char*`` is a C-string, meaning that it is terminated by a NULL character, which can be
  used to determine its length.
* ``unsigned char*`` is not a C-string. NULL characters can exist throughout the array.
  Instead, a separate length field exists to provide the length of the array. This type indicates an
  opaque data stream.
* ``Foo**`` (a pointer to a pointer to the arbitrary type ``Foo``) represents an array of pointers
  to ``Foo``. The one exception to this rule is ``char**``, which instead represents an array of
  null-terminated C-strings. In all cases a separate length field exists to provide the length of
  the array.
* ``void*`` denotes an unknown type that needs to be decoded first before anything is done with it.
  "decoded" simply means to cast to the known type. For example, see the ``receiver`` parameter in
  the callback function pointer in :member:`PntosKeyValueStore::request_notify`.

Inheritance
-----------

pntOS implements an inheritance scheme via the following conventions:

* Usually, the base class name will start with the name ``PntosCommmon`` (e.g.
  :struct:`PntosCommonInertial`).
* Every polymorphic base class contains an enum field (e.g.
  :member:`PntosCommonInertial::inertial_type`). The value of this enum field indicates which child
  class the base object can be downcast to. The child class name will always be the ``PascalCase``
  equivalent of the ``UPPER_SNAKE_CASE`` enum value. For example, if the
  :member:`PntosCommonInertial::inertial_type` field is equal to
  :enumerator:`PntosInertialType::PNTOS_STANDARD_INERTIAL_MECHANIZATION` then the object can be cast to
  :struct:`PntosStandardInertialMechanization`.
* Every child class will have the base class object as its first field (e.g.
  :member:`PntosStandardInertialMechanization::common`).

.. note::
    This inheritance pattern is made possible because the C standard states:

        *A pointer to a structure object, suitably cast, points to its initial member*
