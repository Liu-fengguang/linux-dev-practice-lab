#ifndef __FSL_COMMON_H
#define __FSL_COMMON_H

#include <stdint.h>

/* SDK 通用宏 */
#ifndef BIT
#define BIT(n)  (1U << (n))
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x)  (sizeof(x) / sizeof((x)[0]))
#endif

/* 引脚方向 */
typedef enum {
    kGPIO_DigitalInput  = 0U,
    kGPIO_DigitalOutput = 1U,
} gpio_pin_direction_t;

/* 引脚配置 */
typedef struct {
    gpio_pin_direction_t direction;
    uint8_t outputLogic;
} gpio_pin_config_t;

#endif
