controlled: no

distribution: A

# Experimental Data Models

An experimental data model includes definitions that are a work in progress, proposed for future incorporation into ASPN, or are in some other immature state. These experimental data models are developed in experimental branches and have a few marking requirements for clarity.

## Overview

Experimental branches may be created, modified, or deleted and will have no direct effect on ASPN 2023.  The guidance below aides in the markings of an experimental branch, but never lose focus on the point of an experimental branch: Experimental branches are published as exploratory versions of ASPN.

Experimental branches are not _change proposals_ to ASPN.  It is good practice to implement changes in an experimental branch for use and feedback, but to impact ASPN 2023, a change proposal must be submitted.

## Construction

### Branches

Each experimental branch name shall begin with `experimental/`, for example, `experimental/point_cloud` or `experimental/ArmyIntegrity`. Any user with sufficient gitlab permissions may create experimental branches; there is no approval needed.

Typically, an experimental branch will contain most of the ASPN 2023 data model definitions with one or more experimental modifications.  These experimental modifications may result in deleted files, additional files, and/or modified files compared to ASPN 2023.

| Modification (Action taken in going from ASPN 2023 to the experimental branch) | What to do in the experimental branch |
| --- | --- |
| Deleted file | Do not include the file in the experimental branch | 
| Added file | Include the file in the experimental branch |
| Modified file | (a) Include the modified version of the file in the experimental branch (and follow the rules below), and (b) Do not include the original, unmodified version of the file in the experimental branch |

### Experimental File Guidance

Each file in the experimental folder that has been _added_ or _modified_ shall follow the following guidance:

1. **Filename**  
   
   Name the `.yaml` file with the prefix `EXPERIMENTAL_` regardless if the file is added or modified.  For example, if you add a file, start the name with `EXPERIMENTAL_`.  If you modify `type_timestamp.yaml` in ASPN 2023, the modified file in your experimental branch shall be named `EXPERIMENTAL_type_timestamp.yaml`.  

   This prefix will clearly identify the experimental files when files are distributed outside the `git` construct, e.g., via a `.zip` file. 

   This prefix will have no effect on other aspects of ASPN, since ASPN 2023 inside the `git` construct does _not_ rely on the filename (i.e., no information in the filename). For example, it is anticipated that the aspn-icd tooling will ignore the filename.

2. **Preample Comment**

   Place experimental notes here that you do not want to appear a future version of ASPN if this experimental feature is incorporated. For example, the preamble comment description will _not_ survive tooling.  Descriptions that you wish to survive tooling should be placed elsewhere in the data model.

   Include this preamble in the `.yaml`:

```
# ------------------
# EXPERIMENTAL
# ------------------
#
# DESCRIPTION:
# _Add description of the experimental status here._
```

3. Use of the `name:` Key

   Every data model definition has a `name:` key.  Typically, the `name:` matches the `.yaml` filename for convenience; however, for experimental files, do not follow this pattern.  Do not include `EXPERIMENTAL` in the `name:` (even though the filename begins with `EXPERIMENTAL`).  Use the `name:` that you would like a future version of ASPN to use if the experimental branch was adopted.

| Modification | What to use for `name:` |
|---|---|
| You **add** a file to your experimental branch that was not present in ASPN 2023 | Use an appropriate `name:` that you propose for a future version of ASPN should use.  Typically, this would be the file's filename without the `EXPERIMENTAL_` prefix. |
| You **modify** a file in your experimental branch that was already in ASPN 2023 |  Do not modify the `name:`.  For example, if you modify `type_timestamp.yaml` from ASPN 2023, the modified file in your experimental branch shall continue to use `name: type_timestamp`.|

4. Use of the `experimental:` Key

   Every data model definition has an `experimental:` key.  Typically, this is set to `false`. For experimental data models, this should be set to `true`, i.e., use

```
experimental: true
```

### Summary
- Experimental branches shall begin with `experimental/`.
- Each experimental data model `.yaml` shall adhere to guidance on (1) filename, (2) preamble, (3) `name:` key, and (4) `experimental:` key.
