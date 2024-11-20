#ifndef ADC_H_
#define ADC_H_

#include <avr/interrupt.h>

extern volatile uint8_t flag_ADC;

void configADC(void);
uint16_t ADC_read(uint8_t channel);

#endif /* ADC_H_ */