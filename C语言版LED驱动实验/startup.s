.global _start
.global _bss_start
_bss_start:
    .word __bss_start

.global _bss_end
_bss_end:
    .word __bss_end

_start:
    @ 1. 设置 SP 指针（C 语言需要栈）
    ldr sp, =0x00910000

    @ 2. 清零 .bss 段（C 语言未初始化全局变量必须 = 0）
    ldr r0, _bss_start
    ldr r1, _bss_end
    mov r2, #0
bss_loop:
    cmp r0, r1
    beq bss_done
    str r2, [r0]
    add r0, r0, #4
    b bss_loop
bss_done:

    @ 3. 跳转 C 语言 main 函数
    b main

loop:
    b loop
