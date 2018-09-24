#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <scic/errno.h>

scic_error_handler_t *scic_error_handler;

static void no_error_handler(const char *reason, const char *file, int line, int scic_errno);

void
scic_error(const char *reason, const char *file, int line, int scic_errno)
{
        if (scic_error_handler)
        {
                (*scic_error_handler)(reason, file, line, scic_errno);
                return;
        }

        scic_stream_printf("ERROR", file, line, reason);

        fflush(stdout);
        fprintf(stderr, "Default SCIC error handler invoked.\n");
        fflush(stderr);

        abort();
}

scic_error_handler_t *
scic_set_error_handler(scic_error_handler_t *new_handler)
{
        scic_error_handler_t *previous_handler = scic_error_handler;

        scic_error_handler = new_handler;
        return previous_handler;
}

scic_error_handler_t *
scic_set_error_handler_off()
{
        scic_error_handler_t *previous_handler = scic_error_handler;

        scic_error_handler = no_error_handler;
        return previous_handler;
}

static void
no_error_handler(const char *reason, const char *file, int line, int scic_errno)
{
        /* do nothing */
        reason = 0;
        file = 0;
        line = 0;
        scic_errno = 0;

        (void)reason;
        (void)file;
        (void)line;
        (void)scic_errno;

        return;
}
