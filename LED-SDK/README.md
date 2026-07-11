# LED — SDK 移植实验

将 NXP SDK 移植到 LED 实验，用结构体指针 + API 函数替代手写寄存器操作。

## 核心变化

| 原来（纯寄存器） | 现在（SDK） |
|-----------------|------------|
| `(*(volatile uint32_t *)0x0209C004) \|= (1<<3)` | `GPIO_PinInit(GPIO1_BASE, 3, &config)` |
| `(*(volatile uint32_t *)0x0209C000) &= ~(1<<3)` | `GPIO_PinWrite(GPIO1_BASE, 3, 0)` |

## 移植文件

```
sdk/
├── imx6ull.h          ← 寄存器结构体（CCM/IOMUXC/GPIO）
├── fsl_common.h       ← 通用宏 + 枚举
├── fsl_iomuxc.h/c     ← IO 复用 API
└── fsl_gpio.h/c       ← GPIO API（PinInit + PinWrite）
```

## SDK 函数源码解读

`GPIO_PinWrite` 内部就是 `base->DR &= ~(1U << pin)` —— 和你手写的一样，只是包了层函数名。

> SDK 不是魔法，是封装。理解封装就能从"用别人的代码"进阶到"写自己的 SDK"。
