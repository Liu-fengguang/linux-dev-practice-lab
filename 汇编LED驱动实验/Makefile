CROSS_COMPILE ?= arm-linux-gnueabihf-
CC  = $(CROSS_COMPILE)gcc
LD  = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump

TARGET = led
OBJS   = startup.o led.o

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@
	$(OBJDUMP) -D $(TARGET).elf > $(TARGET).dis

$(TARGET).elf: $(OBJS)
	$(LD) -Tled.lds $^ -o $@

%.o: %.s
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o *.elf *.bin *.dis
