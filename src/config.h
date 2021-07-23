
#ifndef RC_CONFIG
#define RC_CONFIG

#include "Arduino.h"
#include "connection_types.h"
#include "app_config.h"

#define CM_MAX_CHANNELS 9
#define CM_MAX_VIRTUAL_CHANNELS 21



struct InferiorConfig
{
    bool channelsDebug=true;
    int channelsDebugInterval=500;
};



#endif//h