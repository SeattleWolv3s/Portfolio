#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int car_A = 75;
    int car_B = 100;
    int car_C = 150;
    int car_D = 200;
    int daily_A = 10;
    int daily_B = 20;
    int daily_C = 30;
    int daily_D = 40;
    char car;
    int days;
    cout << "Which car type (A, B, C, or D) would you like to rent?" << endl;
    cin >> car;
    cout << "How many days would you like to rent this car?" << endl;
    cin >> days;
    if((car != 'A' && car != 'B' && car != 'C' && car != 'D') || days < 0 || cin.fail()) {
        cout << "Please enter a valid input." << endl;
    }
    else {
        if(car == 'A') {
        cout << fixed << setprecision(2) << "Your bill total is $" << (1.21 * (car_A + (days * daily_A))) << endl;
        }
        else if (car == 'B') {
            cout << fixed << setprecision(2) << "Your bill total is $" << (1.21 * (car_B + (days * daily_B))) << endl;
        }
        else if (car == 'C') {
            cout << fixed << setprecision(2) << "Your bill total is $" << (1.21 * (car_C + (days * daily_C))) << endl;
        }
        else if (car == 'D') {
            cout << fixed << setprecision(2) << "Your bill total is $" << (1.21 * (car_D + (days * daily_D))) << endl;
        }
    }
}
