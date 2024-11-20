#ifndef PIN_H_
#define PIN_H_
#include <avr/io.h>
#include <stdint.h>
#include "Button.h"
#include "EventManager.h"
#include "HD44780.h"
#include "Adc.h"
#include "Timer1.h"
#include "WordsFunctions.h"

#define PIN_DIRECTION_OUTPUT (1)
#define PIN_DIRECTION_INPUT (0)

#define PIN_LEVEL_OFF (0)
#define PIN_LEVEL_ON (1)

#define PORT_DIRECTION_OUTPUT (0xFF)

void configPorts(void);
void configurations();
uint8_t getPinState(uint8_t pin_register, uint8_t position);

#endif /* PIN_H_ */