.global _start
.global _bss_start
_bss_start:
    .word __bss_start

.global _bss_end
_bss_end:
    .word __bss_end

_start:
    @ 1. 设置栈指针（Cortex-A7 上电默认进入 SVC 模式）
    @    将 SP 指向内部 RAM 顶部 (DDR init 前用内部 128KB OCRAM)
    ldr sp, =0x00910000

    @ 2. 跳转到 main 函数
    b main

    @ 3. 死循环，防止跑飞
loop:
    b loop
