#include <iostream>
using namespace std;

int manageFeeder(int feeder, int full_day);

int main() {
    int choice;
    int last_day;
    int check;
    cout << "1. Check Feeder 1" << endl << "2. Check Feeder 2" << endl << "3. Check Feeder 3" << endl << "4. Check All Feeders" << endl << "Enter your choice:" << endl;
    cin >> choice;
    if (cin.fail() || (choice != 1 && choice != 2 && choice != 3 && choice != 4)) {
        cout << "Invalid menu choice!" << endl;
        return 0;
    }
    else if (choice == 4) {
       cout << "How many days ago were all the feeders filled?" << endl;
       cin >> last_day;
       if (last_day < 0) {
        cout << "Invalid input for days_since_last_fill!" << endl;
        cout << "Invalid input for days_since_last_fill!" << endl;
        cout << "Invalid input for days_since_last_fill!" << endl;
        return 0;
       }
       else {
            check = manageFeeder(1, last_day);
            if (check <= 0) {
                cout << "Feeder 1 is currently empty and should be filled immediately." << endl;
            }
            else {
                cout << "Feeder 1 will need to be filled in " << check << " days." << endl;
            }
            check = manageFeeder(2, last_day);
            if (check <= 0) {
                cout << "Feeder 2 is currently empty and should be filled immediately." << endl;
            }
            else {
                cout << "Feeder 2 will need to be filled in " << check << " days." << endl;
            }
            check = manageFeeder(3, last_day);
            if (check <= 0) {
                cout << "Feeder 3 is currently empty and should be filled immediately." << endl;
            }
            else {
                cout << "Feeder 3 will need to be filled in " << check << " days." << endl;
            }
            return 0;
        }
    }
    else {
        if (choice == 1) {
            cout << "How many days ago was feeder 1 filled?" << endl;
            cin >> last_day;
            if (cin.fail() || last_day < 0) {
                cout << "Invalid input for days_since_last_fill!" << endl;
                return 0;
            }
            else {
                check = manageFeeder(1, last_day);
                if (check <= 0) {
                    cout << "Feeder 1 is currently empty and should be filled immediately." << endl;
                    return 0;
                }
                else {
                    cout << "Feeder 1 will need to be filled in " << check << " days." << endl;
                    return 0;
                }
            }
        }
        if (choice == 2) {
            cout << "How many days ago was feeder 2 filled?" << endl;
            cin >> last_day;
            if (cin.fail() || last_day < 0) {
                cout << "Invalid input for days_since_last_fill!" << endl;
                return 0;
            }
            else {
                check = manageFeeder(2, last_day);
                if (check <= 0) {
                    cout << "Feeder 2 is currently empty and should be filled immediately." << endl;
                    return 0;
                }
                else {
                    cout << "Feeder 2 will need to be filled in " << check << " days." << endl;
                    return 0;
                }
            }
        }
        if (choice ==3) {
            cout << "How many days ago was feeder 3 filled?" << endl;
            cin >> last_day;
            if (cin.fail() || last_day < 0) {
                cout << "Invalid input for days_since_last_fill!" << endl;
                return 0;
            }
            else {
                check = manageFeeder(3, last_day);
                if (check <= 0) {
                    cout << "Feeder 3 is currently empty and should be filled immediately." << endl;
                    return 0;
                }
                else {
                    cout << "Feeder 3 will need to be filled in " << check << " days." << endl;
                    return 0;
                }
            }
        }
        return 0;
    }
}

int manageFeeder(int feeder, int full_day) {
    int full;
    int final;
    int ounces;
    int check;
    if (feeder == 1) {
        full = 33;
        final = 2 * full_day;
        ounces = full - final;
        check = ounces / 2;
    }
    if (feeder == 2) {
        full = 27;
        final = 4 * full_day;
        ounces = full - final;
        check = ounces / 4;
    }
    if (feeder == 3) {
        full = 16;
        final = 3 * full_day;
        ounces = full - final;
        check = ounces / 3;
    }
    
    return check;
}