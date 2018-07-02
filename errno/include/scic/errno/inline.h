#ifndef SCIC_ERRNO_H
#error "Never use <scic/errno/inline.h> directly; include <scic/err.h> instead."
#endif

#ifndef SCIC_INLINE_H
#define SCIC_INLINE_H

#ifdef _MSC_VER
        #define __SCIC_ERR_INLINE __forceinline
#else
        #define __SCIC_ERR_INLINE inline __attribute((always_inline))
#endif

/* Use `extern inline` for C99 or later */
#ifdef PREDEF_STANDARD_C99
        #define __SCIC_ERR_EXTERN_INLINE extern __SCIC_ERR_INLINE
#else
        #undef __SCIC_ERR_INLINE

        #define __SCIC_ERR_INLINE
        #define __SCIC_ERR_EXTERN_INLINE
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER) || defined(WIN32)
        #define __SCIC_ERR_API __declspec(dllexport)
#endif

#endif
