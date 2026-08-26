#pragma once
/**
 * A C89 support library. Relying on __STDC_VERSION__, __cplusplus, __GNUC__ et al is unreliable, so
 * we'll use defines to choose functionality and rely on the build system to define things properly.
 */

/* Fallback to platform specific lengths on C89 */
#ifdef PNTOS_NO_STDINT

typedef char int8_t;
typedef short int int16_t;
typedef int int32_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#	ifdef PNTOS_LONG_LONG
typedef long long int64_t;
typedef unsigned long long uint64_t;
#	else  /* PNTOS_LONG_LONG */
typedef long int64_t;
typedef unsigned long uint64_t;
#	endif /* PNTOS_LONG_LONG */

#else /* PNTOS_NO_STDINT */
#	include <stdint.h>
#endif /* PNTOS_NO_STDINT */
