#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

extern char switch_pressed;
int count = 0;

void
__interrupt_vec(WDT_VECTOR) WDT()
{
  switch(switch_pressed) {
  case 0:
    if(++count == 125) {
      state_advance();
      count = 0;
    }
    break;
  case 1:
    if((++count % 25== 0)) {
      buzzer_advance();
    }
    if(count == 75) {
      main_state_advance();
      count = 0;
    }
    break;
  case 2:
    button3_siren();
    if(++count == 50) {
      blink_dim();
      count = 0;
    }
    break;
  case 3:
    button4_off();
    break;
  }
}
