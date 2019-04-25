#include "pid.h"
using namespace std;

PID::PID() {
    this->Kp = 0.02;
    this->Ki = 0.01;
    this->Kd = 0.005;
}

PID::PID(float Kp, float Ki, float Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
}

float PID::getKp() {
    return this->Kp;
}

float PID::getKi() {
    return this->Ki;
}

float PID::getKd() {
    return this->Kd;
}

void PID::setKp(float Kp) {
    this->Kp = Kp;
}

void PID::setKi(float Ki) {
    this->Ki = Ki;
}

void PID::setKd(float Kd) {
    this->Kd = Kd;
}

float PID::calcP(float setPoint, float input) {
    float error = setPoint - input;
    this->previousError = error;
    this->sumOfError += error;

    return this->Kp * error;
}

float PID::calcPI(float setPoint, float input) {
    float error = setPoint - input;
    float output = ( this->Kp * error) + (this->Ki * this->sumOfError);
    this->previousError = error;
    this->sumOfError += error;

    return output;
}

float PID::calcPD(float setPoint, float input) {
    float error = setPoint - input;
    float output = (this->Kp * error) + (this->Kd * this->previousError);
    this->previousError = error;
    this->sumOfError += error;

    return output;
}

float PID::calcPID(float setPoint, float input) {
    float error = setPoint - input;
    float output = (this->Kp * error) + (this->Kd * this->previousError) + (this->Ki * this->sumOfError);
    this->previousError = error;
    this->sumOfError += error;

    return output;
}