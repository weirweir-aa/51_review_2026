#ifndef __UTIL_H__
#define __UTIL_H__

#include <STC89C5xRC.H>
#include <INTRINS.H>

// 8bit无符号数
typedef unsigned char u8;
// 16bit无符号数
typedef unsigned int u16;
// 32bit无符号数
typedef unsigned long u32;

/**
 * @brief 延时一定时长
 *
 * @param count 延时时长，单位1ms
 */
void Delay1ms(u16 count);

#endif