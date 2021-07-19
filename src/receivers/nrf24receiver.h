#ifndef NRF24RECEIVER_H
#define NRF24RECEIVER_H

#include "receiver.h"
#include "nrf24receiver.h"
#include <RH_NRF24.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <RHReliableDatagram.h>

class nrf24Receiver:public Receiver{
    public:
        virtual void init();
        virtual void update();
        virtual void waitForConnection();
        virtual uint8_t* getChannels();
    private:
        RH_NRF24* _driver;
        RHReliableDatagram* _manager;
        uint8_t* _buf;
        bool _connected=false;
};

#endif