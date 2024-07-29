#include <iostream>
using namespace std;

double calculateSeedCost(double seeds, double area);

int main () {
    char grade;
    double area; 
    cout << "Enter the area of the farmland in sq ft:" << endl;
    cin >> area;
    cout << "Enter the grade of seed to be used:" << endl;
    cin >> grade;
    double seeds;
    if (cin.fail() || (grade != 'A' && grade != 'B' && grade != 'C') || (area <= 0)) {
        cout << "Area or seed grade is invalid. Cost cannot be calculated" << endl;
        return 0;
    }
    else {
        if (grade == 'A') {seeds = 7.5;}
        if (grade == 'B') {seeds = 12.5;}
        if (grade == 'C') {seeds = 27.5;}
        double cost = calculateSeedCost(seeds, area);
        cout << "The cost is: $" << cost << endl;
        return 0;
    }
    return 0;
}

double calculateSeedCost(double seeds, double area) {
    double cost = (seeds * area);
    return cost;
}