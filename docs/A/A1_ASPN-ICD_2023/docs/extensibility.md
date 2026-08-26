controlled: no

distribution: A

# Extensibility Rules

The ASPN ICD uses `.yaml` to define the data model, because they are both machine readable and human readable.  The `.yaml`s themselves are not the data model end product; rather, they are converted into the end user's desired product.  After the `.yaml`s are put through a conversion tool, example end products include

- Documentation (.pdf, .html)
- Cameo (.xsd)
- C/C++ headers
- Various transport IDLs (LCM, DDS, Victory)

As such, describing extensibility really is a function of the end product rather than the `.yaml`.  The following sections describe how ASPN will do versioning and extensibility.

## Versioning

ASPN 2023 does not follow semantic versioning. Previously, ASPN's major version increments represent a shift in approach.  For example, from ASPN 1.x to ASPN 2.x, there was a shift from matlab and MS Word documents to `.yaml`s.  From ASPN 2.x to ASPN 3.x, there was a shift from implementation-specific definitions that required human to human coordination for compatibility to well-defined `.yaml`s that provided enough specificity that anyone could use ASPN 3.x.

Since ASPN 2023 does not follow semantic versioning, ASPN 2023 adopted the naming convention that includes the release year rather than a `major version.minor version`. Additional mid-year releases are expected to append a letter, e.g., ASPN 2023a.

## Breaking Changes

Classifying changes in ASPN as breaking or non-breaking is problematic, since implementations use products _derived from_ ASPN--not ASPN itself. In this context, a breaking change causes the application to fail after recompile, whereas for a non-breaking change, the application will function after recompile. Whether or not an end product is breaking or non-breaking depends upon the ASPN conversion tool and the intended application. 

> **EXAMPLE:**
> - An ASPN change (i.e, a modification to an ASPN `.yaml`) that renames a field may be used to generate an LCM IDL that is non-breaking.
> - This same change (renaming a field in a `yaml`) may break some implementations of a DDS IDL. 
> - To compound matter further, it may be possible for tooling to account for some changes in the data model to avoid breaking the DDS IDL.

There are two main methods that are used to help tooling products to avoid breaking changes as a result of changing to the ASPN data model: enums and experimental branches.

## Enums

The first method for extending ASPN to more easily implement `.yaml` changes is through the use of enumerated lists, or an `enum`.  The `enum` construct is as follows:

```
- name:
  enum:
  - entry
  - entry
  length:
  description:
```
where there may be any number of entries up to the _length_ of the `enum`.  The ASPN `yaml` definitions make use of `enum`s to be extensible without breaking many of the end products by specifying entries for an enum while allowing expansion up to the length of the enum.  It is important to re-iterate the length of an enum is both the _maximum_ number of entries ASPN will define and the _minimum_ number of entries any implementation of ASPN must support.  As such, new entries may be added to the `enum` in the future and both the data model and the implementation will allow those additional entries.  Obviously, _allowing_ additional entries does not guarantee _support_ for the new entries.

In order to gain extensibility through `enum`s, the following rules are declared:

1. All `enum`s shall be implemented using an `enum` that is at _least_ the enum length specified.  **This enables future growth.**  For example, do NOT implement an `enum` that currently has two entries with a single bit.  If that were done, ASPN could not be extended in a future version to add a third entry.

2. All systems must be implemented to allow the full range `enum` values specified in the enum length.  For example, consider a message with an `enum` that currently has two entries with an enum `length: 32`. Tooling shall implement a system that accepts values from 1 through 32.  In this way, ASPN may be extended in a future version to add a third entry.

> **EXAMPLE:**  Consider a system using ASPN 2023 and LCM.  Suppose an image sensor `.yaml` with an `enum` indicating the image type (`image_type`), such as Bitmap (BMP) or Portable Network Graphics (PNG), is changed from ASPN 2023 to ASPN 2024 to include an additional image type of JPEG2023 (totally hypothetical example).  Suppose the estimation filter was using ASPN 2023 and continues to use ASPN 2023, but only supports `image_type=BMP`. Suppose the sensor was upgraded to ASPN 2024 and generates an ASPN 2024 LCM message with `image_type=BMP`, which was included in ASPN 2023. The filter would continue to understand this measurement and function with no issues. If the sensor generates an ASPN 2024 LCM message with `image_type=JPEG2023`, the filter would not know how to process this measurement. This scenario is no different than if the sensor sent a message with `image_type=PNG`, which is not supported by the filter.  In other words, `enum` updates are more a matter of what is supported by a system rather than "breaking" a system.

## Experimental Branches

The second method for extending ASPN to more easily implement `.yaml` changes is by including features in an experimental branch within the ASPN repository. `.yaml`s that are immature and need further community usage prior to adoption may be included in an ASPN 2023 experimental branch with the intent for consideration into a future release of ASPN. This also allows users to identify and resolve potential breaking points by the tools being developed.  

While the data model modifications are not regulated, there is administrative guidance in `experimental_models.md` to keep the community aligned on how to use experimental branches.