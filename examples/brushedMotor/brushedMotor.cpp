#include <Wire.h>
#include <Arduino.h>
#include "channels_manager.h"
#include "config.h"
#include "nrf24receiver.h"
#include "filter.h"
#include "motorBrushed.h"

ChannelsManager* channelsManager;
InferiorConfig config;
MotorBrushed* motorBrushed;
void setup() {
  Serial.begin(9600);

  //create channels manager
  //config.channelsDebug=false;//hide debug information
  Receiver* receiver = new nrf24Receiver(10,9,2);
  channelsManager = new ChannelsManager(&config,receiver);
  motorBrushed= new MotorBrushed(5,3);

  //create filter chanin
  FilterHandler* filter = new EmptyFilter();
  
  //configure filter chain
  filter
  ->SetNext(new DeadzoneFilter(120,130,128))
  ->SetNext(new MapFilter(0,255,-50,50))
  ->SetNext(new LerpFilter(0.01))
  ; //map 0,1 to 2500,1500 turret range
  


  //assign filter chani to virtual channel 0
  channelsManager->AddFilter(1,0,filter);
  
}

void loop() {
  //receive information and apply filters to it
  channelsManager->update();
  //print value from virtual channel 0
  //Serial.println(channelsManager->GetVirtual(0));
  motorBrushed->Turn(channelsManager->GetVirtual(0));
}

