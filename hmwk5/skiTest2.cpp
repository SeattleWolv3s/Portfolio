#include <iostream>
using namespace std;

bool budgetCheck(double budget, char pass);

int main() {
    double budget;
    char pass;
    cout << "Enter your budget:" << endl;
    cin >> budget;
    cout << "Enter the type of pass you wish to check (B, I, A, P):" << endl;
    cin >> pass;
    bool checked;
    checked = budgetCheck(budget, pass);
    if (checked == true) {
        cout << "Yes, this pass is within your budget!" << endl;
        return 0;
    }
    else {
        cout << "Sorry this pass is outside your budget or invalid entry for budget and/or pass entry." << endl;
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