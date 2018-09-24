#include <scic/errno.h>

const char *
scic_strerror(const int scic_errno)
{
        switch (scic_errno) {
        case SCIC_SUCCESS:
                return "success";
        case SCIC_FAILURE:
                return "failure";
        case SCIC_CONTINUE:
                return "the iteration has not converged yet";
        case SCIC_EDOM:
                return "input domain error";
        case SCIC_ERANGE:
                return "output range error";
        case SCIC_EFAULT:
                return "invalid pointer";
        case SCIC_EINVAL:
                return "invalid argument supplied by user";
        case SCIC_EFAILED:
                return "generic failure";
        case SCIC_EFACTOR:
                return "factorization failed";
        case SCIC_ESANITY:
                return "sanity check failed - shouldn't happen";
        case SCIC_ENOMEM:
                return "malloc failed";
        case SCIC_EBADFUNC:
                return "problem with user-supplied function";
        case SCIC_ERUNAWAY:
                return "iterative process is out of control";
        case SCIC_EMAXITER:
                return "exceeded max number of iterations";
        case SCIC_EZERODIV:
                return "tried to divide by zero";
        case SCIC_EBADTOL:
                return "specified tolerance is invalid or theoretically unattainable";
        case SCIC_ETOL:
                return "failed to reach the specified tolerance";
        case SCIC_EUNDRFLW:
                return "underflow";
        case SCIC_EOVRFLW:
                return "overflow";
        case SCIC_ELOSS:
                return "loss of accuracy";
        case SCIC_EROUND:
                return "roundoff error";
        case SCIC_EBADLEN:
                return "matrix/vector sizes are not conformant";
        case SCIC_ENOTSQR:
                return "matrix not square";
        case SCIC_ESING:
                return "singularity or extremely bad function behavior detected";
        case SCIC_EDIVERGE:
                return "integral or series is divergent";
        case SCIC_EUNSUP:
                return "the required feature is not supported by this hardware platform";
        case SCIC_EUNIMPL:
                return "the requested feature is not (yet) implemented";
        case SCIC_ECACHE:
                return "cache limit exceeded";
        case SCIC_ETABLE:
                return "table limit exceeded";
        case SCIC_ENOPROG:
                return "iteration is not making progress towards solution";
        case SCIC_ENOPROGJ:
                return "jacobian evaluations are not improving the solution";
        case SCIC_ETOLF:
                return "cannot reach the specified tolerance in F";
        case SCIC_ETOLX:
                return "cannot reach the specified tolerance in X";
        case SCIC_ETOLG:
                return "cannot reach the specified tolerance in gradient";
        case SCIC_EOF:
                return "end of file";
        default:
                return "unknown error code";
        }
}
