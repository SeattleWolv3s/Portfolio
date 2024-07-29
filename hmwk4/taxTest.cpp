#include <iostream>
using namespace std;

int main() {
    string tax_type;
    float income;
    cout << "What is the tax type?" << endl;
    cin >> tax_type;
    cout << "What is your income?" << endl;
    cin >> income;
    if (cin.fail() || (tax_type != "state" && tax_type !=  "federal")) {
        cout << "Invalid tax type." << endl;
        return 0;
    }
    else {
        if (cin.fail() || income <= 0) {
            cout << "Income cannot be negative or zero." << endl;
            return 0;
        }
        else {
            int n;
            if (tax_type == "state") {n = 1;}
            if (tax_type == "federal") {n = 2;}
            switch (n) {
                case 1 :
                    if (income >= 5000) {
                        cout << "You are required to pay $" << (income * 0.045) << " in taxes" << endl; 
                        return 0;
                    }
                    else {
                        cout << "You are not required to pay taxes" << endl;
                        return 0;
                    }
                break; 
                case 2 :
                if (income >= 11000) {
                    cout << "You are required to pay $" << (income * 0.22) << " in taxes" << endl;
                }
                else {
                    cout << "You are required to pay $" << (income * 0.11) << " in taxes" << endl;
                }
                break; 
            }
        }

    }
    return 0;
}