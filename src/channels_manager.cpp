#include "channels_manager.h"
#include "config.h"
#include "nrf24receiver.h"

ChannelsManager::ChannelsManager(InferiorConfig *inferiorConfig, Receiver *receiver)
{
    _receiver = receiver;
    _inferiorConfig = inferiorConfig;
    
    

    for (int32_t i = 0; i < CM_MAX_VIRTUAL_CHANNELS; i++)
    {
        _filters[i] = (AbstractFilterHandler *)0;
    }

    for (int32_t channel = 0; channel < CM_MAX_VIRTUAL_CHANNELS; channel++)
    {
         _filteredValues[channel]= 0;
         _filterInputs[channel]=-1;
    }

    _receiver->init();
}

void ChannelsManager::AddFilter(int16_t sourceChannel, int16_t virtualChannel, FilterHandler *filterChain)
{
    _filterInputs[virtualChannel]=sourceChannel;
    _filters[virtualChannel] = filterChain;
}

void ChannelsManager::update()
{
    _receiver->waitForConnection();
    _receiver->update();
    uint8_t *buf = _receiver->getChannels();

    byte channelsCount = CM_MAX_VIRTUAL_CHANNELS;

    for (int i = 0; i < channelsCount; i++)
    {

        if(_filterInputs[i]==-1)continue;
        FilterHandler *caller = _filters[i];
        _filteredValues[i] = caller->Handle(buf[_filterInputs[i]]);

        
    }

    if (_inferiorConfig->channelsDebug)
    {
        if (__debug_timeout < millis())
        {
            Serial.println("-----------------------------");
            for (int i = 0; i < CM_MAX_VIRTUAL_CHANNELS; i++)
            {
                if(_filterInputs[i]==-1)continue;
                Serial.print("VC");
                Serial.print(i);
                Serial.print(": ");
                char s[10];
                sprintf(s, "%03d", (int)_filteredValues[i]);
                Serial.print(s);
                Serial.print("\t");
                Serial.print("raw:");
                Serial.println(buf[_filterInputs[i]]);
            }
            
            __debug_timeout = millis() + _inferiorConfig->channelsDebugInterval;
        }
    }
}

int32_t ChannelsManager::GetVirtual(int virtualChannel)
{
    return _filteredValues[virtualChannel];
}