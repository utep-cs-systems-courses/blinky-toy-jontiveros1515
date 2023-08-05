#include <msp430.h>
#include "led.h"
#include "stateMachine.h"

void updateState(int state){
 
  switch(state){
  case 0:
    P1OUT ^= LED_GREEN;
    break;
  
  case 1:
    P1OUT ^= LED_RED;
    break;

  case 2:
    P1OUT &= ~LED_RED;
    P1OUT &= ~LED_GREEN;
    break;

  case 3:
    P1OUT |= LED_RED;
    P1OUT |= LED_GREEN;
    break;
  }
}
    
