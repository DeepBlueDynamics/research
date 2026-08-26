#pragma once

#include <pntos/plugins/common.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

PNTOS_ASSUME_NONNULL_BEGIN

/**
 * A plugin for logging out data to an arbitrary sink (e.g. console, file, network, etc.).
 */
typedef struct PntosLoggingPlugin {
	PntosCommonPlugin common;
	/**
	 * Log a string to the logging plugin's sink. \p source_plugin_type and \p
	 * source_plugin_identifier are information on the plugin that sent the logout, \p level is the
	 * event severity, and \p message the string contents to be logged.
	 */
	void (*log)(struct PntosLoggingPlugin* self,
	            PntosPluginTypes source_plugin_type,
	            char* source_plugin_identifier,
	            PntosLoggingLevel level,
	            char* message);
	void (*log_fmt)(struct PntosLoggingPlugin* self,
	                PntosPluginTypes source_plugin_type,
	                char* source_plugin_identifier,
	                PntosLoggingLevel level,
	                char* fmt,
	                va_list args);
} PntosLoggingPlugin;

PNTOS_ASSUME_NONNULL_END

#ifdef __cplusplus
}
#endif
