#include "util.h"
#include "led.h"
#include "key.h"
#include "Dri_Timer0.h"

static u16 time0_count = 0;

void timer0_count_cfg(void) //timer0的时序基础
{
	time0_count++;
	if(time0_count>=1000)
	{
		time0_count = 0;
	}
}

void led0_toggle_timer0(void)
{
	if(time0_count>=200)
	{
		led_toggle(0);
	}
}

void main()
{
	led_init();

	Dri_Timer0_Init();
	Dri_Timer0_RegisterCallback(timer0_count_cfg);
	Dri_Timer0_RegisterCallback(led0_toggle_timer0);

	while(1)
	{
		
	}
}
