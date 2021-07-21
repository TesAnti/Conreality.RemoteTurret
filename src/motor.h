#ifndef MOTOR_H
#define MOTOR_H
class Motor
{
    public:
        virtual void tick()=0;
        virtual void turn(int target)=0;
        virtual void brake()=0;

};

#endif