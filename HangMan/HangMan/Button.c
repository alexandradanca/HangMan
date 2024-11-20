#include "Button.h"
#include "EventManager.h"

Button button1;
Button button2;
Button button3;
Button button4;

void init_button(Button *btn, volatile uint8_t* ddrX, volatile uint8_t* pinX, uint8_t pos, uint8_t state_hw_old,
uint8_t state_hw_new, uint8_t state_sw_old, uint8_t state_sw_new, uint8_t counter, uint8_t event_button )
{
	btn->direction_register = ddrX;
	btn->pin_register = pinX;
	btn->pin_position = pos;
	*ddrX &= ~(1 << pos);
	btn->pin_state_hw_old = state_hw_old;
	btn->pin_state_hw_new = state_hw_new;
	btn->pin_state_sw_old = state_sw_old;
	btn->pin_state_sw_new = state_sw_new;
	btn->counterDebounce = counter;
	btn->event_number = event_button;
}

void pull_up_active(uint8_t poz_min, uint8_t poz_max, volatile uint8_t* portX)
{
	uint8_t i;
	
	for (i=poz_min; i<poz_max; i++)
	{
		*portX |= (1<< i);
	}
}

void debounce(Button* btn)
{
	if (((*btn->direction_register>>btn->pin_position) &1)== PIN_DIRECTION_INPUT)
	{
		btn->pin_state_hw_old =btn->pin_state_hw_new;
		btn->pin_state_hw_new = getPinState(*btn->pin_register,btn->pin_position);
		btn->pin_state_sw_old=btn->pin_state_sw_new;

		if (btn->pin_state_hw_old == btn->pin_state_hw_new)
		{
			if (btn->counterDebounce < DEBOUNCE_SAMPLES)
			{
				(btn->counterDebounce)++;
			}
			if(btn->counterDebounce  == DEBOUNCE_SAMPLES)
			{
				btn->pin_state_sw_new = btn->pin_state_hw_new;
			}
		}
		else
		{
			btn->counterDebounce  = 1;
		}
		
		if( (btn->pin_state_sw_old == BUTTON_PRESSED) && (btn->pin_state_sw_new == BUTTON_RELEASED))
		{
			setEvent(btn->event_number);
		}
	}
}

void debounce_all_buttons(void)
{
	debounce(&button1);
	debounce(&button2);
	debounce(&button3);
	debounce(&button4);

}