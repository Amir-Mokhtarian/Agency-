#include <iostream>
#include "Trip.h"
#include "PurchasedTickets.h"
#include "Date.h"
#include "Time.h"
#include "LinkList.h"
#include "TravelNotFount.h"
#include "Trip_Rail.h"


using namespace std;

int main()
{
    Date D(6,4,1397);
    Time Ti(12,00,10);
    Trip T("az esfahan","be tehran",D,Ti,30,90,600);
    T.PrintTravelInfo();
    cout<<'\n';
    T.SellTicket("Amir");
    T.PrintTravelInfo();
    cout<<'\n';

    Date D1(7,4,1397);
    Time Ti1(12,01,10);
    Trip T1("az shiraz","be tehran",D1,Ti1,35,120,850);
    T1.PrintTravelInfo();
    Date DR(8,4,1397);
    Time Tr(11,00,10);
    Trip_Rail TR("isfahan ra","tehran ra",DR,Tr,12,150,90,26,4);
    TR.PrintTravelInfo();
    T.SaveInFile();
    cout<<'\n'<<'\n';
    //T.PrintCustomers();
    cout<<"afsasfsadfadsgasgagaghderahgadrghdrahg\n";
    T1.LoadTravelsInContainer();
    cout << "Hello world!" << endl;
    return 0;
}
