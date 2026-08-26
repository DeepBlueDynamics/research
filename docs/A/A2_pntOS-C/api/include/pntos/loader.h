#pragma once

#include <pntos/annotations.h>
#include <pntos/stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

PNTOS_ASSUME_NONNULL_BEGIN

/**
 * The current API version for the plugin declarations in this header. Any time a breaking change is
 * made to the loader API, this number will be incremented before the next release. Shared libraries
 * wanting to be loaded into pntOS will provide a `PntosPluginsDescription`, the first field of
 * which contains the loader API version the shared library is aware of. If a shared library loader
 * version doesn't match the version the loader was compiled with, the loader will have the option
 * of either rejecting the shared library or falling into a compatibility mode.
 *
 * This version macro only applies to released versions of pntOS.
 */
#define PNTOS_LOADER_API_VERSION 2


/* Expand a token to be a quoted string */
#define PNTOS_STR_EXPAND(tok) #tok

/**
 * A list and description of a set of plugins to be loaded into pntOS. This structure is used in two
 * ways:
 *
 * - The loader, when searching for pntOS plugins to load into the runtime, will search for
 *        `PntosPluginsDescription` definitions. The way it does this depends on the mode of
 *        operation (see below).
 *
 * - The controller will receive a `PntosPluginsDescription`, describing the collection of plugins
 *        that were found by the loader. The controller is then free to use or not use any plugin
 *        listed in the structure as needed.
 *
 * When used on an operating system supporting shared libraries, pntOS plugins are usually bundled
 * into a shared library which are loaded dynamically by the pntOS loader. Each shared library
 * containing pntOS plugins should define a `PntosPluginsDescription` at the top level (the name of
 * this symbol should be `PNTOS_PLUGIN_MAGIC_SYMBOL`). The pntOS loader will find this struct in the
 * shared library, parse its contents, and then load the plugins described by it into the runtime.
 *
 * When used in a non-hosted environment (i.e. where `dlopen()` is not available) all the plugins
 * statically linked into the executable should be listed in a `PntosPluginsDescription` and passed
 * into the controller.
 *
 */
typedef struct PntosPluginsDescription {
	/**
	 * The loader API version of the pntOS loader when this list was defined. When creating this
	 * structure this field should ordinarily be populated with the value from
	 * #PNTOS_LOADER_API_VERSION. For example, if `loader_api_version = 2`, that means that this
	 * structure was written against a `pntos.h` with #PNTOS_LOADER_API_VERSION defined as 2.
	 *
	 * The loader API specifies all of the symbols and types needed to load the plugin list.
	 * Therefore, any breaking changes to the PntosPluginsDescription will cause this number to
	 * increment. If the value of #loader_api_version is different than the code that received this
	 * structure, it may not be safe to use any other fields on `PntosPluginsDescription`.
	 */
	uint32_t loader_api_version;

	/**
	 * The plugin API version that the plugins represented by this structure were built against. For
	 * example, if `plugin_api_version == 6`, that means that all the plugins described by this
	 * structure were written against a `pntos.h` with #PNTOS_PLUGIN_API_VERSION defined as 6. If
	 * the `i`th plugin is a fusion plugin, then the pointer returned by `plugins_loader()[i]` would
	 * point to the structure PntosFusionPlugin as defined by the `pntos.h` with
	 * `PNTOS_PLUGIN_API_VERSION 6`.
	 *
	 * If a #plugin_api_version value is different than the code that received this structure, it
	 * may not be safe to use the return value of #plugins_loader for that particular plugin.
	 */
	uint32_t plugin_api_version;

	/**
	 * A loader function that, when called, returns an array of pointers to plugins. Determining the
	 * actual concrete type of each plugin in the returned array may be done by inspecting the
	 * `plugin_type` field on each returned `PntosPluginArray.plugins`.
	 */
	struct PntosPluginArray* (*plugins_loader)(void);

} PntosPluginsDescription;


#ifndef PNTOS_STATIC_BUILD
/**
 * A string representation of the pntOS magic symbol name for use at runtime.
 */
#	define PNTOS_PLUGIN_MAGIC_SYMBOL_STR PNTOS_STR_EXPAND(PNTOS_PLUGIN_MAGIC_SYMBOL)
#endif

PNTOS_ASSUME_NONNULL_END

#ifdef __cplusplus
}
#endif
