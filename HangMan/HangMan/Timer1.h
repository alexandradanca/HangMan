#ifndef TIMER1_H_
#define TIMER1_H_
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

extern volatile uint8_t timer1_flag_100us;

void config_Timer1_CTC_100us(void);

#endif /* TIMER1_H_ */