#ifndef __IMX6ULL_H
#define __IMX6ULL_H

/* CCM 时钟寄存器 */
#define CCM_BASE            (0x020C4000)
#define CCM_CCGR0           (*(volatile unsigned int *)(CCM_BASE + 0x68))
#define CCM_CCGR1           (*(volatile unsigned int *)(CCM_BASE + 0x6C))
#define CCM_CCGR2           (*(volatile unsigned int *)(CCM_BASE + 0x70))
#define CCM_CCGR3           (*(volatile unsigned int *)(CCM_BASE + 0x74))
#define CCM_CCGR4           (*(volatile unsigned int *)(CCM_BASE + 0x78))
#define CCM_CCGR5           (*(volatile unsigned int *)(CCM_BASE + 0x7C))
#define CCM_CCGR6           (*(volatile unsigned int *)(CCM_BASE + 0x80))

/* SNVS_TAMPER1 复用为 GPIO5_IO01 */
#define IOMUXC_SW_MUX_CTL_PAD_SNVS_TAMPER1   (*(volatile unsigned int *)0x0229000C)
#define IOMUXC_SW_PAD_CTL_PAD_SNVS_TAMPER1   (*(volatile unsigned int *)0x02290058)

/* GPIO5 寄存器 */
#define GPIO5_DR    (*(volatile unsigned int *)0x020AC000)
#define GPIO5_GDIR  (*(volatile unsigned int *)0x020AC004)

#endif
