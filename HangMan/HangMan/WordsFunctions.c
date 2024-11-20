#include "WordsFunctions.h"

WordStruct word={0,0,1,0};
uint8_t random_number = 0; 
uint8_t counter_random_number = 0;
char word_to_guess1[MAX_NUMBER_OF_LETTER_PER_WORD];
char alphabet[NUMBER_OF_ALPHABETS_LETTERS] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void random_guess_number()
{
	uint8_t i = counter_random_number;
	random_number= (ADC_read(0)+i)%(NUMBER_OF_DATABASE_WORD+1);
}

uint8_t increment_random_number()
{
		static uint8_t i;
		
		i++;
		
		if(i > NUMBER_OF_DATABASE_WORD)
		{
			i=0;
		}
		
		return i;
}

void extract_word(char** word1, char* array_database[], uint8_t position)
{
 	*word1 = word_to_guess1;

	strcpy(*word1, array_database[position]);
		
}

void counter_of_letters(WordStruct* word_struct)
{
	uint8_t i;
	uint8_t counter = 0;
	
	for ( i=0; word_to_guess1[i]!= 0; i++)
	{
		word_struct->last_letter_position = i;
		counter++;
	}

	word_struct->number_of_letters = counter;
}

char* letter_replacement(char* word, uint8_t pos)
{
	char *buffer=" ";
	strncpy((buffer+0), (word+pos), 1);
	return buffer;
}


