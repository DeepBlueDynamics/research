#pragma once

#include <pntos/aspn.h>
#include <pntos/plugins/common.h>

#ifdef __cplusplus
extern "C" {
#endif

PNTOS_ASSUME_NONNULL_BEGIN

/**
 * This type configures the buffering, delay, and sorting characteristics of messages that are
 * streamed into the orchestration plugin. The pntOS system will deliver messages to the
 * orchestration plugin as it receives them. However, there is a fundamental tradeoff
 * between latency and those messages being in-order. In particular, to guarantee that messages are
 * sorted by timestamp, it is necessary to build a buffer and delay delivery, such that a sorting
 * function may be applied. This structure allows the plugin to choose which messages are buffered
 * and which are not.
 */
typedef struct PntosMessageStreamConfig {
	/**
	 * Request messages of the given PntosMessageType and optional \p source_identifier are
	 * streamed in sorted timestamp ordering. Note that the ability to do this reliably will
	 * depend on the length of the buffer used by the mediator.
	 */
	void (*sequenced_stream_add)(PntosMediator* self,
	                             PntosMessageType type,
	                             char* PNTOS_NULLABLE source_identifier);
	/**
	 * Request messages of the given PntosMessageType and optional \p source_identifier are no
	 * longer streamed in sorted timestamp ordering. This will remove a type that was previously
	 * added in a call to #sequenced_stream_add, or remove individual messages from the entire
	 * list of messages that was added with a previous call to #sequenced_stream_all.
	 */
	void (*sequenced_stream_remove)(PntosMediator* self,
	                                PntosMessageType type,
	                                char* PNTOS_NULLABLE source_identifier);
	/**
	 * Request all messages are streamed in sorted timestamp ordering. Note that the ability to
	 * do this reliably will depend on the length of the buffer used by the mediator.
	 */
	void (*sequenced_stream_all)(PntosMediator* self, bool enable);

	/**
	 * Request messages of the given PntosMessageType and optional \p source_identifier are streamed
	 * immediately without delay, buffering, or sorting.
	 */
	void (*immediate_stream_add)(PntosMediator* self,
	                             PntosMessageType type,
	                             char* PNTOS_NULLABLE source_identifier);
	/**
	 * Request messages of the given PntosMessageType and optional \p source_identifier are no
	 * longer streamed immediately. This will remove a type that was previously added in a call to
	 * #immediate_stream_add, or remove individual messages from the entire list of messages that
	 * was added with a previous call to #immediate_stream_all.
	 */
	void (*immediate_stream_remove)(PntosMediator* self,
	                                PntosMessageType type,
	                                char* PNTOS_NULLABLE source_identifier);
	/**
	 * Request all messages are streamed immediately without delay, buffering, or sorting.
	 */
	void (*immediate_stream_all)(PntosMediator* self, bool enable);
} PntosMessageStreamConfig;

/**
 * The pntOS orchestration plugin is responsible for orchestrating one or more fusion
 * engines, state model providers and other plugins in order to perform sensor fusion. The
 * orchestration plugin is sent (sorted, buffered) ASPN messages from the controller, and is
 * responsible for computing a solution for the system, as well as estimating any other quantities
 * of interest.
 *
 * In order to achieve this task, the orchestration plugin may be passed a set of other plugins
 * during the call to PntosOrchestrationPlugin.init_orchestration_plugin. If so, the orchestration
 * plugin then, as the name suggests, configures and orchestrates these plugins to work together to
 * perform sensor fusion. For example, the orchestration plugin may set up a fusion engine it
 * received in the call to PntosOrchestrationPlugin.init_orchestration_plugin, then add state blocks
 * or measurement processors to that fusion engine from a state modeling plugin it also received,
 * and process inertial data from an inertial plugin it received. The
 * PntosOrchestrationPlugin.request_solutions function will be called by the system when pntOS needs
 * to know the current filtering solutions. Other quantities which need to be estimated by the
 * orchestration engine can be returned to the system by registry updates.
 */
typedef struct PntosOrchestrationPlugin {
	PntosCommonPlugin common;
	/**
	 * Initial data structures needed by the orchestration plugin. This function will be
	 * called by the system after the PntosCommonPlugin.init_plugin but before any other call to an
	 * orchestration plugin function.
	 *
	 * The \p plugins parameter is a set of plugins which should be used by the orchestration
	 * plugin. For example, the plugins list may include a PntosStandardFusionEngine, which the
	 * orchestration plugin can use to perform fusion of sensor data received. The list may also
	 * include a state modeling plugin, which the orchestration plugin can use to extract the
	 * algorithms needed for parsing sensor data into the data model a fusion engine needs.  If the
	 * orchestration plugin does not require any plugins, `NULL` may be passed.
	 *
	 * The \p stream_config parameter is a set of configuration options that the orchestration
	 * plugin can use to indicate to the controller how it would prefer delivery of messages. When
	 * the orchestration plugin receives the \p stream_config struct, it should call the functions
	 * on it to set up how messages will be delivered to it. If it does not, the order of messages'
	 * arrival will be unspecified and at the discretion of the controller.
	 */
	void (*init_orchestration_plugin)(struct PntosOrchestrationPlugin* self,
	                                  PntosPluginArray* PNTOS_NULLABLE plugins,
	                                  PntosMessageStreamConfig stream_config);

	/**
	 * Deliver a new message from an external to pntOS source into the orchestration plugin. The
	 * plugin should utilize this sensor data contained in message by passing it into a fusion
	 * engine.
	 */
	void (*process_pntos_message)(struct PntosOrchestrationPlugin* self,
	                              PntosMessage* message,
	                              bool sequenced);

	/**
	 * Request a list of strings describing the filters available in this Orchestration plugin. One
	 * of these description strings may be used when calling #request_solutions. For consistency,
	 * these strings should adhere to the following conventions:
	 *
	 * - Strings should be upper case and have words and acronyms separated by underscores
	 *   (`UPPER_SNAKE_CASE`).
	 * - Strings should contain the substring `BEST` when they represent the primary solution.
	 * - Strings should contain the substring DEAD_RECKONING when they represent a solution suitable
	 *   for estimating relative motion or rotation over a period of time. This solution may drift
	 *   more than BEST solutions, as the goal is to allow a user to get an estimate of the relative
	 *   motion between different times. In the calculation of this solution, some sensor
	 *   measurement might be excluded. For example, a system with an IMU might provide a
	 *   DEAD_RECKONING solution which is the solution from its free-running inertial mechanization,
	 *   with resets disabled during the time intervals between solution_times (but resets applied
	 *   before all of the solution_times).
	 * - Strings should include a substring indicating the type of solution returned. This substring
	 *   should contain the string-equivalent to the AspnMessageType enum value, followed by the
	 *   string `_ESTIMATE`. This allows the user to perform substring matching without a risk of
	 *   getting a false positive match from a type whose string would be a subset of another type.
	 *
	 * For example, if the primary solution is an ASPN PVA then the string
	 * `MY_BEST_ASPN_MEASUREMENT_POSITION_VELOCITY_ATTITUDE_ESTIMATE` would fulfill the convention.
	 *
	 * These conventions allow the user to identify their desired type of solution using substring
	 * matching.
	 */
	PntosStringArray* (*get_filter_description_list)(struct PntosOrchestrationPlugin* self);

	/**
	 * Request filtering solutions at the times specified in the array \p solution_times. The number
	 * of time entries in \p solution_times is specified by \p num_solution_times.
	 *
	 * An Orchestration plugin may run multiple filters. To select which filter(s) to request
	 * solutions from, enter a valid filter description string in \p filter_description. Valid
	 * filter description strings can be obtained by calling get_filter_description_list(). Passing
	 * in NULL will provide a result specific to a particular Orchestration plugin implementation.
	 * When \p filter_description is NULL, the implementation should endeavor to return its best
	 * solution.
	 *
	 * Returned will be an array of messages containing the filter solutions for the requested \p
	 * solution_times. The number of solutions should equal \p num_solution_times, although some
	 * entries may be NULL if they are unavailable at the corresponding time in \p solution_times.
	 * The returned PntosMessageArray may be NULL if \p filter_description is invalid.
	 */
	PntosMessageArray* PNTOS_NULLABLE (*request_solutions)(struct PntosOrchestrationPlugin* self,
	                                                       AspnTypeTimestamp* solution_times,
	                                                       size_t num_solution_times,
	                                                       char* PNTOS_NULLABLE filter_description);

} PntosOrchestrationPlugin;

PNTOS_ASSUME_NONNULL_END

#ifdef __cplusplus
}
#endif
