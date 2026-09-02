#ifndef __Dri_iic_h__
#define __Dri_iic_h__

#include "util.h"

#define IIC_SCL P21
#define IIC_SDA P20

void dri_iic_start(void);
void dri_iic_stop(void);

void dri_iic_send_byte(u8 dat);
u8 dri_iic_receive_byte(void);

void dri_iic_send_ack(bit ack);
bit dri_iic_receive_ack(void);

#endif 