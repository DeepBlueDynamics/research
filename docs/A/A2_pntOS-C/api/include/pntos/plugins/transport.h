#pragma once

#include <pntos/plugins/common.h>

#ifdef __cplusplus
extern "C" {
#endif

PNTOS_ASSUME_NONNULL_BEGIN

/**
 * A plugin that abstracts a network transport, listening for sensor data off the wire and sending
 * data back to the sensors as needed.
 */
typedef struct PntosTransportPlugin {
	PntosCommonPlugin common;
	/**
	 * Start listening to the transport that this plugin implements, calling the appropriate
	 * controller function as data streams in.
	 */
	void (*start_listening)(struct PntosTransportPlugin* self);
	/**
	 * Disable listening to the transport that was previously started in a call to #start_listening.
	 */
	void (*stop_listening)(struct PntosTransportPlugin* self);
	/**
	 * Send a message back out to the sensor from pntOS. If \p channel_name is NULL the
	 * implementation may decide where \p message should be routed, if anywhere. For example, a
	 * serial cable might send all messages to a single destination.
	 */
	void (*broadcast_message)(struct PntosTransportPlugin* self,
	                          PntosMessage* message,
	                          char* PNTOS_NULLABLE channel_name);
} PntosTransportPlugin;

PNTOS_ASSUME_NONNULL_END

#ifdef __cplusplus
}
#endif
