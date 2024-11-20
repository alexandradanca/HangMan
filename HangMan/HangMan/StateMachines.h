#ifndef STATEMACHINES_H_
#define STATEMACHINES_H_

#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Button.h"
#include "EventManager.h"
#include "HD44780.h"
#include "WordsFunctions.h"
#include "Display.h"

#define IDLE (3u)
#define GAME_OVER (0u)
#define WINNER (1u)
#define IN_GAME (2u)

typedef struct
{
	uint8_t start;
	uint8_t idle;
	uint8_t choose_letter;
	uint8_t reset;
	uint8_t transition_increment;
	uint8_t transition_decrement;
	uint8_t check_letter;
}EventState;

extern EventState state;

typedef struct  
{
	uint8_t increment_alphabets;
	uint8_t state;
}GameDetails;

extern GameDetails game;

extern uint8_t score;

void doTransition(uint8_t events);
void match_check(EventState *check_state, char* word, char* alphabet, uint8_t pos_word, uint8_t pos_alph);
void doSwitch(EventState *check_state, WordStruct* word_struct);
void increment_position(WordStruct* word_struct);
void change_score(EventState *check_state, uint8_t *score);
void reset_values(EventState *check_state, WordStruct* word_struct);


#endif /* STATEMACHINES._H_ */