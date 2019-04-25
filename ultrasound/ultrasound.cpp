#include <iostream>
#include <tuple>
#include <pigpio.h>

#include "ultrasound.h"

using namespace std;

void Ultrasound::initialize()
{
    
    gpioSetMode(this->trig, PI_OUTPUT); 
    gpioSetMode(this->echo, PI_INPUT); 
    gpioWrite(this->trig, 0);
    gpioSleep(PI_TIME_RELATIVE, 0.5, 0);
}

double Ultrasound::getDistance()
{
	long end;
    long start;

	gpioWrite(this->trig, 1);
	gpioDelay(10);
	gpioWrite(this->trig, 0);

    long now = gpioTick();

    while (end== 0)
    {
        std::tie(end, start) = Ultrasound::pulse();
	}


    long difference_time = end - start;

    //distanceCm = 50*((DifferenceTimeUsec/1000000.0)*340.29);
    double distance = (double)difference_time/58.7734;
	
	if (end!= 0)
		return distance;
    else
		return 0;
}

std::tuple<long, long> Ultrasound::pulse()
{
    long start_time = gpioTick();
    long end_time;

    while ( gpioRead(echo) == 1 )
    {
		end_time = gpioTick();
	}

    return std::make_tuple(start_time, end_time);
}