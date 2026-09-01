#ifndef __LED_H__
#define __LED_H__

#include "util.h"

#define LED_PORT P2
#define LED_NUM 8

#define LED_ON_LEVEL 0

void led_init(void);
void led_on(u8 n);
void led_off(u8 n);
void led_toggle(u8 n);

#endif