#include <msp430.h>
#include "stateMachine.h"

void __interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count == 1) {
    nextState();
    blink_count = 0;
  }
}
