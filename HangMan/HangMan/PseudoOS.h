#ifndef PSEUDOOS_H_
#define PSEUDOOS_H_
#include <avr/io.h>
#include "HD44780.h"
#include "Pin.h"
#include "WordsFunctions.h"
#include "Button.h"
#include "EventManager.h"
#include "StateMachines.h"
#include "Display.h"
#include "Adc.h"

void task_1ms(void);
void task_5ms(void);

#endif /* PSEUDOOS_H_ */