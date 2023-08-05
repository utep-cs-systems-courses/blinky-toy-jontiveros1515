#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

int main() {
    configureClocks();
    enableWDTInterrupts();
 
    buzzer_init();
    buzzer_set_period(1000); /* start buzzing!!! 2MHz/1000 = 2kHz*/

    or_sr(0x18);          // CPU off, GIE on
}

int period = 300;
int secondCount = 0;

void
__interrupt_vec(WDT_VECTOR) WDT()
{
  secondCount++;
  if (secondCount > 67){
    secondCount = 0;
    period += 500;
  }
  buzzer_set_period(period);

  if (period >= 3000)
    period = 500;
}
