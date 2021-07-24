#include <Wire.h>
#include <Arduino.h>
#include "channels_manager.h"
#include "config.h"
#include "nrf24receiver.h"
#include "filter.h"


ChannelsManager* channelsManager;
InferiorConfig config;

void setup() {
  Serial.begin(9600);

  //create channels manager
  config.channelsDebug=false;//hide debug information
  Receiver* receiver = new nrf24Receiver(10,9,2);
  channelsManager = new ChannelsManager(&config,receiver);


  //create filter chanin
  FilterHandler* filter = new EmptyFilter();
  
  //configure filter chain
  filter
  ->SetNext(new TriggerFilter())          //press button once - 0, press again - 1
  ->SetNext(new MapFilter(0,1,2500,1500)) //map 0,1 to 2500,1500 turret range
  ->SetNext(new LerpFilter(0.01));        //change the value slowly


  //assign filter chani to virtual channel 0
  channelsManager->AddFilter(3,0,filter);
  
}

void loop() {
  //receive information and apply filters to it
  channelsManager->update();
  //print value from virtual channel 0
  Serial.println(channelsManager->GetVirtual(0));
}

