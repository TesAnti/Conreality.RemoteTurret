#include "motorBrushed.h"

MotorBrushed::MotorBrushed(int fwdPin,int bkwdPin)
{
    _fwdPin=fwdPin;
    _bkwdPin=bkwdPin;
    pinMode(_fwdPin,OUTPUT);
    pinMode(_bkwdPin,OUTPUT);
    analogWrite(_fwdPin,0);
    analogWrite(_bkwdPin,0);
}

void MotorBrushed::Turn(int speedPercent)
{
    int speed=map(abs(speedPercent),0,100,0,255);
    if(speedPercent>0)
    {
        analogWrite(_bkwdPin,0);
        analogWrite(_fwdPin,speed);
    }else if (speedPercent<0)
    {
        analogWrite(_fwdPin,0);
        analogWrite(_bkwdPin,speed);
    }else{
        analogWrite(_fwdPin,0);
        analogWrite(_bkwdPin,0);
    }
    
}