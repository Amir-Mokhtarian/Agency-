
#ifndef TRIP_H
#define TRIP_H
#include "Date.h"
#include "Time.h"
#include <string>
#include <deque>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <iostream>

///Container
//template<class T, class Container = std::deque<T>>


class Trip
{
    public:

        Trip(std::string,std::string,Date,Time,int,int,int);
        Trip(int);

        Trip();
        virtual ~Trip();
        void setHarkatDate(int,int,int);
        std::string getHarkatDate();
        void setHarkatTime(int,int,int);
        std::string getHarkatTime();
        void setCode(int);
        int getCode();
        void setSale(int);
        int getSale();
        void setZarf(int);
        int getZarf();
        void setPrice(int);
        int getPrice();
        void setMabda(std::string);
        void setMagsad(std::string);
        void setModat(int);
        std::string getMabda();
        std::string getMagsad();
        int getmodat();
        std::deque<Trip> LoadTravelsInContainer()
{
    Trip a;
    std::deque<Trip> c;
    std::ifstream fi{"Travels.dat",std::ios::in|std::ios::binary};
    while (!fi.eof())
    {
        fi.read(reinterpret_cast<char*>(&a),sizeof(Trip));
        a.PrintTravelInfo();

        c.push_back(a);
    }
    return c ;
}
        ///print
        void PrintTravelInfo();
        ///file
        void SaveInFile();
        void LoadFromFile(int);

        ///By LinkList
        void LoadPrintTravelsInLinkedList();



        void UpdateTravelInfo();

        void PrintCustomers();

        virtual void SellTicket(std::string name);

        void operator + (int a);
        void operator ++();
        void operator --();
    protected:

    private:
        int Code;
        Date harkatDate;
        Time harkatTime;
        int sale;
        int zarf;
        int price;
        std::string mabda;
        std::string magsad;
        int modat;

};

#endif // TRIP_H
