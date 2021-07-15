
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "motor.h"

#ifndef SERVO360ADA_H
#define SERVO360ADA_H



class Servo360Ada:public Motor{
    public:
        Servo360Ada(Adafruit_PWMServoDriver servo,int channel, int midPoint);
        
        virtual void turnCCW(int speed);
        virtual void turnCW(int speed);

        virtual void tick();
        void brake();
        
    private:
        int _lastRotation;
        int _midPoint;
        int _channel;
        unsigned long _brakeTime;
        Adafruit_PWMServoDriver* _servo;
        
};


#endif
