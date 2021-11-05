#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "songNotes.h"

int toggle_red = 0;
int toggle_green = 0;

void red_dim25()
{
  switch(toggle_red) {
  case 0:
    red_on(0);
    toggle_red++;
  case 1:
    toggle_red++;
  case 2:
    toggle_red++;
      break;
  case 3:
    red_on(1);
    toggle_red = 0;
    break;
  default:
    break;
  }
}

void red_dim50()
{
  switch(toggle_red) {
  case 0:
    red_on(1);
    toggle_red++;
    break;
  case 1:
    red_on;
    toggle_red++;
    break;
  case 2:
    toggle_red++;
    break;
  case 3:
    red_on(0);
    toggle_red++;
  default:
    break;
  }
}

void red_dim75()
{
  switch(toggle_red) {
  case 0:
    red_on(0);
    toggle_red++;
    break;
  case 1:
    toggle_red++;
    break;
  case 2:
    toggle_red++;
    break;
  case 3:
    red_on(1);
    toggle_red = 0;
    break;
  default:
    break;
  }
}

void green_dim25()
{
  switch (toggle_green){
  case 0:
    green_on(0);
    toggle_green++;
  case 1:
    toggle_green++;
  case 2:
    toggle_green++;
    break;
  case 3:
    green_on(1);
    toggle_green = 0;
    break;
  default:
    break;
  }
}

void green_dim50()
{
  switch (toggle_green){
  case 0:
    green_on(1);
    toggle_green++;
    break;
  case 1:
    green_on(0);
    toggle_green++;
    break;
  case 2:
    toggle_green++;
    break;
  case 3:
    green_on(1);
    toggle_green = 0;
  default:
    break;
  }
}

void play_song()
{
  char currNote = 0;  // Keep track of state
  int sunandmoon[6] = {E7,D6,CS5,FS1,A3,B4};
  int n = 15;
  if (currNote < n){
    buzzer_set_period(sunandmoon[currNote]);
    currNote++;
  } else{
    currNote = 0;
  }
}

void green_dim75()
{
  switch(toggle_green){
  case 0:
    green_on(0);
    toggle_green++;
    break;
  case 1:
    toggle_green++;
    break;
  case 2:
    toggle_green++;
    break;
  case 3:
    green_on(1);
    toggle_green = 0;
    break;
  default:
    break;
  }
}
