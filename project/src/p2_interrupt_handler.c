#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "led.h"

char switch_pressed = 3;

void
__interrupt_vec(PORT2_VECTOR) Port_2() {
  if(P2IFG & SWICHES) {
    P2IFG &= ~SWITCHES;
    switch_interrupt_hander();
  }
}
