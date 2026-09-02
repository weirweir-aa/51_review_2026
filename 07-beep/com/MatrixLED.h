#ifndef __MATRIXLED_H__
#define __MATRIXLED_H__

#include "util.h"

#define RCLK P35
#define SRCLK P36
#define SER P34

void matrixled_init(void);
void matrixled_init_eeprom(u8 *buf);

#endif