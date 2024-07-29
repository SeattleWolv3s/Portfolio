#include <iostream>
using namespace std;

double useWater(double water_level, double amount);
double refillWater(double water_level, double amount);

int main() {
    double water_level;
    double amount;
    string choice;
    cout << "Do you plan to use or refill the water tank?" << endl;
    cin >> choice;
    cout << "Please provide the current water level:" << endl;
    cin >> water_level;
    cout << "Please enter how much you plan to add or use:" << endl;
    cin >> amount;
    if (cin.fail() || (choice != "Use" && choice != "Refill") || amount < 0 || amount > 100) {
        cout << "Please enter a valid choice." << endl;
        return 0;
    }
    else {
        if (choice == "Use") {
            double left = useWater(water_level, amount);
            cout << "There will be " << left << "% remaining in the water tank." << endl;
            return 0;
        }
        else {
            double current = refillWater(water_level, amount);
            cout << "There is " << current << "% now in the water tank." << endl;
            return 0;
        }
    }
    return 0;
}

double useWater(double water_level, double amount) {
    double left = (water_level - amount);
    if (left <= 0) {
        cout << "The amount you entered exceeds the amount of water available." << endl;
        return 0;
    }
    else {
    return left;
    }
}

double refillWater(double water_level, double amount) {
    double current = (water_level + amount);
    if (current >= 100) {
        cout << "The amount of water you added exceeds the capacity of the water tank." << endl;
        return 0;
    }
    else {
    return current;
    }
}