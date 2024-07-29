#ifndef GALAXY_H
#define GALAXY_H
#include <iostream>
using namespace std;

class Galaxy
{
    public:
    Galaxy();
    Galaxy(string named);
    Galaxy(string named, int radii[], int planet_count);

    string const getName();
    int const getCurrentSize();
    void setName(string named);
    const int getRadius(int planet);

    bool addRadius(int current_planets);

    double getAverageRadius();

    private:
    string _name;
    const static int _max_size = 10;
    int _radii[_max_size];
    int _current_planets;
};
#endif