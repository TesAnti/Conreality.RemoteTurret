#ifndef MOTOR_H
#define MOTOR_H
class Motor
{
    public:
        virtual void tick()=0;

        virtual void turnCCW(int speed)=0;
        virtual void turnCW(int speed)=0;
        virtual void brake()=0;

};

#endif