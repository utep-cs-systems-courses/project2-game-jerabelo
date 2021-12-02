#include <msp430.h>
#include "switches.h"
#include "stateMachine.h"
#include "led.h"

static char check_switches() {
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES); /* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES); /* if switch down, sense up */
  return p2val;
}

void switch_init() { /* setup switch */
  P2REN |= SWITCHES; /* enables resistor */
  P2IE |= SWITCHES; /* enable interrupts from switches */
  P2OUT |= SWITCHES; /* pull-ups for switches */
  P2DIR &= ~SWITCHES; /*set switch bits for inputs */
}

void handle_switches() {
  char p2val = check_switches();
  char state = (p2val & SW1) ? 0 : 1;
  if (state == 0) state = (p2val & SW2) ? 0 : 2;
  if (state == 0) state = (p2val & SW3) ? 0 : 3;
  if (state == 0) state = (p2val & SW4) ? 0 : 4;
  stateChange(state);
} 
