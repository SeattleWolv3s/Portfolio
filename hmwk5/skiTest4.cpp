#include <iostream>
#include <cassert>
using namespace std;

bool budgetCheck(double budget, char pass);
double purchasePass(double budget, char pass);

int main() {
    double budget;
    char pass;
    cout << "Enter your budget:" << endl;
    cin >> budget;
    cout << "Enter the type of pass you wish to purchase ('B', 'I', 'A', 'P'):" << endl;
    cin >> pass;
    bool checked;
    checked = budgetCheck(budget, pass);
    if (checked == true) {
       double receipt;
       receipt = purchasePass(budget, pass);
       if (receipt != budget) {
        cout << "Pass purchased successfully. Updated budget: $" << receipt << endl;
       double receipt_2;
       receipt_2 = purchasePass(receipt, pass);
       if (receipt_2 != receipt) {
        cout << "Another pass purchased for your friend. Remaining budget: $" << receipt_2 << endl;
        return 0;
       }
       else {
        cout << "Insufficient budget to purchase another pass for your friend." << endl;
        return 0;
       }
       }
       else {
        cout << "Sorry, this pass is outside your budget or invalid entry for budget and/or pass type." << endl;
        return 0;
       }
    }
    else {
        cout << "Sorry, this pass is outside your budget or invalid entry for budget and/or pass type." << endl;
        return 0;
    }
    return 0;
}

bool budgetCheck(double budget, char pass) {
    double pass_type;
    bool check;
    if (cin.fail() || (budget < 0) || (pass != 'B' && pass != 'I' && pass != 'A' && pass != 'P')) {
        check = false;
    }
    else {
    if (pass == 'B') {pass_type = 250.15;}
    if (pass == 'I') {pass_type = 479.85;}
    if (pass == 'A') {pass_type = 684.29;}
    if (pass == 'P') {pass_type = 950.33;}
    if (budget >= pass_type) {
        check = true;
    }
    else {
        check = false;
    }
    }
    return check;
}

double purchasePass(double budget, char pass) {
    double pass_type;
    double receipt;
    if (pass == 'B') {pass_type = 250.15;}
    if (pass == 'I') {pass_type = 479.85;}
    if (pass == 'A') {pass_type = 684.29;}
    if (pass == 'P') {pass_type = 950.33;}
    receipt = budget - pass_type;
    if (receipt < 0) {
        return budget;
    }
    else {
        return receipt;
    }
}
