#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "MCIMX6Y2.h"
#include "fsl_common.h"
#include "fsl_iomuxc.h"

void clk_enable(void);
void led_init(void);
void led_on(void);
void led_off(void);

#endif
