#pragma once

#include <pntos/annotations.h>
#include <pntos/aspn.h>
#include <pntos/stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

PNTOS_ASSUME_NONNULL_BEGIN

/**
 * A heartbeat message containing a timestamp. One example use-case of this message is when a filter
 * should be propagated to a certain time but no filter update needs to be performed.
 *
 * **UNSTABLE**: This feature is unstable and is not yet considered part of the stable pntOS API.
 * Usage of this feature is highly discouraged in non-experimental code, and its definition may
 * change at any time.
 */
typedef struct AspnExtendedMarkerMessage {

	AspnBase base;

	/**
	 * Whole number of nanoseconds elapsed since the ASPN system time epoch. If negative, whole
	 * number nanoseconds until the ASPN system time epoch.
	 */
	int64_t elapsed_nsec;

} AspnExtendedMarkerMessage;

/**
 * Serialized data with an identifier that can be used for message routing through the pntOS system.
 * The serialized data can be used for communication between plugins where only the sending and
 * receiving plugins need to know how to encode or decode the message.
 *
 * **UNSTABLE**: This feature is unstable and is not yet considered part of the stable pntOS API.
 * Usage of this feature is highly discouraged in non-experimental code, and its definition may
 * change at any time.
 */
typedef struct AspnExtendedSerializedMessage {

	AspnBase base;

	/**
	 * Whole number nanoseconds elapsed since timestamp's zero epoch. If negative,
	 * whole number nanoseconds until timestamp's zero epoch.
	 */
	int64_t elapsed_nsec;

	/**
	 * A unique identifier for this serialized message
	 */
	char* identifier;

	/**
	 * The length of the above data array.
	 */
	uint32_t data_len;

	/**
	 * A pointer to a serialized data stream. The data stream format can be based
	 * on the content of the above identifier. Two plugins communicating by sharing this data must
	 * agree on a format, such that they both interpret the data the same
	 * way.
	 */
	unsigned char* data;

} AspnExtendedSerializedMessage;

PNTOS_ASSUME_NONNULL_END

#ifdef __cplusplus
}
#endif
