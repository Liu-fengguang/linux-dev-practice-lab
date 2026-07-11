#include "fsl_gpio.h"

void GPIO_PinInit(GPIO_Type *base, uint32_t pin, const gpio_pin_config_t *config)
{
    if (config->direction == kGPIO_DigitalOutput) {
        base->GDIR |= (1U << pin);   /* 设为输出 */
    } else {
        base->GDIR &= ~(1U << pin);  /* 设为输入 */
    }
}

void GPIO_PinWrite(GPIO_Type *base, uint32_t pin, uint8_t output)
{
    if (output == 0U) {
        base->DR &= ~(1U << pin);    /* 清位 → 低电平 */
    } else {
        base->DR |= (1U << pin);     /* 置位 → 高电平 */
    }
}
