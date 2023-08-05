#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "stateMachine.h"
#include "switches.h"
#include "buzzer.h"
#include "buzzerStateMachine.h"

void main(void){
  configureClocks();
  init();
  initSwitches();
  buzzer_init();
  //  buzzer_set_period(5000);
  enableWDTInterrupts();

  or_sr(0x18);
}

void __interrupt_vec(WDT_VECTOR) WDT(){
  secondCount++;
  buzz();
}
