#include "Timer1.h"

void config_Timer1_CTC_100us(void)
{
	cli();
		
	TCNT1  = 0;
	TCCR1A = 0;
	TCCR1B = 0;
	TCCR1B |= (1 << WGM12);
	TCCR1B |= (0 << CS12) | (0 << CS11) | (1 << CS10);
	
	/* -------------- Calculate 100 us in HZ --------------
	(interrupt time frequency)
	F = 1s/T => 1s/100us => 1s/0,000100s => 10000Hz
	
	   -------------- Calculate OCR1A --------------
	[F_CPU/(prescaler*F)]-1 => [16000000/(1*10000)]-1 => 1600-1 => 1599
	1599 < 65536 => OK!!
	*/

    OCR1A = 1599;
	TIMSK |= (1 << OCIE1A);
	
	sei();
}

ISR(TIMER1_COMPA_vect)
{
	timer1_flag_100us = 1;
}