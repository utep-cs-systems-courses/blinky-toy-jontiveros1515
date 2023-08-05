#include <msp430.h>
#include "led.h"
#include "stateMachine.h"


void init(){
  P1DIR |= LEDS;
  updateState();
}
    
