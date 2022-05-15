#include "Date.h"
#include <sstream>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
Date::Date(int dd,int mm,int yy)
{
    this->month=mm;
    this->year=yy;
    this->day=dd;
}
std::string Date::PrintDate()
{
    ostringstream ooo;
    ooo<<year<<"/"<<month<<"/"<<day<<'\n';
    return ooo.str();
}
Date::Date()
{
    //dtor
}
Date::~Date()
{
    //dtor
}
