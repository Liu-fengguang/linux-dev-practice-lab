#include "bsp_led.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"

/* GPIO1_IO03 的复用和电气属性寄存器地址 */
#define MUX_CTL_PAD_GPIO1_IO03   0x020E0068U
#define PAD_CTL_PAD_GPIO1_IO03   0x020E02F4U

/* ===== 使能所有外设时钟 ===== */
void clk_enable(void)
{
    CCM_Type *ccm = CCM_BASE;
    ccm->CCGR0 = 0xFFFFFFFF;
    ccm->CCGR1 = 0xFFFFFFFF;
    ccm->CCGR2 = 0xFFFFFFFF;
    ccm->CCGR3 = 0xFFFFFFFF;
    ccm->CCGR4 = 0xFFFFFFFF;
    ccm->CCGR5 = 0xFFFFFFFF;
    ccm->CCGR6 = 0xFFFFFFFF;
}

/* ===== 初始化 LED（SDK 方式） ===== */
void led_init(void)
{
    IOMUXC_SetPinMux(MUX_CTL_PAD_GPIO1_IO03, 0x5U);
    IOMUXC_SetPinConfig(PAD_CTL_PAD_GPIO1_IO03, 0x10B0U);

    gpio_pin_config_t led_config = {
        .direction   = kGPIO_DigitalOutput,
        .outputLogic = 0U,
    };
    GPIO_PinInit(GPIO1_BASE, 3U, &led_config);
}

void led_on(void)
{
    GPIO_PinWrite(GPIO1_BASE, 3U, 0U);
}

void led_off(void)
{
    GPIO_PinWrite(GPIO1_BASE, 3U, 1U);
}
