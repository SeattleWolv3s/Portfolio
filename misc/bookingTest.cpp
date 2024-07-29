#include <iostream>
#include <iomanip>
using namespace std;

struct Booking
{
    string name;
    int num_people;
};

void displayBooking(Booking bookings[], int num_bookings);

int main()
{
    Booking booking1, booking2, booking3;
    booking1.name = "Frederick";
    booking2.name = "Timothy";
    booking3.name = "Johnson";
    booking1.num_people = 4;
    booking2.num_people = 8;
    booking3.num_people = 2;
    int num_bookings = 3;
    Booking bookings[3] = {booking1, booking2, booking3};
    displayBooking(bookings, num_bookings);
    return 0;
}

void displayBooking(Booking bookings[], int num_bookings)
{
    for (int i = 0; i < num_bookings; i++)
    {
        cout << bookings[i].name << " " << bookings[i].num_people << endl;
    }
}