#include <iostream>
using namespace std;

int main() {
    int temperature;
    int wind_speed;
    cout << "What is tomorrow's temperature looking like?" << endl;
    cin >> temperature;
    cout << "What is tomorrow's wind speed looking like?" << endl;
    cin >> wind_speed;
    if(wind_speed < 0 || cin.fail()) {
        cout << "Please enter valid input." << endl;
    }
    else {
    if(temperature <= 10 && temperature >= -10 && wind_speed <= 20) {
        cout << "The weather conditions are ideal for photography tomorrow." << endl;
    }
    if(temperature > 10 || temperature < -10 || wind_speed > 20) {
        cout << "The weather conditions are not ideal for photography tomorrow." << endl;
    }
    }
    return 0;
}