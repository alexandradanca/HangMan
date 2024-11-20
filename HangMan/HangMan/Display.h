#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Button.h"
#include "EventManager.h"
#include "HD44780.h"
#include "WordsFunctions.h"
#include "StateMachines.h"

#define LAST_LCD_POSITION (15u)

extern uint8_t start_display;

typedef struct  
{
	uint16_t counter_ms;
	uint8_t index;
	uint8_t x_final;
	uint8_t x_current;
	uint8_t y;
	uint8_t first_line_finised;
}ScrollTextStruct;

extern ScrollTextStruct winnerStruct;
extern ScrollTextStruct gameOverStruct;

void doTransitionDisplay(uint8_t events);
void display(WordStruct* word_struct, char* word);
void display_clean_letter(WordStruct* word_struct, uint8_t line);
void display_clean_line(uint8_t line);
void display_score(uint8_t score, uint8_t line, uint8_t pos_LCD);
void end_game_display();
void display_sequence(ScrollTextStruct* winner_struct, uint8_t option);
void reset_scroll_text_structure(ScrollTextStruct* scroll_struct, uint8_t option);
#endif /* DISPLAY_H_ */