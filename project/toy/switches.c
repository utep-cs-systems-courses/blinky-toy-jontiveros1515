#include <msp430.h>
#include "switches.h"
#include "stateMachine.h"
#include "led.h"
#include "buzzerStateMachine.h"

void initSwitches(){

  P1REN |= P1_SWITCH;
  P1IE |= P1_SWITCH;
  P1OUT |= P1_SWITCH;
  P1DIR &= ~P1_SWITCH;

  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;

}

int switch_interrupt_handler(){
  char P2VAL = P2IN;

  P2IES |= ( P2VAL & SWITCHES );
  P2IES |= ( P2VAL | ~SWITCHES);

  if (!(P2VAL & SW0)){
    return 0;
  }
  else if (!(P2VAL & SW1)){
    return 1;
  }
  else if (!(P2VAL & SW2)){
    return 2;
  }
  else if(!(P2VAL & SW3)){
    return 3;
  }
}

void p1_switch_interrupt_handler(){
  char p1val = P1IN;
    
  P1IES |= (p1val & P1_SWITCH);
  P1IES |= (p1val | ~P1_SWITCH);
  
  state++;
}

void __interrupt_vec(PORT1_VECTOR) PORT_1(){
  if (P1IFG & P1_SWITCH){
    P1IFG &= ~P1_SWITCH;
    ///////////////////
    p1_switch_interrupt_handler();
  }
}
void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {
    P2IFG &= ~SWITCHES;
    int nextState = switch_interrupt_handler();
    updateState(nextState);
  }
}
