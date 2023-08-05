#include <msp430.h>
#include "buzzerStateMachine.h"
#include "buzzer.h"
int secondCount = 0;
int state = 4;

void buzz(){
  static int period = 0;
  secondCount++;
  
  if(state > 4)
    state = 0;

  switch(state){
  case 0:
    
    if(secondCount > 67){
      secondCount = 0;
      period += 500;
    }
    buzzer_set_period(period);
    if(period >= 3000)
      period = 500;
    break;
    
  case 1:

    period += 1;
    buzzer_set_period(period);
    if (period >= 1000)
      period = 700;
    
    break;
    
  case 2:

    period += 10;
    buzzer_set_period(period);
    if (period > 4500)
      period = 3000;
    
    break;

  case 3:

    if (secondCount >= 500){
      secondCount = 0;
      buzzer_set_period(3000);
    }
    if (secondCount >= 250){
      buzzer_set_period(0);
    }
    
    break;

  case 4:

    buzzer_set_period(0);
    
    break;
   
  }
}
