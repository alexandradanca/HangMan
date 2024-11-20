#include "Pin.h"

void configPorts(void)
{

	init_button(&button1, &DDRD, &PIND, 0, BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED, 0, BUTTON1_EVENT);
	init_button(&button2, &DDRD, &PIND, 1, BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED, 0, BUTTON2_EVENT);
	init_button(&button3, &DDRD, &PIND, 2, BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED, 0, BUTTON3_EVENT);
	init_button(&button4, &DDRD, &PIND, 3, BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED, 0, BUTTON4_EVENT);

	pull_up_active(0,4,(uint8_t*)&PORTD);
}

void configurations()
{
	configPorts();
	configADC();
	LCD_Initalize();
	LCD_Clear();
	config_Timer1_CTC_100us();
	random_guess_number();
}

uint8_t getPinState(uint8_t pin_register, uint8_t position)
{
	return ((pin_register >> position) & 1);
}


