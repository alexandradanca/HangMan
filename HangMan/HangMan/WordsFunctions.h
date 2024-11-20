#ifndef WORDSFUNCTIONS_H_
#define WORDSFUNCTIONS_H_
#include <string.h>
#include <stdio.h>
#include "HD44780.h"
#include "Adc.h"

#define MIN_NUMBER_OF_DATABASE_WORD (0u)
#define NUMBER_OF_DATABASE_WORD (20u)
#define MAX_NUMBER_OF_LETTER_PER_WORD (16u)
#define FIRST_LETTER_POSITION (0u)
#define MIN_NUMBER_OF_CHANCES (0u)
#define MAX_NUMBER_OF_CHANCES (6u)
#define NUMBER_OF_WORD_TO_GUESS (1u)
#define FIRST_LCD_LINE (0u)
#define SECOND_LCD_LINE (1u)
#define NUMBER_OF_ALPHABETS_LETTERS (26u)

typedef struct  
{
	uint8_t number_of_letters;
	uint8_t last_letter_position;
	uint8_t word_position;
	uint8_t clean_LCD;
}WordStruct;

extern WordStruct word;

extern uint8_t random_number;
extern uint8_t counter_random_number;
extern char word_to_guess1[MAX_NUMBER_OF_LETTER_PER_WORD];
extern char alphabet[26];

void random_guess_number();
uint8_t increment_random_number();
void extract_word(char** word1, char* array_database[], uint8_t position);
void counter_of_letters(WordStruct* word_struct);
char* letter_replacement(char* word, uint8_t pos);

#endif /* WORDSFUNCTIONS_H_ */