#include <iostream>
using namespace std;

int main() {
    float amount; 
    float time; 
    float rate; 
    float simple_interest; 
    cout << "Enter the principal amount:" << endl;
    cin >> amount; 
    cout << "Enter rate of interest" << endl;
    cin >> rate; 
    cout << "Enter time (in years):" << endl;
    cin >> time;
    simple_interest = (amount * rate * time)/100; 
    cout << "Simple interest: " << simple_interest << endl;
    return 0; 
}