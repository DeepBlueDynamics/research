
#ifndef __has_feature
#	define __has_feature(x) 0
#endif

/**
 * Define a set of pragmas and attributes to instrument code to define whether or not pointers may
 * be null. This feature attempts to gracefully disable itself if the current compiler is unable to
 * support static analysis of nullability. However, if this automatic disabling fails, the user may
 * define PNTOS_DISABLE_NULLABILITY to force nullability checks off. In this case, the burden is
 * still on the user to not set NULL to pointers defined as not NULL.
 */
#if __has_feature(nullability) && defined(_Pragma) && !defined(PNTOS_DISABLE_NULLABILITY)

/**
 * Indicates that pointers should be assumed to be not NULL unless they are explicitly marked with
 * PNTOS_NULLABLE.
 *
 * All pointers in type and function definitions declared in the region between
 * PNTOS_ASSUME_NONNULL_BEGIN and PNTOS_ASSUME_NONNULL_END in a file are by default not NULL-able.
 * For example, consider the following code:
 *
 *  #include <pntos/annotations.h>
 *
 *  // After this macro, all pointers are assumed to be not NULL-able unless
 *  // otherwise marked
 *  PNTOS_ASSUME_NONNULL_BEGIN
 *
 *  // This function takes a int pointer parameter that must not be null
 *  int foo(int* a) { ... }
 *  // This function takes a int pointer parameter that may be null
 *  int bar(int* PNTOS_NULLABLE a) { ... }
 *
 *  ...
 *
 *  // Invalid-- parameter a cannot be NULL
 *  foo(NULL);
 *  // OK-- Parameter explicitly marked as nullable
 *  bar(NULL);
 *
 *  PNTOS_ASSUME_NONNULL_END
 *
 * Users of types within a PNTOS_ASSUME_NONNULL region must ensure that pointer fields and arguments
 * are not populated with a NULL value when passing them across pntOS API boundaries. Pointers
 * explicitly annotated with PNTOS_NULLABLE are still nullable, even when within such a region.
 */
#	define PNTOS_ASSUME_NONNULL_BEGIN _Pragma("clang assume_nonnull begin")
/**
 * Ending a default not NULL region started by PNTOS_ASSUME_NONNULL_BEGIN. Definitions after a
 * PNTOS_ASSUME_NONNULL_END return to ambiguous nullability unless otherwise explicitly marked.
 */
#	define PNTOS_ASSUME_NONNULL_END _Pragma("clang assume_nonnull end")
/**
 * Declare a pointer as NULL-able. This macro should follow the pointer asterisk for the pointer
 * that is being declared NULL. Thus, `int ** PNTOS_NULLABLE foo` declares a NULL-able pointer to a
 * non-NULL pointer to int.
 */
#	define PNTOS_NULLABLE _Nullable

#	pragma clang diagnostic ignored "-Wnullability-extension"

/**
 * This is needed due to a seeming bug in clang. Even with assume_nonnull, the compiler still throws
 * warnings for missing nullability attributes
 */
#	pragma clang diagnostic ignored "-Wnullability-completeness"

#else

/**
 * This macro does nothing. To enable compiler non-null checking, compile using a compiler that has
 * the "nullability" feature and do not define PNTOS_DISABLE_NULLABILITY.
 */
#	define PNTOS_ASSUME_NONNULL_BEGIN
/**
 * This macro does nothing. To enable compiler non-null checking, compile using a compiler that has
 * the "nullability" feature and do not define PNTOS_DISABLE_NULLABILITY.
 */
#	define PNTOS_ASSUME_NONNULL_END
/**
 * This macro does nothing. To enable compiler non-null checking, compile using a compiler that has
 * the "nullability" feature and do not define PNTOS_DISABLE_NULLABILITY.
 */
#	define PNTOS_NULLABLE

#endif
