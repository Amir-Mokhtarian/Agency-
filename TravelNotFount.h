#ifndef TRAVELNOTFOUNT_H
#define TRAVELNOTFOUNT_H
#include <stdexcept>
using namespace std;
class InvalidTicketCount : public out_of_range
{
public:
    InvalidTicketCount(string msg):out_of_range(msg)
    {
    }
};
class TravelNotFount : public logic_error
{
    public:
        TravelNotFount(string msg);
        TravelNotFount();
        virtual ~TravelNotFount();

    protected:

    private:
};

#endif // TRAVELNOTFOUNT_H
