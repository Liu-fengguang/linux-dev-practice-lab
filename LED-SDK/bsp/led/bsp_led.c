#include "bsp_led.h"

void clk_enable(void)
{
    CCM->CCGR0 = 0xFFFFFFFF;
    CCM->CCGR1 = 0xFFFFFFFF;
    CCM->CCGR2 = 0xFFFFFFFF;
    CCM->CCGR3 = 0xFFFFFFFF;
    CCM->CCGR4 = 0xFFFFFFFF;
    CCM->CCGR5 = 0xFFFFFFFF;
    CCM->CCGR6 = 0xFFFFFFFF;
}

void led_init(void)
{
    /* 复用为 GPIO + 配置电气属性 */
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0U);
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0x10B0U);

    /* 设置 GPIO1_IO03 为输出 */
    GPIO1->GDIR |= (1 << 3);
}

void led_on(void)
{
    GPIO1->DR &= ~(1 << 3);
}

void led_off(void)
{
    GPIO1->DR |= (1 << 3);
}
