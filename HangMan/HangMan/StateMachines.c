#include "StateMachines.h"

EventState state = {0,1,0,0,0,0,0};
GameDetails game = {0, IDLE};
uint8_t score = MAX_NUMBER_OF_CHANCES;

void doTransition(uint8_t events)
{	
	if(events&BUTTON1_EVENT && game.state==IDLE)
	{
		state.start = 1;
		state.idle = 0;
		game.state=IN_GAME;
	}

	if(state.start)
	{
		if(events&BUTTON1_EVENT && game.state==IN_GAME)
		{
			state.transition_increment = 0;
			state.transition_decrement = 1;
			
			if(game.increment_alphabets==0)
			{
				game.increment_alphabets = 0;
			}
			else
			{
				game.increment_alphabets--;
			}
		}

		if(events&BUTTON2_EVENT && game.state==IN_GAME)
		{
			state.transition_decrement = 0;
			state.transition_increment = 1;
			
			if(game.increment_alphabets < (NUMBER_OF_ALPHABETS_LETTERS-1))
			{
				game.increment_alphabets++;
			}
		}
		
		if(events&BUTTON3_EVENT && game.state==IN_GAME)
		{
			state.choose_letter = 1;
		}
		else
		{
			state.choose_letter = 0;
		}
		
		if(events&BUTTON4_EVENT)
		{
			state.reset = 1;
		}

		LCD_GoTo(word.word_position,SECOND_LCD_LINE);
		LCD_WriteText(letter_replacement(alphabet, game.increment_alphabets));	
		match_check(&state, word_to_guess1, alphabet, word.word_position, game.increment_alphabets);
		doSwitch(&state, &word);
		clearEvents();
	}
}

void match_check(EventState *check_state, char* word, char* alphabet, uint8_t pos_word, uint8_t pos_alph)
{
	char* letter_word = letter_replacement(word, pos_word);
	
	if(*letter_word == alphabet[pos_alph])
	{
		check_state->check_letter = 1;
	}
	else
	{
		check_state->check_letter = 0;
	}
}

void doSwitch(EventState *check_state, WordStruct* word_struct)
{
	if(check_state->choose_letter && check_state->check_letter)
	{
		check_state->choose_letter = 0;
		check_state->check_letter = 0;
		LCD_GoTo(word_struct->word_position, FIRST_LCD_LINE);
		LCD_WriteText(letter_replacement(alphabet, game.increment_alphabets));
		display_clean_letter(word_struct, SECOND_LCD_LINE);
		increment_position(word_struct);
		game.increment_alphabets = 0;
	}
	else if(check_state->choose_letter && (check_state->check_letter == 0))
	{
		change_score(check_state, &score);
		game.increment_alphabets = 0;
	}
	
	LCD_GoTo(word_struct->word_position, SECOND_LCD_LINE);
	LCD_WriteText(letter_replacement(alphabet, game.increment_alphabets));
	display_score(score, SECOND_LCD_LINE, LAST_LCD_POSITION);
}

void increment_position(WordStruct* word_struct)
{
	if(word_struct->word_position < (word_struct->last_letter_position-1))
	{
		word_struct->word_position+=1;
	}
	else
	{
		game.state= WINNER;
	}
}

void change_score(EventState *check_state, uint8_t *score)
{
	if(check_state->check_letter != 1)
	{
		*score-=1;
		
		if(*score == 0)
		{
			game.state = GAME_OVER;
		}
		else
		{
			game.state = IN_GAME;
		}
	}
}

void reset_values(EventState *check_state, WordStruct* word_struct)
{
	check_state->check_letter = 0;
	check_state->choose_letter = 0;
	word_struct->word_position = 1;
	word_struct->clean_LCD = 0;
	score = MAX_NUMBER_OF_CHANCES;
}





