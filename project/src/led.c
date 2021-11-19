#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char red = 0, green = 0, change = 0;
static char red_value[] = {0,LED_RED}, value_green[] = {0,LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;
  change = 1;
  led_update();
}

void led_update()
{
  if(change) {
    char led = red_value[red] | value_green[green];
    P1OUT  &= ~LEDS;
    P1OUT |= led;
    change = 0;
  }
}
