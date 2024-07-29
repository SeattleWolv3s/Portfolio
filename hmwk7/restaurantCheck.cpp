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

double getOverallRating(Restaurant restaurant);

int main()
{
    Restaurant r;

    r.name = "McDonalds";
    r.food_quality = 4;
    r.cleanliness = 7;
    r.wait_time = 5;

    r.overall = getOverallRating(r);

    if (r.overall == -1)
    {
        cout << "Invalid rating(s) entered." << endl;
    }
    else
    {
        cout << "Restaurant: " << r.name << " Overall: " << r.overall << endl;
    }

    return 0;
}

double getOverallRating(Restaurant restaurant)
{
    if (restaurant.cleanliness > 10 || restaurant.food_quality > 10 || restaurant.wait_time > 5)
    {
        return -1;
    }
    else 
    {
    double total;
    total = (6.3 * restaurant.food_quality) + (4.3 * restaurant.cleanliness) + (3.4 * (5 - restaurant.wait_time));
    return total;
    }
}