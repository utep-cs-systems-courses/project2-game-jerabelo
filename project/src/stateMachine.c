#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "buzzer.h"
#include "songNotes.h"

static int sunandmoon[26]  = {E7,D6,CS5,CS5,CS5,CS5,CS5,CS5,E7,FS1,CS5,E7,E7,A3,E7,D6,CS5,B4,CS5,A3,A3,E7,D6,CS5,B4,A3};
static int buzzer = 2637; static int beepOne = 3600; static int beepTwo = 2000;
int currNote = 0;
char button = 0;

void stateOne() {
  static int greenState = 0;
  green = 0, red = 1;
  buzzer_set_period(buzzer);

  switch(greenState) {
  case 0: greenState++; green = 1;
  case 1: greenState++; green = 0;
  case 2: greenState++; green = 0;
  case 3: greenState++; green = 0;
  case 4: greenState++; green = 0;
  }
}

void stateTwo() {
  static int timer = 0; static int stop = 0; static int pitch = 134;
  green = 1, red = 0;
  if (currNote < 26) {
    buzzer_set_period(2000000/sunandmoon[currNote]);
    currNote++;
  } else {
    currNote = 0;
  }
}

void stateThree() {
  green = 1, red = 1;
  if(beepOne < 6000){
    buzzer_set_period(2000000/beepOne);
    beepOne++;
  } else {
    beepOne = 3600;
  }
}

void offState(){
  buzzer_set_period(0);
  red = 0, green = 0;
}

void stateChange(char state) {
  switch(state) {
  case 1: button = 1; break;
  case 2: button = 2; break;
  case 3: button = 3; break;
  case 4: button = 4; break;
  }
}

void nextState() {
  char changed = 0;
  switch(button) {
  case 1: stateOne(); changed = 1; break;
  case 2: stateTwo(); changed = 1; break;
  case 3: stateThree(); changed = 1; break;
  case 4: offState();changed = 1;
  }
  change = changed;
  led_update();
}

