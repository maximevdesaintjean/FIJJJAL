#include <iostream>
#include <tuple>
#include <pigpio.h>

#include "ultrasound.h"

using namespace std;

/* Constructor */
Ultrasound::Ultrasound(int echo, int trig) {
    this->echo = echo;
    this->trig = trig;
}

/* Initialise pin for ultrasound */
void Ultrasound::initialize()
{
    gpioSetMode(this->trig, PI_OUTPUT); 
    gpioSetMode(this->echo, PI_INPUT); 
    gpioWrite(this->trig, 0);
    gpioSleep(PI_TIME_RELATIVE, 0.5, 0);
}

/* Get distance for object detection */
double Ultrasound::getDistance()
{
	end = 0;

    /* To be sure that trig pin is on low level */
	gpioWrite(this->trig, 1);
	gpioDelay(10);
	gpioWrite(this->trig, 0);

    while (end == 0)
    {
        Ultrasound::pulse();
	}

    /* Calcul distance with time difference between end and start pulse */
    long difference_time = end - start;
    /* Convert time to distance */
    double distance = (double)difference_time/58.7734;
	
	if (end != 0)
		return distance;
    else
		return 0;
}

/* Function to get pulse between echo trig to recover time dor distance */
void Ultrasound::pulse()
{
    start = gpioTick();

    while ( gpioRead(this->echo) == 1 )
    {
		end = gpioTick();
	}
}