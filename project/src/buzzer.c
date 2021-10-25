#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init() {
  P2SEL &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}
