#include <iostream>
#include <pigpio.h>

#include "./motor/motor.h"
#include "./pid/pid.h"
#include "./ultrasound/ultrasound.h"
#include "./gyro/gyro.h"
#include "fijjal.h"


int main() {
    /* Initialise GPIO pin */
    while (gpioInitialise() < 0)
    {
      fprintf(stderr, "pigpio initialisation failed\n");
      return -1;
    }

    /* Config class */
    Fijjal f = Fijjal();

    /* Initialize Ultrasound */
    Ultrasound ultra1 = Ultrasound(f.ultra_echo1, f.ultra_trig1);
    Ultrasound ultra2 = Ultrasound(f.ultra_echo2, f.ultra_trig2); 

    /* Initialize Gyroscope */
    Gyro gyro = Gyro();
    gyro.initialise();

    return 0;
}