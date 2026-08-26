Extensibility Rules
===================

pntOS is designed to be extensible without breaking API backwards compatibility
with previous releases within the same major version release. For example, pntOS
utilizes enums with different options, where new approaches may be added to the
enum in the future. To this end, there are a number of rules that pntOS plugins
must adhere to in order to allow their code to function without changes when the
API is extended.

Enums
-----

Enums are often used in pntOS for extensibility. For example, the
:code:`PntosPluginTypes` is an enum of the current set of supported pntOS plugin types.
These enums may be extended in later pntOS revisions, and such additions to
existing enums are not considered breaking changes to pntOS. Therefore, plugins
that dispatch enum values must consider the enum list to be non-exhaustive and
handle the case where the value matches none of the known enum values. Users of
enums in pntOS must not assume anything about the numerical value assigned to a
pntOS enum entry, or the number of entries contained in the enum. In general,
pntOS is free to add entries to any enum in the pntOS APIs and these additions
do not increment the :code:`PNTOS_PLUGIN_API_VERSION` or constitute a breaking change
of the pntOS API.

Memory allocation
-----------------

pntOS reserves the right to add new fields to core structures in future releases
which add optional additional functionality. These additional fields will change
the size of the structure, adding more bytes onto the end of the structure.
Therefore, plugins which allocate memory to store pntOS structures must:

1. Dynamically find the :code:`sizeof` the struct from the header file.

2. Allocate all bytes in the struct to be zero (e.g. by using :code:`calloc`),
   such that new bytes added to the end of the struct definition are zero by
   default.

3. Never assume offsets into the structures are constant, as padding and
   additional features may change these offsets.

API Stability
-------------

pntOS uses semantic versioning, and avoids API breaking changes within a major
release. However, some features of pntOS are still experimental and therefore
are not guaranteed to be stable even within a major release. These features are
marked :code:`UNSTABLE` in their docstrings. Any code which is marked unstable
may change at any time. Changes to experimental API features are not considered
breaking changes. Many enum entries which are marked unstable are for features
or advanced implementations that are not yet complete, and are instead reserved
for future use.