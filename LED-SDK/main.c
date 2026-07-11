#include "bsp_led.h"

void delay(volatile unsigned int n)
{
    while (n--) {
        volatile unsigned int i = 0x7ff;
        while (i--)
            ;
    }
}

int main(void)
{
    clk_enable();
    led_init();

    while (1) {
        led_on();
        delay(500);

        led_off();
        delay(500);
    }

    return 0;
}
