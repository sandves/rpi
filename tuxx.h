#ifndef TUXX_H
#define TUXX_H

#define RED 		4
#define YELLOW		17
#define GREEN		27
#define RED_MAN		18
#define GREEN_MAN	23

#define BUTTON		22

void setup_io();
void waitButton();
void stopTraffic();
void walk();
void graceTime();
void startTraffic();
void delay (unsigned int howLong);

#endif /* TUXX_H */