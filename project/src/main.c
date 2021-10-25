#include <msp430.h>
#include "led.h"
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"

int main(void) {
  configureClocks();
  switch_init();
  buzzer_init();
  enableWDTInterrupts();
  or_sr(0x18);
  
}
