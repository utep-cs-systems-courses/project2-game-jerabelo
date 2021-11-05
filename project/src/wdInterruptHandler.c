#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

int press1 = 0;
int press2 = 0;
int press3 = 0;
int press4 = 0;

void __interrupt_vec(WDT_VECTOR) WDT()
{
  int count = 0;
  count++;
  if((count % 63 == 0) && press1 == 1){
    led_update();
    play_song();
  } else if((count % 31) == 0 && press1 == 1) {
    led_update();
    play_song();
    count = 0;
  } else if((count % 63) == 0 && press3 == 1) {
    led_update();
    play_song();
    count = 0;
  } else if((count % 125) == 0 && press4 == 1) {
    buzzer_set_period(0);
    // dim_sequence();
    count = 0;
  }
}
