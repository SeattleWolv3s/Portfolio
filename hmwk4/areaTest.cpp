#include <iostream>
using namespace std;

double calculateFarmArea(double length, double width);

double calculateFarmArea(double length, double width) {
    double area = length * width;
    return area;
}

int main() {
    double length;
    double width;
    cout << "Enter length of the farmland in ft:" << endl;
    cin >> length;
    cout << "Enter width of the farmland in ft:" << endl;
    cin >> width;
    if (cin.fail() || length <= 0 || width <= 0 ) {
        cout << "Length or width is invalid. Area cannot be calculated." << endl;
        return 0;
    }
    else {
    double area = calculateFarmArea(length, width);
    if (area <= 0) {
        cout << "Length or width is invalid. Area cannot be calculated." << endl;
        return 0;
    }
    else {
        cout << "The area is: " << area << " sq ft." << endl;
        return 0;
    }
    }
    return 0;
}
