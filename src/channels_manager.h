#ifndef CHANNELS_MANAGER_H
#define CHANNELS_MANAGER_H
#include "Arduino.h"
#include "receivers\receiver.h"
#include "filters\filter.h"
#include "config.h"
class ChannelsManager
{

public:
    ChannelsManager();
    void update();
    void AddFilter(int32_t channel,AbstractFilterHandler* filterChain);
private:
    uint8_t *_buttons;
    uint8_t *_pressedFlags;
    Receiver *_receiver;
    uint8_t _axis0;
    uint8_t _axis1;
    uint32_t __debug_timeout = 0;
    uint16_t _filterCounter[CM_MAX_CHANNELS];
    int32_t _filteredValues[CM_MAX_CHANNELS][CM_MAX_FILTERS_PER_CHANNEL];
    AbstractFilterHandler* _filters[CM_MAX_CHANNELS*CM_MAX_FILTERS_PER_CHANNEL] ;
};

#endif