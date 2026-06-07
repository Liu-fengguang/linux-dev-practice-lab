.global _start          @ 全局标号

_start:
    @===== 初始化所有外设时钟 =====
    @ 设置 CCGR0~CCGR6 全部为 0xFFFFFFFF，使能所有外设时钟

    ldr r0, =0x020c4068   @ CCGR0
    ldr r1, =0xffffffff   @ 向 CCGRx 写入的数据
    str r1, [r0]          @ 将 0xFFFFFFFF 写入 CCGR0

    ldr r0, =0x020c406c   @ CCGR1
    str r1, [r0]

    ldr r0, =0x020c4070   @ CCGR2
    str r1, [r0]

    ldr r0, =0x020c4074   @ CCGR3
    str r1, [r0]

    ldr r0, =0x020c4078   @ CCGR4
    str r1, [r0]

    ldr r0, =0x020c407c   @ CCGR5
    str r1, [r0]

    ldr r0, =0x020c4080   @ CCGR6
    str r1, [r0]

    @===== 配置 IO 复用 =====
    @ 将 GPIO1_IO03 复用为 GPIO
    @ 寄存器 IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 地址 0x020E0068
    @ bit[3:0] = 0101 = 5，即 ALT5 = GPIO 模式

    ldr r0, =0x020E0068   @ IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 地址
    ldr r1, =0x5          @ MUX_MODE = 5
    str r1, [r0]          @ 将 5 写入寄存器

    @===== 配置电气属性 =====
    @ 寄存器 IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03 地址 0x020E02F4
    @ bit[0]:      0  低速率
    @ bit[5:3]:  110  R0/6 驱动能力
    @ bit[7:6]:   10  100MHz 速度
    @ bit[11]:     0  关闭开漏输出
    @ bit[12]:     1  使能 pull/keeper
    @ bit[13]:     0  keeper
    @ bit[15:14]: 00  100K 下拉
    @ bit[16]:     0  关闭 hys

    ldr r0, =0x020E02F4
    ldr r1, =0x10b0
    str r1, [r0]

    @===== 配置 GPIO 为输出 =====
    @ 寄存器 GPIO1_GDIR 地址 0x0209C004
    @ bit3 = 1，设置 GPIO1_IO03 为输出

    ldr r0, =0x0209C004
    ldr r1, =0x8             @ bit3 = 1
    str r1, [r0]

    @===== 点亮 LED =====
    @ 寄存器 GPIO1_DR 地址 0x0209C000
    @ bit3 = 0，输出低电平，LED 点亮

    ldr r0, =0x0209C000
    ldr r1, =0
    str r1, [r0]

loop:
    b loop
