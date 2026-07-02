#include "bsp_beep.h"
#include "imx6ull.h"

/* 初始化蜂鸣器 IO：SNVS_TAMPER1 → GPIO5_IO01 */
void beep_init(void)
{
    /* 复用为 GPIO */
    IOMUXC_SW_MUX_CTL_PAD_SNVS_TAMPER1 = 0x5;   /* ALT5 = GPIO5_IO01 */

    /* 电气属性：0x10B0 */
    IOMUXC_SW_PAD_CTL_PAD_SNVS_TAMPER1 = 0x10B0;

    /* 设为输出 */
    GPIO5_GDIR |= (1 << 1);
}

/* 蜂鸣器响：低电平 */
void beep_on(void)
{
    GPIO5_DR &= ~(1 << 1);
}

/* 蜂鸣器停：高电平 */
void beep_off(void)
{
    GPIO5_DR |= (1 << 1);
}
