#include "EventManager.h"

static uint8_t events=0;

void setEvent(uint8_t event_nr)
{
	if(event_nr&BUTTON1_EVENT)  
	{
		events = 1;
	}
	else if(event_nr&BUTTON2_EVENT)
	{
		events = 2;
	}
	else if(event_nr&BUTTON3_EVENT)
	{
		events = 4;
	}
	else if(event_nr&BUTTON4_EVENT)
	{
		events = 8;
	}
}

uint8_t getEvent()
{
	return events;
}

void clearEvents()
{
	events = 0;
}

