#ifndef BUTTON_H_
#define BUTTON_H_
#include <avr/io.h>
#include <stdint.h>

#include "Pin.h"

#define BUTTON_PRESSED 0
#define BUTTON_RELEASED 1u
#define DEBOUNCE_SAMPLES 4


typedef struct
{
	volatile unsigned char * direction_register;
	volatile unsigned char * pin_register;
	unsigned char pin_position;
	unsigned char pin_state_hw_old;
	unsigned char pin_state_hw_new;
	unsigned char pin_state_sw_old;
	unsigned char pin_state_sw_new;
	unsigned char counterDebounce;
	unsigned char event_number;
}Button;

extern Button button1;
extern Button button2;
extern Button button3;
extern Button button4;

void init_button(Button *btn, volatile uint8_t* ddrX, volatile uint8_t* pinX, uint8_t pos, uint8_t state_hw_old,
uint8_t state_hw_new, uint8_t state_sw_old, uint8_t state_sw_new, uint8_t counter, uint8_t event_button);

void pull_up_active(uint8_t poz_min, uint8_t poz_max, volatile uint8_t* portX);
void debounce(Button* btn);
void debounce_all_buttons(void);

#endif /* BUTTON_H_ */