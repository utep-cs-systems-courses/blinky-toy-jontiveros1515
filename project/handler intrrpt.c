#include <msp430.h>

#include "switches.h"



void

__interrupt_vec(PORT2_VECTOR) Port_2(){



  if (P2IFG & SWITCHES) { //button that makes it interumpt

    P2IFG &= ~SWITCHES; 

    switch_interrupt_handler(); //this is a single handler for all the switches

  }

}
