#ifndef __IMX6ULL_H
#define __IMX6ULL_H

#include <stdint.h>

/* CCM 时钟模块基地址 */
#define CCM_BASE    ((CCM_Type *)0x020C4000)

/* IOMUXC 模块基地址 */
#define IOMUXC_BASE ((IOMUXC_Type *)0x020E0000)

/* GPIO 模块基地址 */
#define GPIO1_BASE  ((GPIO_Type *)0x0209C000)
#define GPIO5_BASE  ((GPIO_Type *)0x020AC000)

/* ——— CCM 寄存器结构体 ——— */
typedef struct {
    volatile uint32_t CCR;
    volatile uint32_t CCDR;
    volatile uint32_t CSR;
    volatile uint32_t CCSR;
    volatile uint32_t CACRR;
    volatile uint32_t CBCDR;
    volatile uint32_t CBCMR;
    volatile uint32_t CSCMR1;
    volatile uint32_t CSCMR2;
    volatile uint32_t CSCDR1;
    volatile uint32_t CS1CDR;
    volatile uint32_t CS2CDR;
    volatile uint32_t CDCDR;
    volatile uint32_t CHSCCDR;
    volatile uint32_t CSCDR2;
    volatile uint32_t CSCDR3;
    volatile uint32_t RESERVED0[8];
    volatile uint32_t CDHIPR;
    volatile uint32_t RESERVED1[2];
    volatile uint32_t CLPCR;
    volatile uint32_t CISR;
    volatile uint32_t CIMR;
    volatile uint32_t CCOSR;
    volatile uint32_t CGPR;
    volatile uint32_t CCGR0;
    volatile uint32_t CCGR1;
    volatile uint32_t CCGR2;
    volatile uint32_t CCGR3;
    volatile uint32_t CCGR4;
    volatile uint32_t CCGR5;
    volatile uint32_t CCGR6;
    volatile uint32_t RESERVED2[1];
    volatile uint32_t CMEOR;
} CCM_Type;

/* ——— IOMUXC 寄存器结构体（简化：只含 LED 用到的引脚） ——— */
typedef struct {
    volatile uint32_t RESERVED0[26];                    /* 0x0000 ~ 0x0064 */
    volatile uint32_t SW_MUX_CTL_PAD_GPIO1_IO03;        /* 0x0068 */
    volatile uint32_t SW_MUX_CTL_PAD_GPIO1_IO04;        /* 0x006C */
    volatile uint32_t RESERVED1[162];                   /* 填充到 PAD_CTL 区间 */
    volatile uint32_t SW_PAD_CTL_PAD_GPIO1_IO03;        /* 0x02F4 */
    volatile uint32_t SW_PAD_CTL_PAD_GPIO1_IO04;        /* 0x02F8 */
} IOMUXC_Type;

/* ——— GPIO 寄存器结构体 ——— */
typedef struct {
    volatile uint32_t DR;        /* 0x00 数据 */
    volatile uint32_t GDIR;      /* 0x04 方向 */
    volatile uint32_t PSR;       /* 0x08 状态 */
    volatile uint32_t ICR1;      /* 0x0C 中断控制1 */
    volatile uint32_t ICR2;      /* 0x10 中断控制2 */
    volatile uint32_t IMR;       /* 0x14 中断屏蔽 */
    volatile uint32_t ISR;       /* 0x18 中断状态 */
    volatile uint32_t EDGE_SEL;  /* 0x1C 边沿选择 */
} GPIO_Type;

#endif
