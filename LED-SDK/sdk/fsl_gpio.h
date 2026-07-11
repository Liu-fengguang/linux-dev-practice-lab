#ifndef __FSL_GPIO_H
#define __FSL_GPIO_H

#include "imx6ull.h"
#include "fsl_common.h"

void GPIO_PinInit(GPIO_Type *base, uint32_t pin, const gpio_pin_config_t *config);
void GPIO_PinWrite(GPIO_Type *base, uint32_t pin, uint8_t output);

#endif
