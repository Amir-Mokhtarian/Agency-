#ifndef TRIP_RAIL_H
#define TRIP_RAIL_H
#include <stdexcept>
#include "Trip.h"
#include "Date.h"
#include "Time.h"
#include <iostream>
#include "TravelNotFount.h"


class Trip_Rail : public Trip
{
public:
    Trip_Rail();
    virtual ~Trip_Rail();
    void setCopeZarfiat(int cz)
    {
        if(cz>=0&&cz<=10)
            this->copeZarfiat=cz;
        else
            throw std::invalid_argument("Zarfiate Cope Bayad Beyne 0 Ta 10 Bashad!");
    }
    int getCopeZarfiat()
    {
        return copeZarfiat;
    }
    void setkhat(int k)
    {
        this->khat=k;
    }
    int getKhat()
    {
        return khat;
    }
    Trip_Rail(std::string mab,std::string mag,Date harkatD,Time harkatT,int zarfiat,int mod,int pri,int k,int cz)
        :Trip(mab,mag,harkatD,harkatT,zarfiat,mod,pri)
    {
        setkhat (k);
        setCopeZarfiat(cz);
    }
    void PrintTravelInfo()
    {
        Trip::PrintTravelInfo();
        std::cout<<"Shomare Khat : "<<khat<<"\nZarfiate Cope : "<<copeZarfiat<<'\n';
    }
    void SellTicket(string nam)
    {
        if((this->getSale())>=(this->copeZarfiat))
            throw InvalidTicketCount("Bishtar Az Zarfiat Ast!\n");
        this->setSale(this->getSale()+10);
        UpdateTravelInfo();
        int a=getCode();
        ofstream fo{"PurchasedTickets.dat",ios::binary|ios::app};
        fo.write(reinterpret_cast<char*>(&a),sizeof(int));
        fo.write(reinterpret_cast<char*>(&nam),sizeof(string));
        fo.close();
    }
protected:

private:
    int khat;
    int copeZarfiat;
};

#endif // TRIP_RAIL_H
