#include "PseudoOS.h"

void task_1ms(void)
{
	counter_random_number = increment_random_number();
	debounce_all_buttons();
}

void task_5ms(void)
{
		doTransitionDisplay(getEvent());
}

