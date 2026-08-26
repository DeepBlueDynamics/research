
#pragma once
#include <pntos/aspn.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * A superset of AspnMessageType, containing all the canonical ASPN messages, the pntOS-specific
 * extended ASPN messages, and a reserved range for implementation-specific messages.
 */
typedef enum PntosMessageType {
	/* PNTOS_UNDEFINED should never be used. Indicates that uninitialized memory is being used */
	PNTOS_UNDEFINED = ASPN_UNDEFINED,
	/* Add some pntOS messages into the ASPN extended message region */
	ASPN_EXTENDED_MARKER_MESSAGE = ASPN_EXTENDED_BEGIN,
	ASPN_EXTENDED_SERIALIZED_MESSAGE,
	PNTOS_LAST_MESSAGE = ASPN_EXTENDED_SERIALIZED_MESSAGE,
	/* The values between PNTOS_EXTENDED_BEGIN and PNTOS_EXTENDED_END are reserved for extensions to
	   pntOS. pntOS users who need to pass custom messages may use these values for implementation
	   specific messages. Users utilizing these values must ensure all implementations coordinate on
	   the interpretation of these values. Any values before PNTOS_EXTENDED_BEGIN are reserved for
	   usage by future pntOS/ASPN revisions. Users must not use any value between PNTOS_LAST_MESSAGE
	   and PNTOS_EXTENDED_BEGIN until those values are specified by a future pntOS revision.
	*/
	PNTOS_EXTENDED_BEGIN = 0xC000,
	PNTOS_EXTENDED_END   = 0xFFFF,

} PntosMessageType;

#ifdef __cplusplus
}
#endif
