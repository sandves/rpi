#include "RPI.h"
#include "tuxx.h"
#include <stdio.h>

void setup_io()
{
	// Define input and output pins
	INP_GPIO(RED);
	OUT_GPIO(RED);

	INP_GPIO(YELLOW);
	OUT_GPIO(YELLOW);

	INP_GPIO(GREEN);
	OUT_GPIO(GREEN);

	INP_GPIO(RED_MAN);
	OUT_GPIO(RED_MAN);

	INP_GPIO(GREEN_MAN);
	OUT_GPIO(GREEN_MAN);

	INP_GPIO(BUTTON);

	GPIO_SET = 1 << GREEN;
	GPIO_SET = 1 << RED_MAN;
}

void waitButton()
{
	printf("%s\n", "Waiting for button ... ");
	while(GPIO_READ(BUTTON) != 0)
		delay(100);
	printf("%s\n", "Got it");
}

void stopTraffic()
{
	printf("%s\n", "Stopping traffic ... ");
	
	GPIO_CLR = 1 << GREEN;
	GPIO_SET = 1 << YELLOW;
	
	delay(2000);
	
	GPIO_CLR = 1 << YELLOW;
	GPIO_SET = 1 << RED;
	
	delay(2000);
	
	printf("%s\n", "Stopped");
}

void walk()
{
	printf("%s\n", "Walk now ... ");
	
	GPIO_CLR = 1 << RED_MAN;
	GPIO_SET = 1 << GREEN_MAN;
	
	delay(2000);
	
	GPIO_CLR = 1 << RED;
	GPIO_SET = 1 << YELLOW;
}

void graceTime()
{
	int i;

	printf("%s\n", "Grace time ...");

	for(i = 0; i < 8; i++)
	{
		delay(500);
		
		GPIO_CLR = 1 << GREEN_MAN;
		GPIO_CLR = 1 << YELLOW;
		
		delay(500);
		
		GPIO_SET = 1 << GREEN_MAN;
		GPIO_SET = 1 << YELLOW;
	}

	printf("%s\n", "Time up!");
}

void startTraffic()
{
	printf("%s\n", "Starting traffic ...");

	GPIO_CLR = 1 << GREEN_MAN;
	GPIO_SET = 1 << RED_MAN;
	
	delay(500);
	
	GPIO_CLR = 1 << YELLOW;
	GPIO_SET = 1 << GREEN;

	printf("%s\n", "Going");
}

void delay (unsigned int howLong)
{
	struct timespec sleeper, dummy ;

	sleeper.tv_sec  = (time_t)(howLong / 1000) ;
	sleeper.tv_nsec = (long)(howLong % 1000) * 1000000 ;

	nanosleep (&sleeper, &dummy) ;
}