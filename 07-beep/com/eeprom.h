#ifndef __EEPROM_h__ 
#define __EEPROM_h__

#include "util.h"
#include "Dri_iic.h"

#define EEPROM_IIC_ADDR 0xA0
#define EEPROM_PAGE_SIZE 16

bit eeprom_write_byte(u8 addr, u8 *buf, u8 len);

bit eeprom_read_byte(u8 addr, u8 *buf, u8 len);

#endif