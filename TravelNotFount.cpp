#include "TravelNotFount.h"
using namespace std;
TravelNotFount::TravelNotFount(string msg):logic_error(msg)
{
}
TravelNotFount::TravelNotFount():logic_error("Error : Khata Ra Handel Nakardei :: TravelNotFount")
{
}
TravelNotFount::~TravelNotFount()
{
    //dtor
}
