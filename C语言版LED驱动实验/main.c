/* C 语言版 LED 驱动 — IMX6ULL */

/* 寄存器地址 */
#define CCM_CCGR1                    (*(volatile unsigned int *)0x020C406C)
#define IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03  (*(volatile unsigned int *)0x020E0068)
#define IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03  (*(volatile unsigned int *)0x020E02F4)
#define GPIO1_GDIR                   (*(volatile unsigned int *)0x0209C004)
#define GPIO1_DR                     (*(volatile unsigned int *)0x0209C000)

/* 延时 */
void delay(unsigned int n)
{
    while (n--)
        ;
}

int main(void)
{
    /* 1. 使能 GPIO1 时钟（CCGR1 bit27~26 = 11）*/
    CCM_CCGR1 |= (3 << 26);

    /* 2. 配置 GPIO1_IO03 复用为 GPIO（MUX_MODE = 5）*/
    IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 = 0x5;

    /* 3. 配置电气属性 */
    IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03 = 0x10B0;

    /* 4. 设置 GPIO1_IO03 为输出 */
    GPIO1_GDIR |= (1 << 3);

    /* 5. LED 闪烁 */
    while (1) {
        GPIO1_DR &= ~(1 << 3);      /* bit3 = 0，点亮 */
        delay(0xFFFFF);

        GPIO1_DR |= (1 << 3);       /* bit3 = 1，熄灭 */
        delay(0xFFFFF);
    }

    return 0;
}
