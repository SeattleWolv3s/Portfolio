#include <iostream>
#include <array>
using namespace std;

int main() {
    char car;
    char test[] = {'A','B','C','D'}; 
    cin >> car;
    if(car != test) {
        return 0;
    }
    else {
        cout << "Success" << endl;
    }
    return 0;
}