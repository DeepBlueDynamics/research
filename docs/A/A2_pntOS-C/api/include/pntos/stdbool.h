#pragma once

#ifndef __cplusplus
/* Fallback to bool typdefs on C89 */
#	ifdef PNTOS_NO_BOOL
#		define false 0
#		define true 1
#		define bool int
#	else
#		include <stdbool.h>
#	endif
#endif
