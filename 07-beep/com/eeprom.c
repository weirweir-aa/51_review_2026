#include "eeprom.h"

bit eeprom_write_page(u8 addr, u8 *buf, u8 len)
{
    u8 i;
    bit ack;
    dri_iic_start();
    dri_iic_send_byte(EEPROM_IIC_ADDR);
    ack=dri_iic_receive_ack();

    dri_iic_send_byte(addr);
    ack=dri_iic_receive_ack();

    for(i=0;i<len;i++)
    {
        dri_iic_send_byte(buf[i]);
        ack=dri_iic_receive_ack();
    }

    dri_iic_stop();
    return ack;
}

bit eeprom_write_byte(u8 addr, u8 *buf, u8 len)
{
    u8 page_remain;
    bit ack;
    while(len>0)
    {
        page_remain=EEPROM_PAGE_SIZE-(addr%EEPROM_PAGE_SIZE);
        if(len>page_remain)
        {
            ack=eeprom_write_page(addr,buf,page_remain);
            len-=page_remain;
            addr+=page_remain;
            buf+=page_remain;

            Delay1ms(5);
        }else{
            ack=eeprom_write_page(addr,buf,len);
            len=0;
        }
    }
    return ack;
}

bit eeprom_read_byte(u8 addr, u8 *buf, u8 len)
{
    u8 i;
    bit ack;
    dri_iic_start();
    dri_iic_send_byte(EEPROM_IIC_ADDR);
    ack=dri_iic_receive_ack();

    dri_iic_send_byte(addr);
    ack=dri_iic_receive_ack();

    dri_iic_start();
    dri_iic_send_byte(EEPROM_IIC_ADDR|0x01);
    ack=dri_iic_receive_ack();

    for(i=0;i<len;i++)
    {
        buf[i]=dri_iic_receive_byte();
        if(i<len-1)
            dri_iic_send_ack(0);
        else
            dri_iic_send_ack(1);
    }

    dri_iic_stop();
    return ack;
}