#ifndef MOTOR_BRUSHED_H
#define MOTOR_BRUSHED_H
#include "Arduino.h"

class MotorBrushed
{
    public:
        MotorBrushed(int fwdPin,int bkwdPin);
        void Turn(int speedPercent);
    private:
        int _fwdPin;
        int _bkwdPin;

};

#endif