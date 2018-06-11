#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <scic/errno.h>

unsigned int scic_message_mask = SCIC_MESSAGE_MASK;

void
scic_message(const char *reason, const char *file, int line,
             unsigned int mask)
{
        if (mask & scic_message_mask)
        {
                scic_stream_printf ("MESSAGE", file, line, reason);
        }
}
