#include "pid.h"
#include <iostream>
using namespace std;

PID::PID() {
    this->minBound = 1500; /* At verify */
    this->maxBound = 1900;
    this->Kp = 0.02;
    this->Ki = 0.01;
    this->Kd = 0.005;
}

PID::PID(float minBound, float maxBound, float Kp, float Ki, float Kd) {
    this->minBound = minBound >=1500 ? this->minBound = minBound : this->minBound = 1500;
    this->maxBound = maxBound <=1900 ? this->maxBound = maxBound : this->maxBound = 1900;

    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
}

float PID::getMinBound() {
    return this->minBound;
}

float PID::getMaxBound() {
    return this->maxBound;
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

void PID::setMinBound(float minBound) {
    this->minBound = minBound >=1500 ? this->minBound = minBound : this->minBound = 1500;
}

void PID::setMaxBound(float maxBound) {
    this->maxBound = maxBound <=1900 ? this->maxBound = maxBound : this->maxBound = 1900;
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
    float output = this->Kp * error;

    return calcMap(output);
}

float PID::calcPI(float setPoint, float input) {
    float error = setPoint - input;
    float output = (this->Kp * error) + (this->Ki * this->sumOfError/this->cycle);
    this->sumOfError += error;
    this->cycle ++;

    return calcMap(output);
}

float PID::calcPD(float setPoint, float input) {
    float error = setPoint - input;
    float output = (this->Kp * error) + (this->Kd * this->previousError);
    this->previousError = error;

    return calcMap(output);
}

float PID::calcPID(float setPoint, float input) {
    float error = setPoint - input;
    float output = (this->Kp * error) + (this->Kd * this->previousError) + (this->Ki * this->sumOfError/this->cycle);
    this->previousError = error;
    this->sumOfError += error;
    this->cycle ++;

    return calcMap(output);
}

float PID::calcMap(float output) {
    float outputMax = this->Kp * this->errorMax;
    float newOutput = this->minBound + ((output/outputMax) * (this->maxBound - this->minBound));

    if (newOutput <= 1200) {
        return 1200;
    } 
    else {
        return newOutput;
    }
}