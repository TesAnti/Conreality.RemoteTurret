
#ifndef RECEIVER_H
#define RECEIVER_H
#include "Arduino.h"

class Receiver{
    public:
        virtual void init()=0;
        virtual void update()=0;
        virtual void waitForConnection()=0;
        virtual uint8_t* getChannels()=0;
    
};

#endif