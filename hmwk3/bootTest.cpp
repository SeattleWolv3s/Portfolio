#include <iostream>
using namespace std;

int main() {
    int snowfall;
    cout << "What is the amount of snowfall?" << endl;
    if(snowfall < 0 || cin.fail()) {
        cout << "Invalid snowfall amount." << endl;
    }
    else {
    if(snowfall > 5) {
        cout << "You need your snow boots." << endl;
    }
    if(snowfall <5) {
        cout << "You don't need snow boots." << endl;
    }
    }
    
    return 0;
}