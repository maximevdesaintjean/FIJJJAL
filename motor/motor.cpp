#include <stdio.h>
#include <pigpio.h>

#include "motor.h"

using namespace std;

Motor::Motor(int pin, PID pid) {
    this->pin = pin; 
    this->pid = pid;
}

void Motor::initialize() {
    gpioSetMode(this->pin, PI_OUTPUT);
    gpioSleep(PI_TIME_RELATIVE, 0.5, 0);
    gpioWrite(this->pin, 1);
}

void Motor::stop() {
    gpioWrite(this->pin, 0);
    gpioTerminate();
}

void Motor::control(float setPoint, float input) {
    float ctrl = this->pid.calcPID(setPoint, input);
    this->setPWM(ctrl);
}

void Motor::setPWM(float value) {
    gpioServo(this->pin, value);
}