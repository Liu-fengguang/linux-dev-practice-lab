# 汇编LED驱动实验

i.MX6ULL 上第一个裸机实验：用汇编语言点亮 LED。

## 实验原理

LED 接在 GPIO1_IO03（对应开发板 LED0），通过以下步骤控制：

| 步骤 | 寄存器 | 操作 |
|------|--------|------|
| 1. 使能时钟 | CCM_CCGR1 | 使能 GPIO1 时钟 |
| 2. 配置功能 | IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 | 设为 GPIO 模式 |
| 3. 配置属性 | IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03 | 电气属性 |
| 4. 设为输出 | GPIO1_GDIR | 第 3 位置 1 |
| 5. 输出电平 | GPIO1_DR | 第 3 位置 1 灭，清 0 亮 |

## 寄存器地址 (IMX6ULL)

| 寄存器 | 地址 |
|--------|------|
| CCM_CCGR1 | 0x020C406C |
| IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 | 0x020E0068 |
| IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03 | 0x020E02F4 |
| GPIO1_DR | 0x0209C000 |
| GPIO1_GDIR | 0x0209C004 |

## 文件说明

| 文件 | 作用 |
|------|------|
| `startup.s` | 启动文件，设置栈，跳转 main |
| `led.s` | LED 初始化与闪烁逻辑 |
| `Makefile` | 编译与链接 |
| `led.lds` | 链接脚本 |

## 编译与烧写

```bash
# 编译
make

# 生成文件
# led.bin — 烧入 SD 卡的裸机程序
# led.elf — 调试用
# led.dis — 反汇编，用于分析
```

> 裸机程序烧写到 SD 卡后，开发板设为 SD 卡启动，上电即可看到 LED 闪烁。
