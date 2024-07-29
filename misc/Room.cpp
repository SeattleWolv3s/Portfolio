#include "ClassRoom.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Room :: Room()
{
    room_id = "";
    current_occupy = 0;
    current_bookings = 0;
}

Room :: Room(string id)
{
    room_id = id;
    current_bookings = 0;
    current_occupy = 0;
}

void Room :: setRoomID(string id)
{
    room_id = id;
}

string const Room :: getRoomId()
{
    return room_id;
}

void Room :: setNumCurrentOccupants(int num)
{
    current_occupy = num;
}

int const Room :: getNumCurrentOccupants()
{
    return current_occupy;
}

bool Room :: addBooking(string name)
{
    int people = 0;
    for (int i = 0; i < 10; i++)
    {
        people = people + bookings[i].num_people;
    }
    if (people >= 10)
    {
        return false;
    }
    else 
    {
        for (int i = 0; i < 10; i++)
        {
            int tracker = 0;
            if (bookings[i].num_people != 0)
            {
                tracker++;
            }
            else
            {
                ifstream ledger("bookings1.txt");
                string line;
                while (!ledger.eof())
                {
                    getline(ledger, line);
                    string name = "";
                    string number = "";
                    for (int i = 0; i < line.length(); i++)
                    {
                        if (isalpha(line[i]))
                        {
                            name = name + line[i];
                        }
                        else if (isdigit(line[i]))
                        {
                            number = number + line[i];
                        }
                    }
                    int digits = stoi(number);
                    bookings[tracker].name = name;
                    bookings[tracker].num_people = digits;
                    tracker = tracker + 1;
                }
            }
        }
        return true;
    }
}

bool Room :: removeBooking(string name)
{
    for (int i = 0; i < 10; i++)
    {
        if (bookings[i].name == name && bookings[i].num_people != 0)
        {
            bookings[i].name = "";
            bookings[i].num_people = 0;
            return true;
        }
    }
    return false;
}

