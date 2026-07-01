# 蜂鸣器实验

## 硬件

| 项目 | 说明 |
|------|------|
| 控制 IO | `SNVS_TAMPER1` → 复用为 `GPIO5_IO01` |
| 高电平 | 蜂鸣器关闭 |
| 低电平 | 蜂鸣器打开 |

## 寄存器

| 寄存器 | 地址 |
|--------|------|
| `IOMUXC_SW_MUX_CTL_PAD_SNVS_TAMPER1` | `0x0229000C` |
| `IOMUXC_SW_PAD_CTL_PAD_SNVS_TAMPER1` | `0x02290058` |
| `GPIO5_GDIR` | `0x020AC004` |
| `GPIO5_DR` | `0x020AC000` |

## 文件

| 文件 | 作用 |
|------|------|
| `main.c` | 蜂鸣器初始化 + 响停控制 |
| `bsp_beep.c/h` | 蜂鸣器驱动 |
| `bsp_clk.c/h` | 时钟使能 |
| `bsp_delay.c/h` | 延时函数 |
