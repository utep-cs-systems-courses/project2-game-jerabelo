#include <msp430.h>
#include "switches.h"
#include "led.h"

char switch_state_down, switch_state_changed;
char switch_pressed;

statis char
switch_update_interrupt_sense()
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
  switch_update_interrupt_sense();
  led_update();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  if(p2val & S1 == 0)
    {
      switch_pressed = 0;
    } else if (p2val & S2 == 0) {
    switch_pressed = 1;
  } else if (p2va & S3 == 0) {
    switch_pressed = 2;
  } else if (p2val & S4 == 0) {
    switch_pressed = 3;
  }
  switch_state_down = !switch_state_down;
  switch_state_changed = switch_state_changed;
  led_update();
}
