#makfile configuration

COMMON_OBJECTS =
CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include
LDFLAGS = -L/opt/ti/msp430_gcc/include

#switch compiler (for internal make rules)
CC = msp430-elf-gcc
AS = msp430-elf-as

all: buzzer.elf

#additional rules

buzzer.elf: ${COMMON_OBJECTS} buzzer.o main.o buzzer.o wdInterruptHandler.o p2.interrupt_handler.o led.o switches.o main.o ../lib/libTimer.a

	${CC} ${CFLAGS} - o $@ $^

load: buzzer.elf
	msp430loader.sh $^

clean: $^
	rm -f *.o *.elf *.h~ *.c~ *.~
