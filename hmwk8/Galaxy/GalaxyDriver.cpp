#include <iostream>
#include "Galaxy.h"
#include "Galaxy.cpp"
using namespace std;

string findGalaxyWithLargestAverageRadius(Galaxy galaxies[], const int ARR_SIZE);


int main()
{
    const int ARR_SIZE = 3;
    int radii_1[3] = {10, 20, 30};
    int radii_2[4] = {10, 20, 30, 40};
    int radii_3[4] = {20, 40, 10, 10};
    Galaxy galaxy_1 = Galaxy("Andromeda", radii_1, 3);
    Galaxy galaxy_2 = Galaxy("MilkyWay", radii_2, 4);
    Galaxy galaxy_3 = Galaxy("Orion", radii_3, 4);
    Galaxy galaxies[ARR_SIZE] = {galaxy_1, galaxy_2, galaxy_3};
    cout << findGalaxyWithLargestAverageRadius(galaxies, ARR_SIZE) << endl;
    return 0;
}

string findGalaxyWithLargestAverageRadius(Galaxy galaxies[], const int ARR_SIZE)
{
    int huge = galaxies[0].getAverageRadius();
    int watcher = huge;
    string hog = galaxies[0].getName();
    for (int i = 0; i < ARR_SIZE; i++)
    {
        if (galaxies[i].getAverageRadius() != huge && galaxies[i].getAverageRadius() > huge)
        {
            huge = galaxies[i].getAverageRadius();
        }
        if (huge != watcher)
        {
            hog = galaxies[i].getName();
            watcher = huge;
        }
    }
    return hog;
}

