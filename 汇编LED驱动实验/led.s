.global main

@ 寄存器基地址宏
.equ CCM_BASE,              0x020C4000
.equ CCM_CCGR1,             0x020C406C

.equ IOMUXC_BASE,           0x020E0000
.equ SW_MUX_CTL_GPIO1_IO03, 0x020E0068
.equ SW_PAD_CTL_GPIO1_IO03, 0x020E02F4

.equ GPIO1_BASE,            0x0209C000
.equ GPIO1_DR,              0x0209C000
.equ GPIO1_GDIR,            0x0209C004

main:
    @===== 1. 使能 GPIO1 时钟 =====
    @ CCM_CCGR1[27:26] = 11 (CG13 = GPIO1_CLK_ENABLE)
    ldr r0, =CCM_CCGR1
    ldr r1, [r0]
    orr r1, r1, #0x0C000000    @ bit27~26 置 3
    str r1, [r0]

    @===== 2. 配置 GPIO1_IO03 为 GPIO 模式 =====
    @ IOMUXC_SW_MUX_CTL = 0x5 (ALT5 = GPIO mode)
    ldr r0, =SW_MUX_CTL_GPIO1_IO03
    ldr r1, [r0]
    bic r1, r1, #0x0F          @ 清低 4 位
    orr r1, r1, #0x05          @ MUX_MODE = ALT5
    str r1, [r0]

    @===== 3. 配置电气属性 =====
    @ 上下拉、驱动能力、速率
    ldr r0, =SW_PAD_CTL_GPIO1_IO03
    ldr r1, [r0]
    bic r1, r1, #0x1FFFF
    orr r1, r1, #0x10B0        @ 上下拉 100K + 驱动能力 R0/7 + 速率 100MHz
    str r1, [r0]

    @===== 4. 设置 GPIO1_IO03 为输出 =====
    ldr r0, =GPIO1_GDIR
    ldr r1, [r0]
    orr r1, r1, #(1 << 3)      @ bit3 = 1 (输出)
    str r1, [r0]

led_loop:
    @===== 5. 点亮 LED (输出低电平) =====
    ldr r0, =GPIO1_DR
    ldr r1, [r0]
    bic r1, r1, #(1 << 3)      @ bit3 = 0 (亮)
    str r1, [r0]

    bl delay

    @===== 6. 熄灭 LED (输出高电平) =====
    ldr r0, =GPIO1_DR
    ldr r1, [r0]
    orr r1, r1, #(1 << 3)      @ bit3 = 1 (灭)
    str r1, [r0]

    bl delay

    b led_loop

@===== 延时函数 (约 500ms @ 396MHz) =====
delay:
    ldr r2, =0x00FFFFFF
1:
    subs r2, r2, #1
    bne 1b
    bx lr
