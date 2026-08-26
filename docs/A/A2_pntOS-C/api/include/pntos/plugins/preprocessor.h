#pragma once

#include <pntos/plugins/common.h>

#ifdef __cplusplus
extern "C" {
#endif

PNTOS_ASSUME_NONNULL_BEGIN

/**
 * A preprocessor.
 *
 * **UNSTABLE**: This feature is unstable and is not yet considered part of the stable pntOS API.
 * Usage of this feature is highly discouraged in non-experimental code, and its definition may
 * change at any time.
 */
typedef struct PntosPreprocessor {
	PntosManagedMemory* memory;

	/**
	 * @param message A message to be processed.
	 * @return An array of messages. Usually this will be a single message, a modified version of \p
	 * message. It could be NULL if \p message is rejected or dropped. The preprocessor could also
	 * accumulate several messages, returning NULL for each one then returning an array with
	 * multiple processed messages. While the PntosMessageArray may be NULL, all elements in the
	 * array should not be NULL.
	 */
	PntosMessageArray* PNTOS_NULLABLE (*process_pntos_message)(struct PntosPreprocessor* self,
	                                                           PntosMessage* message);
} PntosPreprocessor;

/**
 * An implementation of a preprocessor plugin. This plugin generates PntosPreprocessor instances
 * which may be used to process incoming messages before being distributed to other plugins.
 *
 * **UNSTABLE**: This feature is unstable and is not yet considered part of the stable pntOS API.
 * Usage of this feature is highly discouraged in non-experimental code, and its definition may
 * change at any time.
 */
typedef struct PntosPreprocessorPlugin {
	PntosCommonPlugin common;

	/**
	 * The number of different kinds of PntosPreprocessors that this PntosPreprocessorPlugin can
	 * create. This field describes the length of #preprocessor_identifiers as well as the set of
	 * valid values for the `preprocessor_index` parameter to #new_preprocessor.
	 */
	size_t num_preprocessors;

	/**
	 * A list of identifying strings for each kind of PntosPreprocessor that this
	 * PntosPreprocessorPlugin can create instances of.
	 *
	 * The field is a #num_preprocessors sized array of pointers to `\0` terminated C strings.  The
	 * `preprocessor_index` parameter of #new_preprocessor is an index into this array.
	 */
	char** preprocessor_identifiers;

	/**
	 * @return A newly created PntosPreprocessor. Returns NULL if \p preprocessor_index is greater
	 * than or equal to #num_preprocessors or if \p config_group is invalid.
	 *
	 * @param preprocessor_index Since the PntosPreprocessorPlugin can create #num_preprocessors
	 * different kinds of PntosPreprocessor, the \p preprocessor_index parameter is used to select
	 * which kind of preprocessor to create a new instance of. The #preprocessor_identifiers field
	 * contains identifying strings for the kinds of preprocessors. For example, if the plugin can
	 * create 45 different preprocessors, the identifier of the last preprocessor that can be
	 * created is found in `preprocessor_identifiers[44]`. An instance of this preprocessor can be
	 * created by calling `new_preprocessor(self, 44, ...)`. Note that `0 <= preprocessor_index <
	 * num_preprocessors`.
	 *
	 * @param config_group Indicates which (if any) parameter group in the registry may be used to
	 * obtain additional configuration values to generate the new preprocessor. If the preprocessor
	 * requires no outside configuration, \p config_group may be NULL.
	 */
	PntosPreprocessor* PNTOS_NULLABLE (*new_preprocessor)(struct PntosPreprocessorPlugin* self,
	                                                      size_t preprocessor_index,
	                                                      char* PNTOS_NULLABLE config_group);
} PntosPreprocessorPlugin;

PNTOS_ASSUME_NONNULL_END

#ifdef __cplusplus
}
#endif
