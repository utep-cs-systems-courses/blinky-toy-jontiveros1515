#ifndef led_included
#define led_included

#define P1_SWITCH BIT3
#define SW0 BIT0
#define SW1 BIT1
#define SW2 BIT2
#define SW3 BIT3
#define SWITCHES (SW0 | SW1 | SW2 | SW3)

void initSwitches();
int switch_interrupt_handler();
void p1_switch_interrupt_handler();

#endif
