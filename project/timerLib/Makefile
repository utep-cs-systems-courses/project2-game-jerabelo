all: libTimer.a

CPU	= msp430g2553
CFLAGS	= -mmcu=${CPU}

CC	= msp430-elf-gcc
AS	= msp430-elf-as
AR	= ms430-elf-ar

libTimer.a: clocksTimer.o sr.o
	$(AR) crs $@ $^

install: libTimer.a
	mkdir -p ../ ../lib
	mv $^ ../lib
	cp*.h ../h
clean:
	rm -f timerLib.a *.o
