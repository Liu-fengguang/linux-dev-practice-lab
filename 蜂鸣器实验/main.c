#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_beep.h"

int main(void)
{
    clk_enable();    /* 使能外设时钟 */
    beep_init();     /* 初始化蜂鸣器 IO */

    while (1) {
        beep_on();          /* 蜂鸣器响 */
        delay(500);

        beep_off();         /* 蜂鸣器停 */
        delay(500);
    }

    return 0;
}
