#include <scic/errno.h>


FILE *scic_stream = NULL;
scic_stream_handler_t *scic_stream_handler = NULL;


void
scic_stream_printf(const char *label, const char *file, int line,
                  const char *reason)
{
        if (scic_stream == NULL)
        {
                scic_stream = stderr;
        }

        if (scic_stream_handler)
        {
                (*scic_stream_handler)(label, file, line, reason);
                return;
        }

        fprintf (scic_stream, "scic: %s:%d: %s: %s\n", file, line, label, reason);
}


scic_stream_handler_t *
scic_set_stream_handler(scic_stream_handler_t *new_handler)
{
        scic_stream_handler_t *previous_handler = scic_stream_handler;
        scic_stream_handler = new_handler;
        return previous_handler;
}


FILE *
scic_set_stream(FILE *new_stream)
{
        FILE *previous_stream;

        if (scic_stream == NULL) {
                scic_stream = stderr;
        }

        previous_stream = scic_stream;
        scic_stream = new_stream;
        return previous_stream;
}
