#include <iostream>
#include <tuple>
#include <pigpio.h>

#include "ultrasound.h"

using namespace std;

Ultrasound::Ultrasound(int echo, int trig) {
    this->echo = echo;
    this->trig = trig;
}

void Ultrasound::initialize()
{
    gpioSetMode(this->trig, PI_OUTPUT); 
    gpioSetMode(this->echo, PI_INPUT); 
    gpioWrite(this->trig, 0);
    gpioSleep(PI_TIME_RELATIVE, 0.5, 0);
}

double Ultrasound::getDistance()
{
	end = 0;

	gpioWrite(this->trig, 1);
	gpioDelay(10);
	gpioWrite(this->trig, 0);

    while (end == 0)
    {
        Ultrasound::pulse();
	}

    long difference_time = end - start;
    double distance = (double)difference_time/58.7734;
	
	if (end != 0)
		return distance;
    else
		return 0;
}

void Ultrasound::pulse()
{
    start = gpioTick();

    while ( gpioRead(this->echo) == 1 )
    {
		end = gpioTick();
	}
}