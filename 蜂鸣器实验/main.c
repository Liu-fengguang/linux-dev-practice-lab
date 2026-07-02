#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_beep.h"

int main(void)
{
    clk_enable();
    beep_init();

    while (1) {
        beep_on();
        delay(500);

        beep_off();
        delay(500);
    }

    return 0;
}
