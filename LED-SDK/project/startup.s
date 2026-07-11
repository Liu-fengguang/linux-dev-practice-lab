.global _start
.global _bss_start
_bss_start:
    .word __bss_start

.global _bss_end
_bss_end:
    .word __bss_end

_start:
    mrs r0, cpsr
    bic r0, r0, #0x1F
    orr r0, r0, #0x13
    msr cpsr, r0

    ldr sp, =0x80200000

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

    b main

loop:
    b loop
