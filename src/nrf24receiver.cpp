#include "nrf24receiver.h"
#include "config.h"
#include "Arduino.h"


nrf24Receiver::nrf24Receiver(int ce,int ss,int address)
{
    _ce=ce;
    _ss=ss;
    _address=address;
}


void nrf24Receiver::init()
{
    _driver = new RH_NRF24(_ce, _ss);

    _manager = new RHReliableDatagram(*_driver, _address);
    _buf = new uint8_t[RH_NRF24_MAX_MESSAGE_LEN];

    if(_manager->init())
    {
        Serial.println("radio initialized");
    }else{
        Serial.println("radio not initialized");
        while(true){}
    }
    
}

void nrf24Receiver::update()
{
    if (_manager->available())
    {

        uint8_t len = RH_NRF24_MAX_MESSAGE_LEN;
        uint8_t from;
        if(_manager->recvfromAck(_buf, &len, &from))
        {
            if(!_connected)
            {
                Serial.println("connected");
                Serial.print("received ");
                Serial.print(len);
                Serial.println("bytes");
            }
            _connected=true;
        }
    }
}

void nrf24Receiver::waitForConnection()
{
    
    while (!_connected) {update();}
}

byte* nrf24Receiver::getChannels()
{
    return _buf;
}