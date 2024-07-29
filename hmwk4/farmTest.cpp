#include <iostream> 
using namespace std;

double calculateFarmArea(double length, double width);
double calculateSeedCost(double area, double seeds);
double calculateSowingTime(double farm_area, double sowing);

int main() {
    int choice;
    cout << "1. Calculate Farm Area" << endl << "2. Calculate Seeds Cost" << endl << "3. Estimate Sowing Time" << endl << "4. Exit" << endl;
    cin >> choice;
    if (cin.fail() || (choice != 1 && choice != 2 && choice != 3 && choice != 4)) {
        cout << "Menu choice is invalid." << endl;
        return 0;
    }
    else {
        int n = choice;
        switch (n) {
            case 1 :
            double length;
            double width;
            double total_area;
            cout << "Enter length of the farmland in ft:" << endl;
            cin >> length;
            cout << "Enter width of the farmland in ft:" << endl;
            cin >> width;
            if (cin.fail() || length <= 0 || width <= 0) {
                cout << "Length or width is invalid. Area cannot be calculated." << endl;
                return 0;
            }
            else {
            total_area = calculateFarmArea(length, width);
            if (total_area <= 0) {
                cout << "Length or width is invalid. Area cannot be calculated." << endl;
                return 0;
            }
            else {
                cout << "The area is: " << total_area << " sq ft." << endl;
                return 0;
            }
            }
                break;

            case 2 :
                char grade;
                double area; 
                cout << "Enter area of the farmland in sq ft:" << endl;
                cin >> area;
                cout << "Enter the grade of seed to be used:" << endl;
                cin >> grade;
                double seeds;
                if (cin.fail() || (grade != 'A' && grade != 'B' && grade != 'C') || (area <= 0)) {
                    cout << "Area or seed grade is invalid. Cost cannot be calculated." << endl;
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
                break;

            case 3 :
                double farm_area;
                char machine;
                cout << "Enter area of the farmland in sq ft:" << endl;
                cin >> farm_area;
                cout << "Enter the type of sowing machine to be used:" << endl;
                cin >> machine;
                double sowing;
                if (cin.fail() || (machine != 'W' && machine != 'X' && machine != 'Y' && machine != 'Z') || farm_area <= 0) {
                    cout << "Area or machine type is invalid. Time cannot be calculated." << endl;
                    return 0;
                }
                else {
                    if(machine == 'W') {sowing = 2.4;}
                    if(machine == 'X') {sowing = 3.333333333333;}
                    if(machine == 'Y') {sowing = 2.5;}
                    if(machine == 'Z') {sowing = 2.14285714;}
                    double timing = calculateSowingTime(farm_area, sowing);
                    cout << "The time taken is: " << timing << " minutes." << endl;
                    return 0;
                }
                break;

            case 4 :
            cout << "You have chosen to exit. Thank you!" << endl;
            return 0;
        }
        return 0;
    }
    return 0;
}

double calculateFarmArea(double length, double width) {
    double total_area = length * width;
    return total_area;
}

double calculateSeedCost(double seeds, double area) {
    double cost = (seeds * area);
    return cost;
}

double calculateSowingTime(double farm_area, double sowing) {
    double timing = (farm_area * sowing);
    return timing;
}