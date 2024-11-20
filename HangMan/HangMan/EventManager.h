#ifndef EVENTMANAGER_H_
#define EVENTMANAGER_H_
#include <avr/io.h>
#include <stdint.h>
#include "Button.h"

#define BUTTON1_EVENT (1u)
#define BUTTON2_EVENT (2u)
#define BUTTON3_EVENT (4u)
#define BUTTON4_EVENT (8u)

void setEvent(uint8_t event_nr);
uint8_t getEvent();
void clearEvents();

#endif /* EVENTMANAGER_H_ */