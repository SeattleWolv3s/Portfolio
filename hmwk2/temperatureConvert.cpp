#include <iostream> 
using namespace std;

int main() {
    int temp_f;
    cout << "What is the temperature in Fahrenheit?" << endl; 
    cin >> temp_f; 
    cout << "The temperature is "<< (temp_f - 32) * (5.0 / 9.0)<< " degrees Celsius." << endl;
    return 0; 
}