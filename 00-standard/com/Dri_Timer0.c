#include "Dri_Timer0.h"
#include <STDIO.H>

#define FOSC (11059200L) //晶振频率
#define T0MS (65536 - FOSC / 12 / 1000) //定时器初值

static Timer0_Callback callbacks[MAX_CALLBACK_NUM] = {0}; //回调函数数组

void Dri_Timer0_Init(void)
{
    u8 i;

    TMOD &= 0xF0; //设置定时器0为模式1
    TMOD |= 0x01;
    TL0 = T0MS & 0xFF; //设置定时器初值
    TH0 = T0MS >> 8;
    ET0 = 1; //允许定时器0中断
    TR0 = 1; //启动定时器0
    EA = 1;  //允许总中断

    for (i = 0; i < MAX_CALLBACK_NUM; i++)
    {
        callbacks[i] = NULL;
    }
}

u8 Dri_Timer0_RegisterCallback(Timer0_Callback callback)
{
    u8 i;

    for (i = 0; i < MAX_CALLBACK_NUM; i++)
    {
        if (callbacks[i] == callback)
        {
            return 1; // Callback already registered
        }
    }

    for (i = 0; i < MAX_CALLBACK_NUM; i++)
    {
        if (callbacks[i] == NULL)
        {
            callbacks[i] = callback;
            return 0; // Callback registered successfully
        }
    }
}

u8 Dri_Timer0_DeregisterCallback(Timer0_Callback callback)
{
    u8 i;

    for (i = 0; i < MAX_CALLBACK_NUM; i++)
    {
        if (callbacks[i] == callback)
        {
            callbacks[i] = NULL;
            return 0; // Callback deregistered successfully
        }
    }

    return 1; // Callback not found
}

void Dri_Timer0_ISR(void) interrupt 1
{
    u8 i;

    TL0 = T0MS & 0xFF; //重新加载定时器初值
    TH0 = T0MS >> 8;

    for (i = 0; i < MAX_CALLBACK_NUM; i++)
    {
        if (callbacks[i] != NULL)
        {
            callbacks[i](); //调用回调函数
        }
    }
}