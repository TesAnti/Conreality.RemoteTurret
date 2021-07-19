#include "channels_manager.h"
#include "config.h"
#include "receivers\nrf24receiver.h"
ChannelsManager::ChannelsManager()
{
    for (int32_t i = 0; i < CM_MAX_CHANNELS; i++)
    {
        _filterCounter[i] = 0;
    }

    for (int32_t i = 0; i < CM_MAX_CHANNELS * CM_MAX_FILTERS_PER_CHANNEL; i++)
    {
        _filters[i] = (AbstractFilterHandler *)0;
    }

    for (int32_t channel = 0; channel < CM_MAX_CHANNELS; channel++)
    {
        for (int32_t filter = 0; filter < CM_MAX_FILTERS_PER_CHANNEL; filter++)
        {
            _filteredValues[channel][filter] = 0;
        }
    }

#if USE_NRF24_RCV == 1
    _receiver = new nrf24Receiver();
#endif
    _receiver->init();
}

void ChannelsManager::AddFilter(int32_t channel, AbstractFilterHandler *filterChain)
{
    channel = channel - 1;
    int16_t cnt = _filterCounter[channel];
    if (cnt == CM_MAX_FILTERS_PER_CHANNEL)
    {
        return;
    }

    int32_t addr = CM_MAX_FILTERS_PER_CHANNEL * channel + cnt;

    _filters[addr] = filterChain;
}

void ChannelsManager::update()
{
    _receiver->waitForConnection();
    _receiver->update();
    uint8_t *buf = _receiver->getChannels();

    byte channelsCount = CM_MAX_CHANNELS;

    for (int i = 0; i < channelsCount; i++)
    {
        for (int f = 0; f < CM_MAX_FILTERS_PER_CHANNEL; f++)
        {
            int32_t addr = CM_MAX_FILTERS_PER_CHANNEL * i + f;
            if (_filters[addr] != NULL)
            {
                AbstractFilterHandler *caller = _filters[addr];
                _filteredValues[i][f] = caller->Handle(buf[i]);
            }
            else
            {
                _filteredValues[i][f] = buf[i];
            }
        }
    }

#if CHANNELS_DEBUG == 1
    if (__debug_timeout < millis())
    {
        Serial.println("-----------------------------");
        for (int i = 0; i < channelsCount; i++)
        {

            Serial.print("C");
            Serial.print(i + 1);
            Serial.print(": ");
            for (int f = 0; f < CM_MAX_FILTERS_PER_CHANNEL; f++)
            {
                char s[25];
                sprintf(s, "%03d", (int)_filteredValues[i][f]);
                Serial.print("[");
                Serial.print(s);
                Serial.print("]\t");
            }
            Serial.print("raw:");
            Serial.println(buf[i]);
        }
        __debug_timeout = millis() + CHANNELS_DEBUG_INTERVAL;
    }
#endif
}