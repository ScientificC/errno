#ifndef SCIC_ERRNO_H
#define SCIC_ERRNO_H

#include <stdio.h>

#include <scic/errno/default.h>
#include <scic/errno/inline.h>
#include <scic/errno/message.h>

__SCIC_ERR_BEGIN_DECLS

enum {
        SCIC_SUCCESS  = 0,
        SCIC_FAILURE  = -1,
        SCIC_CONTINUE = -2, /* iteration has not converged */
        SCIC_EDOM     = 1, /* input domain error, e.g sqrt(-1) */
        SCIC_ERANGE   = 2, /* output range error, e.g. exp(1e100) */
        SCIC_EFAULT   = 3, /* invalid pointer */
        SCIC_EINVAL   = 4, /* invalid argument supplied by user */
        SCIC_EFAILED  = 5, /* generic failure */
        SCIC_EFACTOR  = 6, /* factorization failed */
        SCIC_ESANITY  = 7, /* sanity check failed - shouldn't happen */
        SCIC_ENOMEM   = 8, /* malloc failed */
        SCIC_EBADFUNC = 9, /* problem with user-supplied function */
        SCIC_ERUNAWAY = 10, /* iterative process is out of control */
        SCIC_EMAXITER = 11, /* exceeded max number of iterations */
        SCIC_EZERODIV = 12, /* tried to divide by zero */
        SCIC_EBADTOL  = 13, /* user specified an invalid tolerance */
        SCIC_ETOL     = 14, /* failed to reach the specified tolerance */
        SCIC_EUNDRFLW = 15, /* underflow */
        SCIC_EOVRFLW  = 16, /* overflow  */
        SCIC_ELOSS    = 17, /* loss of accuracy */
        SCIC_EROUND   = 18, /* failed because of roundoff error */
        SCIC_EBADLEN  = 19, /* matrix, vector lengths are not conformant */
        SCIC_ENOTSQR  = 20, /* matrix not square */
        SCIC_ESING    = 21, /* apparent singularity detected */
        SCIC_EDIVERGE = 22, /* integral or series is divergent */
        SCIC_EUNSUP   = 23, /* requested feature is not supported by the hardware */
        SCIC_EUNIMPL  = 24, /* requested feature not (yet) implemented */
        SCIC_ECACHE   = 25, /* cache limit exceeded */
        SCIC_ETABLE   = 26, /* table limit exceeded */
        SCIC_ENOPROG  = 27, /* iteration is not making progress towards solution */
        SCIC_ENOPROGJ = 28, /* jacobian evaluations are not improving the solution */
        SCIC_ETOLF    = 29, /* cannot reach the specified tolerance in F */
        SCIC_ETOLX    = 30, /* cannot reach the specified tolerance in X */
        SCIC_ETOLG    = 31, /* cannot reach the specified tolerance in gradient */
        SCIC_EOF      = 32 /* end of file */
};

void scic_error(const char *reason, const char *file, int line,
                int scic_errno);

void scic_stream_printf(const char *label, const char *file,
                        int line, const char *reason);

const char *scic_strerror(const int scic_errno);

typedef void scic_error_handler_t (const char *reason, const char *file,
                                   int line, int scic_errno);

typedef void scic_stream_handler_t (const char *label, const char *file,
                                    int line, const char *reason);

scic_error_handler_t *
scic_set_error_handler(scic_error_handler_t *new_handler);

scic_error_handler_t *
scic_set_error_handler_off(void);

scic_stream_handler_t *
scic_set_stream_handler(scic_stream_handler_t *new_handler);

FILE *scic_set_stream(FILE *new_stream);

/* SCIC_ERROR: call the error handler, and return the error code */
#define SCIC_ERROR(reason, scic_errno)                                  \
        do {                                                            \
                int tmp = scic_errno;                                   \
                scic_error(reason, __FILE__, __LINE__, tmp);            \
                return tmp;                                             \
        } while (0)

/* SCIC_ERROR_VAL: call the error handler, and return the given value */
#define SCIC_ERROR_VAL(reason, scic_errno, value)                       \
        do {                                                            \
                scic_error(reason, __FILE__, __LINE__, scic_errno);     \
                return value;                                           \
        } while (0)

/* SCIC_ERROR_VOID: call the error handler, and then return
 * (for void functions which still need to generate an error)
 */
#define SCIC_ERROR_VOID(reason, scic_errno)                             \
        do {                                                            \
                scic_error(reason, __FILE__, __LINE__, scic_errno);     \
                return;                                                 \
        } while (0)

/* SCIC_ERROR_NULL suitable for out-of-memory conditions */

#define SCIC_ERROR_NULL(reason, scic_errno) \
                SCIC_ERROR_VAL(reason, scic_errno, 0)

/* Sometimes you have several status results returned from
 * function calls and you want to combine them in some sensible
 * way. You cannot produce a "total" status condition, but you can
 * pick one from a set of conditions based on an implied hierarchy.
 *
 * In other words:
 *    you have: status_a, status_b, ...
 *    you want: status = (status_a if it is bad, or status_b if it is bad,...)
 *
 * In this example you consider status_a to be more important and
 * it is checked first, followed by the others in the order specified.
 *
 * Here are some dumb macros to do this.
 */

#define SCIC_ERROR_SELECT_2(a, b)                               \
        (typeof(a) tmp = (a), tmp != SCIC_SUCCESS ?             \
                tmp :                                           \
                (typeof(b) _tmp = (b), _tmp != SCIC_SUCCESS ?   \
                        (_tmp) :                                \
                        SCIC_SUCCESS))

#define SCIC_ERROR_SELECT_3(a, b, c)                            \
        (typeof(a) tmp = (a), tmp != SCIC_SUCCESS ?             \
                tmp :                                           \
                SCIC_ERROR_SELECT_2(b, c))

#define SCIC_ERROR_SELECT_4(a, b, c, d)                         \
        (typeof(a) tmp = (a), tmp != SCIC_SUCCESS ?             \
                tmp :                                           \
                SCIC_ERROR_SELECT_3(b, c, d))

#define SCIC_ERROR_SELECT_5(a, b, c, d, e)                      \
        (typeof(a) tmp = (a), tmp != SCIC_SUCCESS ?             \
                tmp :                                           \
                SCIC_ERROR_SELECT_4(b, c, d, e))

#define SCIC_STATUS_UPDATE(sp, s) do {                          \
        typeof(tmp) = (s);                                      \
        if (tmp != SCIC_SUCCESS)                                \
                *(sp) = tmp;                                    \
} while (0)

__SCIC_ERR_END_DECLS

#endif
