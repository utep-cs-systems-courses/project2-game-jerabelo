#makfile config

COMMON_OBJECTS	=
CPU	= msp430g2553
CFLAGS	= -mmcu=${CPU} -I../h
LDFLAGS	= -L/opt/ti/msp430_gcc/include

#switch compiler for internal make rules
CC	= msp430-elf-gcc
AS	= msp430-elf-as

all:	play.elf
#additional rules for files

play.elf: ${COMMON_OBJECTS} main.o stateMachine.o led.o wdInterruptHandler.o switches.o buzzer.o p2_interrupt_handler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load:	play.elf
	msp430loader.sh play.elf

clean:
	rm -f *.o *.elf

main.o:	led.c switches.h buzzer.h main.c

led.o:	led.c led.h

wdInterruptHandler.o:	stateMachine.h

p2_interrupt_Handler.o:	switches.h

stateMachine.o:	led.h stateMachine.h

switches.o:	switches.h switches.c

buzzer.o:	buzzer.h

sondNotes.o:	songNotes.h
