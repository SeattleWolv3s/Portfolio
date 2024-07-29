#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double heartVolume(double radius);
double sphereVolume(double radius);

int main() {
    double radius;
    string shape;
    cout << "What shape would you like your candy to be (heart or sphere)?" << endl;
    cin >> shape;
    cout << "What size would you like your candy to be (radius in cm)?" << endl;
    cin >> radius;
    if (cin.fail() || radius < 0) {
        return 0;
    }
    else {
    if (shape == "heart") {
        double volume_h;
        volume_h = heartVolume(radius);
        cout << fixed << setprecision(3) << "The exact volume of your chocalate heart is: " << volume_h << " cm cubed!" << endl;
        return 0; 
    }
    else if (shape == "sphere") {
        double volume_s;
        volume_s = sphereVolume(radius);
        cout << fixed << setprecision(3) << "The exact volume of your mousse truffle sphere is: " << volume_s << " cm cubed!" << endl;
        return 0;
    }
    else {
        return 0;
    }
    }
}

double heartVolume(double radius) {
    double volume;
    double pi = 3.14159;
    volume = (pow(radius, 3) * pi) + (pow(radius, 3) * 4 * sqrt(3));
    return volume;
}

double sphereVolume(double radius) {
    double volume_1;
    double pi = 3.14159;
    volume_1 = ((4 /3) * pi * pow(radius, 3));
    return volume_1;
}
