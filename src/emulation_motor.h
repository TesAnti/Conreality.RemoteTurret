#ifndef EMULATION_MOTOR_H
#define EMULATION_MOTOR_H
#include "motor.h"

class EmulationMotor : public Motor
{
public:
    EmulationMotor(int pin);
    virtual void tick();
    virtual void turn(int target);
    virtual void brake();
    private:
    int _pin;
};

#endif