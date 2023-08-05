#ifndef led_included
#define led_included

#define LED_GREEN BIT0
#define LED_RED BIT6
#define LEDS (BIT0 | BIT6)

#define P1_SWITCH BIT3
#define SW0 BIT0
#define SW1 BIT1
#define SW2 BIT2
#define SW3 BIT3
#define SWITCHES (SW0 | SW1 | SW2 | SW3)


void init();

#endif
