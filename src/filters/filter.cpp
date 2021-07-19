#include "filter.h"

FilterHandler *AbstractFilterHandler::SetNext(FilterHandler *handler)
{
    _next_handler = handler;
    return handler;
}

int32_t AbstractFilterHandler::Handle(int32_t request) 
{
    if (_next_handler != 0)
    {
        return _next_handler->Handle(request);
    }

    return request;
}

LimitFilter::LimitFilter(int32_t min,int32_t max)
{
    _min=min;
    _max=max;
}

int32_t LimitFilter::Handle(int32_t request){
    if(request>_max)request=_max;
    if(request<_min)request=_min;
    return request;
}


DeadzoneFilter::DeadzoneFilter(int32_t min,int32_t max,int32_t defaultValue)
{
    _min=min;
    _max=max;
    _defaultValue=defaultValue;
}

int32_t DeadzoneFilter::Handle(int32_t request){
    if(request>_max)request=_defaultValue;
    if(request<_min)request=_defaultValue;
    return request;
}

MapFilter::MapFilter(int32_t minFrom,int32_t maxFrom,int32_t minTo,int32_t maxTo)
{
    _minFrom=minFrom;
    _maxFrom=maxFrom;
    _minTo=minTo;
    _maxTo=maxTo;
    
}

int32_t MapFilter::Handle(int32_t request){
    
    return map(request,_minFrom,_maxFrom,_minTo,_maxTo);
}

LerpFilter::LerpFilter(float t)
{
    _t=t;
 
}

int32_t LerpFilter::Handle(int32_t request){
    if(!_isInitialized)
    {
        _a=(float)request;
        _isInitialized=true;
    }
    _a=_a+(request-_a)*_t;
    return (int32_t)_a;
}