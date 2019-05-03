#include <iostream>
//#include <pigpio.h>

#include "gyro.h"

using namespace std;

int main()
{
    Gyro gyro;

    gyro.initialise();
    while(1){
        gyro.readXY();
            
        printf("Rotation in X-Axis : %d \n", gyro.xy.x);
	    printf("Rotation in Y-Axis : %d \n", gyro.xy.y);
    }
}