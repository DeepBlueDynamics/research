# pntOS-C

This project contains the C API of pntOS and associated documentation.

The C API supports the meson build system by default and can be used downstream by adding a
`pntos.wrap` file to your `subprojects/` directory. It provides a `pntos_api_dep` variable you can
add as a dependency object to include the headers.
