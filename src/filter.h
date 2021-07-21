#ifndef CONNECTION_H
#define CONNECTION_H

#include "Arduino.h"

class FilterHandler
{
public:
    virtual FilterHandler *SetNext(FilterHandler *handler) = 0;
    virtual int32_t Handle(int32_t request) = 0;
};

class AbstractFilterHandler : public FilterHandler
{

private:
    FilterHandler *_next_handler;

public:
    FilterHandler *SetNext(FilterHandler *handler);
    int32_t Handle(int32_t request) ;
};


class LimitFilter:public AbstractFilterHandler
{
private:
    int32_t _min;
    int32_t _max;
public:
    LimitFilter(int32_t min,int32_t max);
    int32_t Handle(int32_t request);
    
};

class DeadzoneFilter:public AbstractFilterHandler
{
private:
    int32_t _min;
    int32_t _max;
    int32_t _defaultValue;
public:
    DeadzoneFilter(int32_t min,int32_t max,int32_t defaultValue);
    int32_t Handle(int32_t request);
    
};

class MapFilter:public AbstractFilterHandler
{
private:
    int32_t _minFrom;
    int32_t _maxFrom;
    int32_t _minTo;
    int32_t _maxTo;
public:
    MapFilter(int32_t minFrom,int32_t maxFrom,int32_t minTo,int32_t maxTo);
    int32_t Handle(int32_t request);
    
};

class LerpFilter:public AbstractFilterHandler
{
private:
    float _t;
    float _a;
    bool _isInitialized=false;
public:
    LerpFilter(float t);
    int32_t Handle(int32_t request);
    
};


#endif //h