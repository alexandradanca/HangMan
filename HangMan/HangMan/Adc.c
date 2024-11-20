#include "Adc.h"

volatile uint8_t flag_ADC = 0;

void configADC(void)
{
	ADMUX = 0; 
	ADMUX |= 1<<REFS0;  
	ADCSRA = 0;
	ADCSRA |= ((1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0));
	ADCSRA |= 1<<ADEN;
	
}

uint16_t ADC_read(uint8_t channel)
{
	ADMUX &= 0xF8;
	ADMUX |= channel;
	ADCSRA |= 1<<ADSC;
	while ((ADCSRA & (1<<ADIF)) == 0)
	{
		//wait here till conversion is complete
	}
	return ADC;
}


