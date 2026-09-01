#include "key.h"

KEY_E key_scan(void)
{
    if (KEY1_PIN == 0)
    {
        Delay1ms(10);              /* 消抖 */
        if (KEY1_PIN == 0)         /* 消抖后再确认一次 */
        {
            while (KEY1_PIN == 0); /* 等待松开 */
            return KEY1;
        }
    }

    if (KEY2_PIN == 0)
    {
        Delay1ms(10);              /* 消抖 */
        if (KEY2_PIN == 0)         /* 消抖后再确认一次 */
        {
            while (KEY2_PIN == 0); /* 等待松开 */
            return KEY2;
        }
    }

    if (KEY3_PIN == 0)
    {
        Delay1ms(10);              /* 消抖 */
        if (KEY3_PIN == 0)         /* 消抖后再确认一次 */
        {
            while (KEY3_PIN == 0); /* 等待松开 */
            return KEY3;
        }
    }

    if (KEY4_PIN == 0)
    {
        Delay1ms(10);              /* 消抖 */
        if (KEY4_PIN == 0)         /* 消抖后再确认一次 */
        {
            while (KEY4_PIN == 0); /* 等待松开 */
            return KEY4;
        }
    }
    return KEY_NONE;
}
