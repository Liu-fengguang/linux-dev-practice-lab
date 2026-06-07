SECTIONS {
    . = 0x87800000;          /* 链接起始地址：DDR 或 OCRAM 映射地址 */

    .text : {
        *(.text)             /* 所有代码段 */
    }

    .rodata ALIGN(4) : {
        *(.rodata)           /* 只读数据 */
    }

    .data ALIGN(4) : {
        *(.data)             /* 已初始化数据 */
    }

    __bss_start = .;
    .bss ALIGN(4) : {
        *(.bss)              /* 未初始化数据 */
        *(COMMON)
    }
    __bss_end = .;
}
