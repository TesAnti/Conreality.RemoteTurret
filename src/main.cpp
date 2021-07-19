#include <RHReliableDatagram.h>
#include <RH_NRF24.h>
#include <SPI.h>
#include "channels_manager.h"

/*-------------------------------------------------------------------------------------*/

#include "config.h"

/*-------------------------------------------------------------------------------------*/

/***
 *                                                             
 *    ,------.                     ,--.                        
 *    |  .--. ' ,---.  ,---. ,---. `--',--.  ,--.,---. ,--.--. 
 *    |  '--'.'| .-. :| .--'| .-. :,--. \  `'  /| .-. :|  .--' 
 *    |  |\  \ \   --.\ `--.\   --.|  |  \    / \   --.|  |    
 *    `--' '--' `----' `---' `----'`--'   `--'   `----'`--'    
 *                                                             
 */

ChannelsManager *manager;
void setup()
{

  Serial.begin(9600);
  manager = new ChannelsManager();

  AbstractFilterHandler* filter = new MapFilter(0,1,255,0);
  filter->SetNext(new LerpFilter(0.000001));

  manager->AddFilter(3,filter);
}

void loop()
{
  manager->update();
}