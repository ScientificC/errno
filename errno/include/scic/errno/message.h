#ifndef SCIC_ERRNO_H
#error "Never use <scic/errno/message.h> directly; include <scic/errno.h> instead."
#endif

#ifndef SCIC_ERRNO_MSG_H
#define SCIC_ERRNO_MSG_H

__SCIC_ERR_BEGIN_DECLS

/* Provide a general messaging service for client use.  Messages can
 * be selectively turned off at compile time by defining an
 * appropriate message mask. Client code which uses the SCIC_MESSAGE()
 * macro must provide a mask which is or'ed with the SCIC_MESSAGE_MASK.
 *
 * The messaging service can be completely turned off
 * by defining SCIC_MESSAGING_OFF.
 */

void scic_message(const char *message, const char *file, int line,
                  unsigned int mask);

#ifndef SCIC_MESSAGE_MASK
        #define SCIC_MESSAGE_MASK 0xffffffffu /* default all messages allowed */
#endif

extern unsigned int scic_message_mask;

/* Provide some symolic masks for client ease of use. */

enum {
        SCIC_MESSAGE_MASK_A = 1,
        SCIC_MESSAGE_MASK_B = 2,
        SCIC_MESSAGE_MASK_C = 4,
        SCIC_MESSAGE_MASK_D = 8,
        SCIC_MESSAGE_MASK_E = 16,
        SCIC_MESSAGE_MASK_F = 32,
        SCIC_MESSAGE_MASK_G = 64,
        SCIC_MESSAGE_MASK_H = 128
};

#ifdef SCIC_MESSAGING_OFF        /* throw away messages */
        #define SCIC_MESSAGE(message, mask) do { } while (0)
#else                           /* output all messages */
        #define SCIC_MESSAGE(message, mask)                             \
        do {                                                            \
                typeof(mask) tmp = (mask);                              \
                if (tmp & SCIC_MESSAGE_MASK)                            \
                {                                                       \
                        scic_message(message, __FILE__, __LINE__, tmp); \
                }                                                       \
        } while (0)
#endif

__SCIC_ERR_END_DECLS

#endif
