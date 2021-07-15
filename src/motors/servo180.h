
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "motor.h"

#ifndef SERVO180_H
#define SERVO180_H

class Servo180:public Motor
{
private:
    
    Adafruit_PWMServoDriver* _servo;
    bool _isStoped;
    int _channel;
    float _angleF;
    float _angleFreal;
    float lerp(float a, float b, float t);
public:
    Servo180(Adafruit_PWMServoDriver servo,int channel);
    virtual void turnCCW(int speed);
    virtual void turnCW(int speed);
    virtual void tick();
    virtual void brake();
};

#endif