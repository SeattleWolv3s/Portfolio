#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Restaurant 
{
    string name;
    int food_quality;
    int cleanliness;
    int wait_time;
    double overall;
};

int readRestaurantDetails(string filename, Restaurant restaurants[], const int MAX_RESTAURANTS);


int main()
{
    const int MAX_RESTAURANTS = 30;

    string restaurants_filename = "restaurants.txt";
    Restaurant restaurants[MAX_RESTAURANTS];

    int res_size = readRestaurantDetails(restaurants_filename, restaurants, MAX_RESTAURANTS);

    // Checking if the file was opened correctly
    if (res_size == -1)
    {
        cout << "Failed to open file." << endl;
    }
    else
    {
        for (int i = 0; i < res_size; ++i) {
            cout << "Restaurant: " << restaurants[i].name << " ";
            cout << "Ratings: ";
            cout << restaurants[i].food_quality << " ";
            cout << restaurants[i].cleanliness<< " ";
            cout << restaurants[i].wait_time << " ";
            cout << "Overall: ";
            cout << restaurants[i].overall << " ";
            cout << endl;
        }
    }

    return 0;
}

int readRestaurantDetails(string filename, Restaurant restaurants[], const int MAX_RESTAURANTS)
{
    ifstream food_list(filename);
    if (food_list.fail())
    {
        return -1;
    }
    else 
    {
        int tracker = 0;
        while (!food_list.eof())
        {
            string place;
            getline(food_list, place);

            int name = 0;
            while (place[name] != '~')
            {
                if (place[name] != '~')
                {
                    name = name + 1;
                }
                else 
                {
                    break;
                }
            }
            if (place.length() > name + 7 || place.substr(name).length() < 5)
            {
                restaurants[tracker].name = "";
                restaurants[tracker].cleanliness = 0;
                restaurants[tracker].food_quality = 0;
                restaurants[tracker].wait_time = 0;
            }
            else 
            {
            restaurants[tracker].name = place.substr(0, name);
            int value1 = place[name + 1] - '0';
            int value2 = place[name + 3] - '0';
            int value3 = place[name + 5] - '0';
            if (!isdigit(place[name + 3]))
            {
                string holder = place.substr((name + 1), 2);
                value1 = stoi(holder);
                value2 = place[name + 4] - '0';
                value3 = place[name + 6] - '0';
            }
            else if (!isdigit(place[name + 5]))
            {
                string holder = place.substr((name + 3), 2);
                value2 = stoi(holder);
                value3 = place[name + 6] - '0';
            }
            restaurants[tracker].food_quality = value1;
            restaurants[tracker].cleanliness = value2;
            restaurants[tracker].wait_time = value3;
            restaurants[tracker].overall = (6.3 * restaurants[tracker].food_quality) + (4.3 * restaurants[tracker].cleanliness) + (3.4 * (5 - restaurants[tracker].wait_time));
            tracker = tracker + 1;
            }
        }
        return tracker;
    }
}