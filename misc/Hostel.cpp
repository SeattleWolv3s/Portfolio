#include "Hostel.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

    Hostel :: Hostel()
    {
        _cost_per_night = 0;
    }

    Hostel :: Hostel(double cost)
    {
        _cost_per_night = cost;
    }

    void Hostel :: setCostPerNight(double cost)
    {
        _cost_per_night = cost;
    }

    double Hostel :: getCostPerNight()
    {
        return _cost_per_night;
    }

    void Hostel :: setRoom(int index, Room sleeping_place)
    {
        _rooms[index] = sleeping_place;
    }

    Room Hostel :: getRoom(int index)
    {
        return _rooms[index];
    }

    int Hostel :: findRoom(Booking customer)
    {
        int rats = -1;
        for (int i = 0, i < _max_rooms; i++)
        {
            if(10 - _rooms[i].getNumCurrentOccupants() >= customer.num_people)
            {
                rats = i;
            }
        }
        return rats;
    }
    
    bool Hostel :: isAtCapacity()
    {
        bool space = true; 
        for (int i = 0; i < _max_rooms; i++)
        {
            if (_rooms[i].getNumCurrentOccupants == 10)
            {
                space = true;
            }
            else 
            {
                space = false;
            }
        }
        return space;
    }

    double Hostel :: calculateNightlyRevenue()
    {
        double revenue = 0;
        for (int i = 0; i < _max_rooms; i++)
        {
            revenue = revenue + (_rooms[i].getNumCurrentOccupants * _cost_per_night);
        }
        return revenue;
    }

    //spot the error
    // 2.1 order1.orderID should be order1.orderid or orderid should be changed to orderID
    // 2.2 replaces same item twice and references to orderID in cout statements should be written as order1.orderID
    // 2.3 the updateCustomerAddress function should be a void function and should not return a value as it manipulates an array reference
