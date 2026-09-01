#include "led.h"

void led_init(void)
{
    LED_PORT = 0xFF;   /* 全部熄灭：低电平点亮，写1=灭 */
}

#if LED_ON_LEVEL == 0      /* 低电平点亮 */
void led_on(u8 n)  { LED_PORT &= ~(1 << n); }
void led_off(u8 n) { LED_PORT |=  (1 << n); }
#else                      /* 高电平点亮 */
void led_on(u8 n)  { LED_PORT |=  (1 << n); }
void led_off(u8 n) { LED_PORT &= ~(1 << n); }
#endif

void led_toggle(u8 n) { LED_PORT ^= (1 << n); }