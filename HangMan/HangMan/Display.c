#include "Display.h"

uint8_t start_display = 0;
ScrollTextStruct winnerStruct = {0, 11, 11, 0, 0, 0};
ScrollTextStruct gameOverStruct = {0, 10, 10, 0, 0, 0};

void doTransitionDisplay(uint8_t events)
{
	if(state.idle == 1)
	{
		doTransition(events);
	}
	
	if(state.start)
	{
		if(start_display == 0)
		{
			display(&word,word_to_guess1);
			display_score(MAX_NUMBER_OF_CHANCES, SECOND_LCD_LINE, LAST_LCD_POSITION);
		}

		if((state.transition_decrement || state.transition_increment || state.choose_letter) && game.state==IN_GAME)
		{
			start_display = 1;
			doTransition(events);
		}
		
		if(events&BUTTON4_EVENT)
		{
			doTransition(events);
			
			if(state.reset)
			{
				start_display = 0;
				game.state = IN_GAME;
				state.reset = 0;
				game.increment_alphabets = 0;
				random_guess_number();
				display_clean_line(FIRST_LCD_LINE);
				display_clean_line(SECOND_LCD_LINE);
				reset_values(&state,&word);
				reset_scroll_text_structure(&winnerStruct, WINNER);
				reset_scroll_text_structure(&gameOverStruct, GAME_OVER);
			}
		}
		
		end_game_display();
	}
}


void display(WordStruct* word_struct, char* word)
{
	static uint8_t index_start = 0;
	static uint8_t index_stop = 0;
	
	if(word_struct->clean_LCD==0)
	{
		word_struct->clean_LCD = 1;
		LCD_Clear();
		index_start = 0;
		index_stop = 0;

	}

	uint8_t i;
	
	index_start = 1;
	index_stop = (word_struct->last_letter_position);
	

	for(i = index_start; i < index_stop; i++)
	{
		LCD_GoTo(FIRST_LETTER_POSITION,FIRST_LCD_LINE);
		LCD_WriteText(letter_replacement(word,FIRST_LETTER_POSITION));
		LCD_GoTo(index_stop,FIRST_LCD_LINE);
		LCD_WriteText(letter_replacement(word,index_stop));
		
		LCD_GoTo(i,0);
		LCD_WriteText("_");
	}
}

void display_clean_letter(WordStruct* word_struct, uint8_t line)
{
	uint8_t pos = word_struct->word_position;
	LCD_GoTo(pos, line);
	LCD_WriteText("  ");
}

void display_clean_line(uint8_t line)
{
	uint8_t i;
	
	for(i = 0; i <= LAST_LCD_POSITION; i++)
	{
		LCD_GoTo(i, line);
		LCD_WriteText("  ");
	}
}

void display_score(uint8_t score, uint8_t line, uint8_t pos_LCD)
{
	LCD_GoTo(pos_LCD, line);
	LCD_WriteDec(score);
}

void end_game_display()
{
	if(game.state==GAME_OVER)
	{
		display_sequence(&gameOverStruct, GAME_OVER);
	}
	else if(game.state==WINNER)
	{
		display_sequence(&winnerStruct, WINNER);
	}
}

void display_sequence(ScrollTextStruct* winner_struct, uint8_t option)
{
	char line_1_text[15];
	
	if(option == WINNER)
	{
		char text[12]="Ai castigat!";
		strcpy(line_1_text, text);
	}
	else if(option == GAME_OVER)
	{
		char text[11]="Ai pierdut!";
		strcpy(line_1_text, text);
	}
	

	if(winner_struct->y==0)
	{
		display_clean_line(FIRST_LCD_LINE);
		display_clean_line(SECOND_LCD_LINE);
		winner_struct->y = 1;
	}
	
	if(winner_struct->first_line_finised == 0)
	{
		winner_struct->counter_ms++;
		if (winner_struct->counter_ms >= 5)  //50
		{
			winner_struct->counter_ms = 0;
			if(winner_struct->x_current > 0)
			{
				LCD_GoTo(winner_struct->x_current-1, FIRST_LCD_LINE);
				LCD_WriteData(' ');

			}
			
			LCD_GoTo(winner_struct->x_current, FIRST_LCD_LINE);
			LCD_WriteData(line_1_text[winner_struct->index]);
			
			winner_struct->x_current++;
			
			if(winner_struct->x_current > winner_struct->x_final)
			{
				winner_struct->x_current = 0;
				if(winner_struct->index > 0)
				{
					winner_struct->index--;
				}
				else
				{
					winner_struct->first_line_finised = 1;
				}
				winner_struct->x_final--;
			}
		}
	}
	
}

void reset_scroll_text_structure(ScrollTextStruct* scroll_struct, uint8_t option )
{
	if(option == WINNER)
	{
		scroll_struct->index = 11;
		scroll_struct->x_final = 11;
	}
	else if(option == GAME_OVER)
	{
		scroll_struct->index = 10;
		scroll_struct->x_final = 10;
	}
	
	scroll_struct->counter_ms = 0;
	scroll_struct->x_current = 0;
	scroll_struct->y = 0;
	scroll_struct->first_line_finised = 0;
}
