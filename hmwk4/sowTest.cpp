#include <iostream>
using namespace std;

double calculateSowingTime(double area, double sowing);

int main() {
    double area;
    char machine;
    cout << "Enter area of the farmland in sq ft:" << endl;
    cin >> area;
    cout << "Enter the type of sowing machine to be used:" << endl;
    cin >> machine;
    double sowing;
    if (cin.fail() || (machine != 'W' && machine != 'X' && machine != 'Y' && machine != 'Z') || area <= 0) {
        cout << "Area or machine type is invalid. Time cannot be calculated." << endl;
        return 0;
    }
    else {
        if(machine == 'W') {sowing = 2.4;}
        if(machine == 'X') {sowing = 3.33;}
        if(machine == 'Y') {sowing = 2.5;}
        if(machine == 'Z') {sowing = 2.14;}
        double timing = calculateSowingTime(area, sowing);
        cout << "The time taken is: " << timing << " minutes." << endl;
        return 0;
    }
    return 0;
}

double calculateSowingTime(double area, double sowing) {
    double timing = ((area * sowing));
    return timing;
}