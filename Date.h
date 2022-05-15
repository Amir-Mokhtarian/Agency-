#ifndef DATE_H
#define DATE_H
#include <string>


class Date
{
public:
    int month;
    int year;
    int day;
    Date(int,int,int);
    virtual ~Date();
    Date();
    std::string PrintDate();
protected:

private:
};

#endif // DATE_H
