/*
* HangMan.c
*
* Created: 18/07/2022 13:57:15
* Author : alexa
*/

#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "HD44780.h"
#include "Pin.h"
#include "WordsFunctions.h"
#include "Button.h"
#include "EventManager.h"
#include "StateMachines.h"
#include "Display.h"
#include "Adc.h"
#include "PseudoOS.h"
#include "Timer1.h"

volatile uint8_t flag_1ms = 0;
volatile uint8_t timer1_flag_100us = 0;

int main(void)
{
	char *word_database[NUMBER_OF_DATABASE_WORD] = {
	"bananas","strawberries","grapes","apples","watermelon","oranges","blueberries","lemons","peaches","pineapple",
	"potatoes","tomatoes","onions","carrots","broccoli","cucumbers","lettuce","mushrooms","garlic","asparagus"};
	char *word_to_guess1;
	
	uint8_t counter_5ms = 0;
	uint8_t counter_1ms = 0;
	
	configurations();

	while (1)
	{
		if(timer1_flag_100us)
		{
			timer1_flag_100us = 0;
			counter_5ms++;
			counter_1ms++;
			
			if(counter_5ms == 50)
			{
				task_5ms();
				counter_5ms = 0;
			}
			
			if(counter_1ms == 10) 
			{
				task_1ms();
				extract_word(&word_to_guess1, word_database, random_number);
				counter_of_letters(&word);
				counter_1ms = 0;
			}
		}
	}
}

