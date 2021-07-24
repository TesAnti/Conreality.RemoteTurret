

#ifndef SERVO180_H
#define SERVO180_H
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


class Servo180 
{
private:
    Adafruit_PWMServoDriver *_servo;
    bool _isStoped;
    int _channel;
    float _angleF;
    float _angleFreal;
    float lerp(float a, float b, float t);

public:
    Servo180(Adafruit_PWMServoDriver servo, int channel);
    virtual void turn(int target);
    void turnCCW(int speed);
    void turnCW(int speed);
    virtual void tick();
    virtual void brake();
};

#endif