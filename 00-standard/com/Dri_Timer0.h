#ifndef __DRI_TIMIER0_H
#define __DRI_TIMIER0_H

#include "util.h"

//函数指针
typedef void (*Timer0_Callback)(void);

#define MAX_CALLBACK_NUM 4

void Dri_Timer0_Init(void);
u8 Dri_Timer0_RegisterCallback(Timer0_Callback callback);
u8 Dri_Timer0_DeregisterCallback(Timer0_Callback callback);

#endif