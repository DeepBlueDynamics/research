controlled: no

distribution: A

[TOC]

# ASPN 2023 Guiding Principles
- ASPN uses the [International System of Units (SI)](https://www.nist.gov/pml/weights-and-measures/metric-si/si-units) for all information unless there is an overwhelming reason to do otherwise.
- The number of messages should be minimized to ease creating and parsing messages. This is obviously subjective, since we could write a single message that contains everything. The intent here is preference should be given to combine information when appropriate.
- Sensors are _transmit-only_ from ASPN's perspective. No system requests for information (e.g., ASPN does not support requesting a sensor to send its metadata). There may be other sensor interaction with the system that falls outside ASPN-defined messages.
- ASPN does not define every system message.

# FAQs

## Q: Why does ASPN 2023 use meters?  My current system uses feet.

One goal of ASPN is to specify enough detail that the information contained in the ASPN messages are useable by a navigation filter.  Another goal of ASPN is to create a minimal set of messages to ease creating and parsing messages.

With these in mind, units of measure must be specified, and ASPN uses the [International System of Units (SI)](https://www.nist.gov/pml/weights-and-measures/metric-si/si-units) for all information unless there is an overwhelming reason to do otherwise.

An alternate approach is to use only Imperial units. This would have the similar effect as choosing SI units, but SI units are more prevalent.

Another approach is to include multiple versions of the same measurement with various units. The combinatorial effects of this may produce many, many messages to parse.  For example, this may not just be SI versus Imperial, but there are communities that would desire a mix of SI and Imperial.

## Q: Why is geodetic position expressed in latitude, longitude, and altitude (lla) instead of ECEF?

One goal of ASPN is to create a minimal set of messages to ease creating and parsing messages. Thus, 3-D geodetic position as well as 2-D (e.g., latitude and longitude with no altitude information) and 1-D (e.g., longitude only) geodetic position all share the same message by allowing partial information through optional fields. The 2-D and 1-D representations are much more intuitive using lla rather than ECEF, so lla was chosen for all geodetic position representations.

## Q: What is an ASPN system?

ASPN avoids labeling any system as an "ASPN system".  ASPN defines the data model for navigation-related information through `.yaml`s; these definitions are _necessary_ but not _sufficient_ for a system.  Therefore, ASPN has two **immediate** shortcomings when attempting to label a system an "ASPN system":

1. Implementation: The `.yaml`s must be converted to implementation-specific files before a system can use the data model.  Additional information goes into that conversion that may be system-specific.
2. Incompleteness: ASPN only defines the navigation-related information.  There are additional, and perhaps substantial, messages that are also needed for a system.

Rather than labeling a system as an "ASPN System", it may be more appropriate to say a system "uses the ASPN data model".

## Q: What is a "breaking change" within the ASPN 2023 ICD?

ASPN 2023 uses `.yaml` to define the data model, because they are both machine readable and human readable.  The `.yaml`s themselves are not the data model end product; rather, they are converted into the end user's desired product.  After the `.yaml`s are put through a conversion tool, example end products include

- Documentation (.pdf, .html)
- Cameo (.xsd)
- C/C++ headers
- Various transport IDLs (LCM, DDS, Victory)

As such, describing "breaking changes" is a function of the end product rather than the `.yaml`.  For example, if you want to know what will break your LCM implementation of the ASPN 2023 ICD, _it depends_ on how that LCM implementation is generated.

The summary is
- "What is a breaking change?" is an ill-posed question for the ASPN 2023 data model, and
- When asking "What is a breaking change?" for a specific ASPN 2023 implementation, the answer is, "it depends on how that implementation is generated from the ASPN 2023 data model".

For additional information, see `extensibility.md`.

## Q: Some of the experimental message definitions don't follow ASPN 2023 rules.  Is that allowed?

Yes, modifications made in experimental branches are unregulated by ASPN.  Requiring experimental messages to follow ASPN 2023 may prevent a user from experimenting with something that violates, yet improves, ASPN 2023.

If experimental messages that do not follow ASPN 2023 breaks your work flow, please choose to ignore those messages.  You may safely ignore all experimental messages and branches.

While the data model modifications are not regulated, there is administrative guidance in `experimental_models.md` to keep the community aligned on how to use experimental branches.
