#include <msp430.h>
#include "switches.h"
#include "led.h"

int switch_state_down1 = 0;
int switch_state_down2 = 0;
int switch_state_down3 = 0;
int switch_state_down4 = 0;

char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void switch_init()
{
  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
  led_update();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  int state_previous1 = switch_state_down1;
  int state_previous2 = switch_state_down2;
  int state_previous3 = switch_state_down3;
  int state_previous4 = switch_state_down4;
  
  switch_state_down1 = (p2val & S1) ? 0 : 1;
  switch_state_down2 = (p2val & S2) ? 0 : 1;
  switch_state_down3 = (p2val & S3) ? 0 : 1;
  switch_state_down4 = (p2val & S4) ? 0 : 1;

  if(state_previous1 != switch_state_down1 && switch_state_down1) {
    press1 ^= 1;
    press2 = 0, press3 = 0, press4 = 0;
  } else if(state_previous2 != switch_state_down2 && switch_state_down2) {
    press2 ^= 1;
    press1 = 0, press3 = 0, press4 = 0;
  } else if(state_previous3 != switch_state_down3 && switch_state_down3) {
    press3 ^= 1;
    press1 = 0, press2 = 0, press4 = 0;
  } else if(state_previous4 != switch_state_down4 && switch_state_down4) {
    press4 ^= 1;
    press1 = 0, press2 = 0, press3 = 0;
  }
}
