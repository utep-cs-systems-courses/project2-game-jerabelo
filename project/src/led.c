#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LEDS;
  led_update();
}

void led_update()
{
  P1OUT &= ~LEDS;
}

void red_on(int on)
{
  if(on == 0) {
    P1OUT &= ~LED_GREEN;
  } else if(on == 1) {
    P1OUT |= ~LEDS;
  }
}

void green_on(int on)
{
  if(on == 0) {
    P1OUT |= LED_GREEN;
  } else if(on == 1) {
    P1OUT |= LED_GREEN;
  }
}

void leds_on(int on) {
  if(on == 0) {
    P1OUT &= ~LEDS;
  } else if (on == 1) {
    P1OUT |= LEDS;
  }
}

void alt_leds(int on) {
  switch(on) {
  case 0:
    red_on(1);
    green_on(0);
    break;
  case 1:
    red_on(1);
    green_on(1);
    break;
  default:
    leds_on(0);
    break;
  }
}
