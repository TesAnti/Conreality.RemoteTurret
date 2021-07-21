#include "emulation_motor.h"
#include "Arduino.h"

EmulationMotor::EmulationMotor(int pin)
{
    _pin=pin;
    if(!Serial.availableForWrite())
    {
        Serial.begin(9600);
    }
    Serial.print("emulation motor of pin ");
    Serial.println(pin);
}

void EmulationMotor::brake(){

}

void EmulationMotor::tick(){

}

void EmulationMotor::turn(int target)
{
    Serial.print("pin ");
    Serial.print(_pin);
    Serial.print(": turning to ");
    Serial.println(target);    
}