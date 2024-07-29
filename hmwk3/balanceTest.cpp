#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double balance = 30;
    double withdrawal; 
    cout << "How much would you like to withdraw?" << endl;
    cin >> withdrawal;
    if((balance - withdrawal) >= 20 && withdrawal > 0) {
        cout << fixed << setprecision(2) << "Your transaction was successful! Your remaining balance is $" << balance - withdrawal << endl;
    }
    else {
        cout << "Transaction failed!" << endl;
    }
}