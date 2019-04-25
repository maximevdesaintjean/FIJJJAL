#include <iostream>
#include <pigpio.h>

#include "ultrasound.h"

using namespace std;

int trigger = 4;
int echo = 17;

int main()
{
    Ultrasound ultra = Ultrasound(echo, trigger);
    ultra.initialize();

    while(1){
		gpioSleep(PI_TIME_RELATIVE, 0, 500000);
        cout << "Distance is " << ultra.getDistance() << " cm." << endl;   
    }
}