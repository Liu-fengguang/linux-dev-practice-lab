# 交叉编译器前缀，用 ?= 允许命令行覆盖
CROSS_COMPILE ?= arm-linux-gnueabihf-

CC      = $(CROSS_COMPILE)gcc
LD      = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump

TARGET = led
OBJS   = startup.o led.o

all: $(TARGET).bin

# 规则1：.bin 是从 .elf 提纯出来的纯机器码
$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary -g -S $(TARGET).elf $(TARGET).bin
	$(OBJDUMP) -D $(TARGET).elf > $(TARGET).dis

# 规则2：.elf 是链接所有 .o 拼装出来的
# -Ttext 指定代码运行地址 = 链接起始地址
$(TARGET).elf: $(OBJS)
	$(LD) -Ttext 0x87800000 $(OBJS) -o $(TARGET).elf

# 规则3：.o 是从 .s 编译出来的
%.o: %.s
	$(CC) -g -c $< -o $@

# 清理
.PHONY: clean
clean:
	rm -rf *.o $(TARGET).elf $(TARGET).bin $(TARGET).dis
