COMMON_OBJECTS	= main.o
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include


CC		= msp430-elf-gcc
AS		= msp430-elf-as

all: button.elf
button.elf: ${COMMON_OBJECTS} main.o led.o stateMachine.o switches.o buzzer.o buzzerStateMachine.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	msp430loader.sh $^

led.o: led.h led.c

stateMachine.o: stateMachine.c stateMachine.h

switches.o: switches.h switches.c 

buzzer.o: buzzer.h buzzer.c

buzzerStateMachine.o: buzzerStateMachine.c buzzerStateMachine.h

clean:
	rm -f *.o *.elf
