#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float water;
    cout << "How much water did you drink today? (in liters)" << endl;
    cin >> water;
    double remaining = 3.0 - water;
    if(water <= 0 || cin.fail()) {
        cout << "Please enter valid amount." << endl;
        return 0;
    }
    else {
    if(water < 1.5) {
        cout << fixed << setprecision(2) << "You're very, very dehydrated! Get that water in! You have " << remaining << " liters left to drink." << endl;
    }
    else if (water < 3 && water > 1.5) {
        cout << fixed << setprecision(2) << "You're doing great, but you still have " << ((remaining / 3) * 100) << "% remaining. Get that water in! You have " << remaining << " liters left to drink." << endl;
    }
    else {
        cout << fixed << setprecision (2) << "You've hit your goal for the day! Great job getting hydrated!" << endl;
    }
    }
    return 0;
}