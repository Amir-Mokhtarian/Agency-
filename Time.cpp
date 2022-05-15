#include "Time.h"
Time::Time(int s,int m, int h)
{
    this->second=s;
    this->minute=m;
    this->hour=h;
}
Time::Time()
{
    //ctor
}

Time::~Time()
{
    //dtor
}
