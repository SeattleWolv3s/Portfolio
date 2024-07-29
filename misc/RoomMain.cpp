#include "ClassRoom.h"
#include "Room.cpp"
#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
    Room b("125");
    cout << b.getRoomId() << endl;
    bool test = b.addBooking("bookings1.txt");
    if (test == true) 
    {
        cout << "Success" << endl;
    }
    else
    {
        cout << "Fail" << endl;
    }
    bool tester = b.removeBooking("Hank");
    if (tester == true)
    {
        cout << "Removed successfuly" << endl;
    }
    else 
    {
        cout << "Fail" << endl;
    }
    return 0;
}