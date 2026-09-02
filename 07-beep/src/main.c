#include "util.h"
#include "led.h"
#include "key.h"
#include "eeprom.h"
#include "Dri_Timer0.h"
#include "MatrixLED.h"

static u16 time0_count = 0;

void timer0_count_cfg(void) //timer0的时序基础
{
	time0_count++;
	if(time0_count>=1000)
	{
		time0_count = 0;
	}
}

// static u8 buf_eeprom[] = {
// 	0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80
// };
u8 buf_eeprom[8];

void main()
{
	led_init();

	Dri_Timer0_Init();
	Dri_Timer0_RegisterCallback(timer0_count_cfg);

	// matrixled_init();
	// eeprom_write_byte(0, buf_eeprom, 8);

	eeprom_read_byte(0, buf_eeprom, 8);
	matrixled_init_eeprom(buf_eeprom);

	while(1)
	{
		
	}
}
