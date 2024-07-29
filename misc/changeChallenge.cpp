#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float change;
    bool verify = false;
    cout << "How much change do you have?" << endl;
    for(cin >> change; verify == false; cin >> change) {
        int true_change = floor(change);
        if(true_change < 0 || cin.bad()) {
            verify = false;
        }
        if(true_change >0) {
            verify = true;
        }
        if(verify == false) {
            cout << "The amount of change you entered is not a valid amount. Please try again:" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        if(verify == true) {
            change = true_change;
            break;
        }
    }
    int dollars = (change / 100);
    int spare_change1 = (change - (dollars * 100));
    int quarters = (spare_change1 / 25);
    int spare_change2 = (spare_change1 - (quarters * 25));
    int dimes = (spare_change2 / 10);
    int spare_change3 = (spare_change2 - (dimes * 10));
    int nickels = (spare_change3 / 5);
    int spare_change4 = (spare_change3 - (nickels * 5));
    cout << "You have " << dollars << " dollar(s), " << quarters << " quarter(s), " << dimes << " dime(s), " << nickels << " nickel(s), " << " and " << spare_change4 << " pennies." << endl; 
    return 0;
}