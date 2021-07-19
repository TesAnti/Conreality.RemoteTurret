
#ifndef RC_CONFIG
#define RC_CONFIG

#include "Arduino.h"
#include "connection_types.h"
#include "app_config.h"


#ifndef CHANNELS_DEBUG
#define CHANNELS_DEBUG 0
#endif

#ifndef CHANNELS_DEBUG_INTERVAL
#define CHANNELS_DEBUG_INTERVAL 500
#endif

//-------------------
//  NRF24 RECEIVER CONFIG
//-------------------

#ifndef USE_NRF24_RCV
#define USE_NRF24_RCV 1
#endif

#ifndef NRF24_RCV_CE_PIN
#define NRF24_RCV_CE_PIN 10
#endif

#ifndef NRF24_RCV_SS_PIN
#define NRF24_RCV_SS_PIN 9
#endif

#ifndef NRF24_RCV_ADDRESS
#define NRF24_RCV_ADDRESS 2
#endif


//-------------------
//  SERIAL RECEIVER CONFIG
//-------------------



//-------------------
//  CHANNELS MANAGER CONFIG
//-------------------

#ifndef CM_MAX_CHANNELS
#define CM_MAX_CHANNELS 9
#endif

#ifndef CM_MAX_FILTERS_PER_CHANNEL
#define CM_MAX_FILTERS_PER_CHANNEL 3
#endif

//  AXIS X
#ifndef CM_USE_AXIS_X
#define CM_USE_AXIS_X 0
#endif

#ifndef CM_AXIS_X_FILTER
#define CM_AXIS_X_FILTER(A) map(A,0,255,0,255)
#endif

//  AXIS Y
#ifndef CM_USE_AXIS_Y
#define CM_USE_AXIS_Y 0
#endif

#ifndef CM_AXIS_Y_FILTER
#define CM_AXIS_Y_FILTER(A) map(A,0,255,0,255)
#endif


//  CHANNEL1
#ifndef CM_USE_CHANNEL1
#define CM_USE_CHANNEL1 0
#endif

#ifndef CM_CHANNEL1_FILTER
#define CM_CHANNEL1_FILTER(A) map(A,0,255,0,255)
#endif

#ifndef CM_CHANNEL1_TOGGLE
#define CM_CHANNEL1_TOGGLE false
#endif


//  CHANNEL2
#ifndef CM_USE_CHANNEL2
#define CM_USE_CHANNEL2 0
#endif

#ifndef CM_CHANNEL2_FILTER
#define CM_CHANNEL2_FILTER(A) map(A,0,255,0,255)
#endif

#ifndef CM_CHANNEL2_TOGGLE
#define CM_CHANNEL2_TOGGLE false
#endif

//  CHANNEL3
#ifndef CM_USE_CHANNEL3
#define CM_USE_CHANNEL3 0
#endif

#ifndef CM_CHANNEL3_FILTER
#define CM_CHANNEL3_FILTER(A) map(A,0,255,0,255)
#endif

#ifndef CM_CHANNEL3_TOGGLE
#define CM_CHANNEL3_TOGGLE false
#endif


#endif//h