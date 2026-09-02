#include "Dri_iic.h"

void dri_iic_start(void)
{
    IIC_SCL=1;
    IIC_SDA=1;
    IIC_SDA=0;
    IIC_SCL=0;
}

void dri_iic_stop(void)
{
    IIC_SDA=0;
    IIC_SCL=1;
    IIC_SDA=1;
}

void dri_iic_send_byte(u8 dat)
{
    u8 i;
    for(i=0;i<8;i++)
    {
        IIC_SDA=(dat&0x80)?1:0;
        IIC_SCL=1;
        IIC_SCL=0;
        dat<<=1;
    }
}
u8 dri_iic_receive_byte(void)
{
    u8 i,dat=0;
    for(i=0;i<8;i++)
    {
        IIC_SDA=1; // 趁SCL为低，先释放SDA总线，让EEPROM来驱动数据(避免误判成STOP)
        IIC_SCL=1;
        dat<<=1;
        if(IIC_SDA) dat|=0x01;
        IIC_SCL=0;
    }
    return dat;
}

void dri_iic_send_ack(bit ack)
{
    IIC_SDA=ack;
    IIC_SCL=1;
    IIC_SCL=0;
}

bit dri_iic_receive_ack(void)
{
    bit ack;
    IIC_SDA=1;
    IIC_SCL=1;
    ack=IIC_SDA;
    IIC_SCL=0;
    return ack;
}