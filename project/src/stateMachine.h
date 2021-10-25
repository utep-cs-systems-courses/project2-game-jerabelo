#ifndef stateMachine_included
#define stateMachine_included
#define extern global char state

void state_advance();
void up_state();
void down_state();
void button3_sirren();
void button4_off();
void blink_dim();
void buzzer_advance();
void main_state_advance();
#endif
