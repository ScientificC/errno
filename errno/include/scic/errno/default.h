#ifndef SCIC_ERRNO_H
#error "Never use <scic/errno/default.h> directly; include <scic/err.h> instead."
#endif

#ifndef SCIC_DEFAULT_H
#define SCIC_DEFAULT_H

/* Check C standard */
#ifdef __STDC__
        #define PREDEF_STANDARD_C89
        #ifdef __STDC_VERSION__
                #if __STDC_VERSION__ >= 199901L
                        #define PREDEF_STANDARD_C99
                        #if __STDC_VERSION__ >= 201112L
                                #define PREDEF_STANDARD_C11
                        #endif
                #endif
        #endif
#endif

#define __SCIC_ERR_BEGIN_DECLS
#define __SCIC_ERR_END_DECLS

#ifdef __cplusplus
        #undef __SCIC_ERR_BEGIN_DECLS
        #undef __SCIC_ERR_END_DECLS

        #define __SCIC_ERR_BEGIN_DECLS extern "C" {
        #define __SCIC_ERR_END_DECLS }

        #if __cplusplus >= 199901L
                #define PREDEF_STANDARD_CPP99
                #if __cplusplus >= 201112L
                        #define PREDEF_STANDARD_CPP11
                #endif
        #endif
#endif

#ifndef PREDEF_STANDARD_C11
        #undef __SCIC_ERR_NO_GENERIC
        #define __SCIC_ERR_NO_GENERIC
#endif

#define __SCIC_ERR_ARGS_FIRST(A, ...) A

#ifndef RETURN_IF_NULL
#define RETURN_IF_NULL(x) do { if (!(x)) return; } while (0)
#endif

#endif
