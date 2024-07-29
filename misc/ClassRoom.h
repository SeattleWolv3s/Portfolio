#ifndef CLASSROOM_H
#define CLASSROOM_H
#include <iostream>
using namespace std;
struct Booking
{
    string name;
    int num_people;
};
class Room
{
    public:
    Room ();
    Room(string id);

    void setRoomID(string id);
    string const getRoomId();

    void setNumCurrentOccupants (int num);
    int const getNumCurrentOccupants();

    bool addBooking(string name);
    bool removeBooking(string name);

    private:
    string room_id;
    int current_occupy;
    int current_bookings;
    Booking bookings[10];
};
#endif  