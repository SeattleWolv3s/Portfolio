#ifndef HOSTEL_H
#define HOSTEL_H
#include "Room.cpp"
#include <iostream>
using namespace std;

class Hostel
{
    public:
    Hostel();
    Hostel(double cost);

    void setCostPerNight(double cost);
    double getCostPerNight();

    void setRoom(int index, Room sleeping_place);
    Room getRoom(int index);
    int findRoom(Booking customer);
    
    bool isAtCapacity();

    double calculateNightlyRevenue();

    private:
    const int _max_rooms = 20;
    double _cost_per_night;
    Room _rooms[20];
};
#endif