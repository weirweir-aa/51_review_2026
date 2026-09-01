#ifndef __KEY_H__
#define __KEY_H__

#include "util.h"

#define KEY1_PIN  P31
#define KEY2_PIN  P30
#define KEY3_PIN  P32
#define KEY4_PIN  P33

typedef enum {
    KEY_NONE = 0,   /* 无按键 */
    KEY1,           /* 1 */
    KEY2,           /* 2 */
    KEY3,           /* 3 */
    KEY4            /* 4 */
} KEY_E;

KEY_E key_scan(void);

#endif
