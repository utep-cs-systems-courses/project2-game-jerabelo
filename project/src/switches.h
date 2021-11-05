#ifndef switches_included
#define switches_included

#define S1 BIT0
#define S2 BIT1
#define S3 BIT2
#define S4 BIT3

#define SWITCHES (S1 | S2 | S3 | S4)

void switch_init();
void switch_interrupt_handler();

extern int switch_state_down1, switch_state_down2, switch_state_down3, switch_state_down4;
extern int press1, press2, press3, press4;

#endif
