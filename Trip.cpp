#include "LinkList.h"
#include "TravelNotFount.h"
#include "Trip.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <deque>
#include <vector>
#include "PurchasedTickets.h"
#include "Date.h"
#include "Time.h"

using namespace std;
Trip::Trip(string mab,string mag,Date harkatD,Time harkatT,int zarfiat,int mod,int pri)
{
    setMabda(mab);
    setMagsad(mag);
    setHarkatDate(harkatD.day,harkatD.month,harkatD.year);
    setHarkatTime(harkatT.second,harkatT.minute,harkatT.hour);
    setZarf(zarfiat);
    setModat(mod);
    setPrice(pri);
    static int C=0;
    setCode(C);
    C++;
    this->sale=0;
}
Trip::Trip(int co)
{
    LoadFromFile(co);
}
void Trip::setCode(int co)
{
    this->Code=co;
}
int Trip::getCode()
{
    return Code;
}
void Trip::setHarkatDate(int d,int m,int y)
{
    harkatDate.day=d;
    harkatDate.month=m;
    harkatDate.year=y;
}
string Trip::getHarkatDate()
{
    ostringstream ooo;
    ooo<<"Year: "<<harkatDate.year<<"\tMonth: "<<harkatDate.month<<"\tDay: "<<harkatDate.day<<'\n';
    return ooo.str();
}
void Trip::setHarkatTime(int s,int m,int h)
{
    harkatTime.second=s;
    harkatTime.minute=m;
    harkatTime.hour=h;
}
string Trip::getHarkatTime()
{
    ostringstream ooo;
    ooo<<"Hour: "<<this->harkatTime.second<<"\tMinute: "<<this->harkatTime.minute<<"\tHour: "<<this->harkatTime.hour<<'\n';
    return ooo.str();
}
void Trip::setZarf(int z)
{
    zarf=z;
}
int Trip::getZarf()
{
    return zarf;
}
void Trip::setSale(int s)
{
    sale=s;
}
int Trip::getSale()
{
    return sale;
}
void Trip::setPrice(int p)
{
    price=p;
}
int Trip::getPrice()
{
    return price;
}

void Trip::setMabda(std::string m)
{
    mabda =m;
}
void Trip::setMagsad(std::string m)
{
    magsad=m;
}
void Trip::setModat(int m)
{
    modat=m;
}
std::string Trip::getMabda()
{
    return mabda;
}
std::string Trip::getMagsad()
{
    return magsad;
}
int Trip::getmodat()
{
    return modat;
}







void Trip::LoadPrintTravelsInLinkedList()
{
    Trip i;
    ifstream fi{"Travels.dat",ios::in|ios::binary};
    fi.read(reinterpret_cast<char*>(&i),sizeof(Trip));
    LinkList* first=new LinkList (i);
    LinkList* last;
    last=first;
    fi.read(reinterpret_cast<char*>(&i),sizeof(Trip));
    last->next=new LinkList(i);
    last=first->next;
    while(!fi.eof())
    {
        fi.read(reinterpret_cast<char*>(&i),sizeof(Trip));
        last->next=new LinkList (i);
        last->value.PrintTravelInfo();
        last=last->next;
    }
    LinkList* p{first};
    while (p!=nullptr)
    {
        p->value.PrintTravelInfo();
        p=p->next;
    }
}

void Trip::PrintTravelInfo()
{
    cerr<<"Code: "<<Code<<"\nMabda: "<<mabda<<"\nMagsad: "<<magsad<<"\nModat: "<<modat<<"\nPrice: "<<price<<"\nZarfiat: "<<zarf<<"\nForokhte Shode: "<<sale<<'\n';
}


void Trip::SaveInFile()
{
    ofstream fo{"Travels.dat",ios::app | ios::binary};
    fo.write(reinterpret_cast<char*>(this),sizeof(Trip));
    fo.close();
}



void Trip::LoadFromFile(int a)
{
    Trip *p;
    ifstream fi{"Travels.dat",ios::in|ios::binary};
    for(int i=0; i<INT_MAX; i++)
    {
        fi.read(reinterpret_cast<char*>(p),sizeof(Trip));
        if(!fi.eof())
        {
            if(p->Code==a)
            {
                this->Code=p->Code;
                this->setHarkatDate(p->harkatDate.day,p->harkatDate.month,p->harkatDate.year);
                this->setHarkatTime(p->harkatTime.second,p->harkatTime.minute,p->harkatTime.hour);
                this->setMabda(p->mabda);
                this->setMagsad(p->magsad);
                this->setModat(p->modat);
                this->setPrice(p->price);
                this->setSale(p->sale);
                this->setZarf(p->zarf);
            }
        }
        else
        {
            throw TravelNotFount("Eroor : Safar Peyda Nashod!");
            break;
        }
    }
}



void Trip::UpdateTravelInfo()
{
    ofstream fo{"Travels.dat",ios::out|ios::binary};
    fo.seekp(this->Code);
    fo.write(reinterpret_cast<char*>(this),sizeof(Trip));
}




void Trip::SellTicket(string nam)
{
    PurchasedTickets *p;
    if((this->sale)<(this->zarf))
    {
        (this->sale)=(this->sale)+1;
        UpdateTravelInfo();
        ofstream fo{"PurchasedTickets.dat",ios::binary|ios::app};
        fo.write(reinterpret_cast<char*>(&Code),sizeof(int));
        fo.write(reinterpret_cast<char*>(&nam),sizeof(string));
        fo.close();
    }
    else
        throw InvalidTicketCount("Foroshe Bish Az Hade Mojaz(Zarfiat Takmil)!");
}


/*
void Trip::PrintCustomers()
{
    int co;
    char na;
    ifstream fi{"PurchasedTickets.dat",ios::in|ios::binary};
    for(int i=0; i<INT_MAX; i++)
    {
        fi.read(reinterpret_cast<char*>(&co),sizeof(int));
        fi.read(&na,sizeof(na));
        if(!fi.eof())
        {
            if(co==(this->Code))
                cout<<static_cast<char>(na);
        }
    }
}
*/

void Trip::operator + (int a){

	this->zarf=this->zarf+1;
	UpdateTravelInfo();


}
void Trip::operator++() {

	if ((this->sale) == (this->zarf))
		throw InvalidTicketCount("\nBishtar Az Zarfiat!");
	this->sale++;
	UpdateTravelInfo();

}
void Trip::operator--() {

	if (this->sale == 0)
		throw InvalidTicketCount("\nNemitavan");
	else {
		this->sale -= 1;
		UpdateTravelInfo();
	}
}
Trip::Trip()
{
    //ctor
}

Trip::~Trip()
{
    //dtor
}
