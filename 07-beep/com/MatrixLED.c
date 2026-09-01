#include "MatrixLED.h"
#include "Dri_Timer0.h"

static u8 led_buff[8]={
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80
}; // Assuming an 8x8 matrix LED

void matrixled_timer0_callback(void)
{
    static u8 row = 0;
    P0=0xFF;

    SER=(row==0) ?1:0;
    SRCLK=0;
    SRCLK=1;

    RCLK=0;
    RCLK=1;

    P0=~led_buff[row];
    row++;
    row %= 8; // Wrap around to the first row after the last row
}

void matrixled_init(void)
{
    P0=0xFF; // Set all rows to off
    Dri_Timer0_RegisterCallback(matrixled_timer0_callback);
    // Initialization code for the matrix LED
}