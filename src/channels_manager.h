#ifndef CHANNELS_MANAGER_H
#define CHANNELS_MANAGER_H
#include "Arduino.h"
#include "receiver.h"
#include "filter.h"
#include "config.h"
class ChannelsManager
{

public:
    ChannelsManager(InferiorConfig *inferiorConfig, Receiver* receiver);
    void update();
    void AddFilter(int16_t sourceChannel, int16_t virtualChannel, FilterHandler *filterChain);
    int32_t GetVirtual(int virtualChannel);
private:
    InferiorConfig *_inferiorConfig;
    uint8_t *_buttons;
    uint8_t *_pressedFlags;
    Receiver *_receiver;
    uint8_t _axis0;
    uint8_t _axis1;
    uint32_t __debug_timeout = 0;
    
    int32_t _filteredValues[CM_MAX_VIRTUAL_CHANNELS];
    int16_t _filterInputs[CM_MAX_VIRTUAL_CHANNELS];
    FilterHandler *_filters[CM_MAX_VIRTUAL_CHANNELS];
    
};

#endif