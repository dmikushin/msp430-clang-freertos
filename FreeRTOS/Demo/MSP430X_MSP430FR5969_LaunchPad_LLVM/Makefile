CLANG = clang -fheinous-gnu-extensions -Oz
#CLANG = msp430-elf-gcc -Os
CFLAGS = -mmcu=msp430fr5969 -ffunction-sections -fdata-sections -I. -I../../Source/include -I../../Demo/Common/include -Idriverlib/MSP430FR5xx_6xx -I/opt/ti/ccsv8/ccs_base/msp430/include_gcc -I../../Source/portable/GCC/MSP430X -I../../../FreeRTOS-Plus/Demo/Common/FreeRTOS_Plus_CLI_Demos -I../../../FreeRTOS-Plus/Source/FreeRTOS-Plus-CLI
LD = msp430-elf-gcc

GCC_LIBINC = /home/marcusmae/acctek/msp430-gcc-7.3.2.154_linux64/lib/gcc/msp430-elf/7.3.2
LDFLAGS = -mhwmult=f5series -Wl,--defsym=__idle_stack_size__=0x100,--gc-sections,--no-warn-mismatch,--script=msp430fr5969.ld

FREERTOS_OBJS = list.o queue.o timers.o
PORTABLE_OBJS = port.o portext.o
MEMALLOC_OBJS = heap_4.o

DEVICE_SRCS = gpio.c wdt_a.c cs.c pmm.c
DEVICE_OBJS = $(DEVICE_SRCS:.c=.o)

COMMON_SRCS = $(filter-out EventGroupsDemo.c, $(filter-out comtest_strings.c, $(filter-out sp_flop.c, $(filter-out crhook.c, $(filter-out IntQueue.c,$(shell cd ../Common/Minimal/ && ls *.c))))))
COMMON_OBJS = $(COMMON_SRCS:.c=.o)

OBJS = $(FREERTOS_OBJS) $(PORTABLE_OBJS) $(MEMALLOC_OBJS) $(DEVICE_OBJS) $(COMMON_OBJS)

LD_SCRIPTS = msp430fr5969.ld msp430fr5969_symbols.ld

$(info $(FREERTOS_OBJS))

all: blinky_demo full_demo

blinky_demo: main_blinky.o Blinky_Demo/main_blinky.o tasks_blinky.o LEDs.o printf-stdarg.o $(OBJS) $(LD_SCRIPTS)
	$(LD) $(LDFLAGS) $(filter %.o, $^) -o $@ -L$(GCC_LIBINC) && \
	msp430-elf-size $@

full_demo: main_full.o Full_Demo/main_full.o tasks_full.o Full_Demo/serial.o LEDs.o printf-stdarg.o \
	EventGroupsDemo.o event_groups.o UARTCommandConsole.o FreeRTOS_CLI.o Sample-CLI-commands.o RegTest.o \
	$(OBJS) $(LD_SCRIPTS)
	$(LD) $(LDFLAGS) $(filter %.o, $^) -o $@ -L$(GCC_LIBINC) && \
	msp430-elf-size $@

main_blinky.o: main.c
	$(CLANG) -DmainCREATE_SIMPLE_BLINKY_DEMO_ONLY=1 $(CFLAGS) -c $< -o $@

Blinky_Demo/main_blinky.o: Blinky_Demo/main_blinky.c
	$(CLANG) $(CFLAGS) -c $< -o $@

main_full.o: main.c
	$(CLANG) $(CFLAGS) -c $< -o $@

Full_Demo/main_full.o: Full_Demo/main_full.c
	$(CLANG) $(CFLAGS) -c $< -o $@

Full_Demo/serial.o: Full_Demo/serial.c
	$(CLANG) $(CFLAGS) -c $< -o $@

%.o: ../../Source/%.c
	$(CLANG) $(CFLAGS) -c $< -o $@

tasks_blinky.o: ../../Source/tasks.c
	$(CLANG) -DmainCREATE_SIMPLE_BLINKY_DEMO_ONLY=1 $(CFLAGS) -c $< -o $@

tasks_full.o: ../../Source/tasks.c
	$(CLANG) $(CFLAGS) -c $< -o $@

%.o: ../../Source/portable/GCC/MSP430X/%.c
	$(CLANG) $(CFLAGS) -c $< -o $@

portext.o: ../../Source/portable/GCC/MSP430X/portext.S
	msp430-elf-gcc $(CFLAGS) -c $< -o $@

RegTest.o: RegTest.S
	msp430-elf-gcc $(CFLAGS) -c $< -o $@

%.o: ../../Source/portable/MemMang/%.c
	$(CLANG) $(CFLAGS) -c $< -o $@

%.o: driverlib/MSP430FR5xx_6xx/%.c
	$(CLANG) $(CFLAGS) -c $< -o $@

%.o: ../Common/Minimal/%.c
	$(CLANG) $(CFLAGS) -c $< -o $@

%.o: ../../../FreeRTOS-Plus/Demo/Common/FreeRTOS_Plus_CLI_Demos/%.c
	$(CLANG) $(CFLAGS) -c $< -o $@

%.o: ../../../FreeRTOS-Plus/Source/FreeRTOS-Plus-CLI/%.c
	$(CLANG) $(CFLAGS) -c $< -o $@

%.o: ../../../FreeRTOS-Plus/Demo/Common/FreeRTOS_Plus_CLI_Demos/%.c
	$(CLANG) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CLANG) $(CFLAGS) -c $< -o $@

clean:
	rm -rf blinky_demo full_demo *.o Blinky_Demo/*.o Full_Demo/*.o

