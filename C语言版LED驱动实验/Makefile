CROSS_COMPILE ?= arm-linux-gnueabihf-

CC      = $(CROSS_COMPILE)gcc
LD      = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump

TARGET = led
OBJS   = startup.o main.o

all: $(TARGET).bin

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary -g -S $(TARGET).elf $(TARGET).bin
	$(OBJDUMP) -D $(TARGET).elf > $(TARGET).dis

$(TARGET).elf: $(OBJS)
	$(LD) -Ttext 0x87800000 $(OBJS) -o $(TARGET).elf

%.o: %.s
	$(CC) -g -c $< -o $@

%.o: %.c
	$(CC) -g -c $< -o $@

.PHONY: clean
clean:
	rm -rf *.o $(TARGET).elf $(TARGET).bin $(TARGET).dis
