CC=arm-none-eabi-gcc
ELF= arm-none-eabi-readelf
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -Wall -std=gnu11 -O0
INC= -Iinclude/
LD= -nostdlib -T stm32_ls.ld
LDS= -T stm32_ls.ld

all:startup.o main.o
	$(CC) $(LD) *.o -Wl,-Map=final.map -o final.elf
	$(ELF) -all final.elf > elf_dump.elfd

startup.o: startup.c
	$(CC) $(CFLAGS) $(INC) $@ $^

main.o: main.c
	$(CC) $(CFLAGS) $(INC) $@ $^

task.o: task.c
	$(CC) $(CFLAGS) $(INC) $@ $^

clean:
	del *.o *.elf *.map *.elfd