#include <msp430.h>

#include "switches.h"

#include "stateMachines.h"

#include "buzzer.h"

#include "led.h"



char state1, state2, state3,state4,switch_state_changed;



static char switch_update_interrupt_sense()

{

  char p2val = P2IN;

  P2IES |= (p2val & SWITCHES); // if the switch is up the sense is down

  P2IES &= (p2val | ~SWITCHES);//if it's down the snese is up

  return p2val;

}




//to set up the switch

void switch_init()



{

  P2REN |= SWITCHES; 

  P2IE = SWITCHES; 
  P2OUT |= SWITCHES;

  P2DIR &= ~SWITCHES;

  switch_update_interrupt_sense();



  led_update();

}



void switch_interrupt_handler()

{



  //switches in the toy

  char p2val = switch_update_interrupt_sense();



  state1 = (p2val & SW1) ? 0 : SW1;

  state2 = (p2val & SW2) ? 0 : SW2;

  state3 = (p2val & SW3) ? 0 : SW3;

  state4 = (p2val & SW4) ? 0 : SW4;



  //to play the song
  if(state1){

    sound();

  }


  if(state2){



    enableWDTInterrupts(); // turns on leds



  }

  

  if(state3){

    enableWDTInterrupts();

    buzzer_set_period(1000);



  }



  if(state4){

    greenOn();

    buzzer_set_period(800);

  }



}
