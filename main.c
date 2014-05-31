#include "RPI.h"
#include <stdio.h>
#include "traffic.h"

int main()
{
	struct bcm2835_peripheral gpio = {GPIO_BASE};
	
	if(map_peripheral(&gpio) == -1)
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		return -1;
	}

	setup_io();

	for(;;)
	{
		waitButton();
		stopTraffic();
		walk();
		graceTime();
		startTraffic();
	}

	return 0;
}
