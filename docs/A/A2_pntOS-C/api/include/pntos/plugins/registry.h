#pragma once

#include <pntos/plugins/common.h>

#ifdef __cplusplus
extern "C" {
#endif

PNTOS_ASSUME_NONNULL_BEGIN

/**
 * A plugin for a global key-value registry. See the `pntOS Registry` page in the `Internals`
 * section for more information on the goal of this plugin.
 */
typedef struct PntosRegistryPlugin {
	PntosCommonPlugin common;
	/**
	 * Create a new registry based on the initial values stored in \p initial_config.  The
	 * format of \p initial_config is implementation specific, and plugins are free to support
	 * any or no format.
	 *
	 * Possible formats may include:
	 *   - `NULL`, in which case the plugin is free to choose initial values.  Choices may
	 *     include hard-coded in the plugin or none at all.
	 *   - a `\0`-terminated `char*`.  Examples of possible values the parameter could hold:
	 *     1. The entire config.
	 *     2. A local file path on systems which support them.
	 *     3. A string adhering to the URI scheme.
	 *
	 * \note The returned \ref PntosRegistry should be capable of producing \ref PntosKeyValueStore
	 * structs that are able to be used concurrently.  Thus if the user uses the return value of
	 * this method to start two batches, one on group "foo" and the other on group "bar", then
	 * concurrent access to both of the resulting \ref PntosKeyValueStore structs for "foo" and
	 * "bar" should be supported (i.e. no shared mutable state between them that is not
	 * synchronized).
	 */
	PntosRegistry* (*new_registry)(struct PntosRegistryPlugin* self,
	                               char* PNTOS_NULLABLE initial_config);
} PntosRegistryPlugin;

PNTOS_ASSUME_NONNULL_END

#ifdef __cplusplus
}
#endif
