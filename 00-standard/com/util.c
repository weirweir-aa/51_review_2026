#include "util.h"

void Delay1ms(u16 count) //@11.0592MHz
{
    u8 i, j;

    while (count > 0)
    {
        count--;
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j)
                ;
        } while (--i);
    }
}