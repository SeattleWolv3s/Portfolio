#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double calculateDistance(double x1, double x2, double y1, double y2, int distance_type);

int main() {
    double x1;
    double x2;
    double y1;
    double y2;
    int type;
    cout << "Enter distance type:" << endl;
    cin >> type;
    cout << "Enter x1:" << endl;
    cin >> x1;
    cout << "Enter y1:" << endl;
    cin >> y1;
    cout << "Enter x2:" << endl;
    cin >> x2;
    cout << "Enter y2:" << endl;
    cin >> y2;
    if(cin.fail() || (type != 1 && type != 2)) {
        cout << "Invalid distance type!" << endl;
        return 0;
    }
    else {
        if (cin.fail()) {
            cout << "Calculation failure!" << endl;
            return 0;
        }
        else {
            double range;
            range = calculateDistance(x1, x2, y1, y2, type);
            cout << fixed << setprecision(3) << "The distance between the points is: " << range << endl;
            return 0;
        }
        return 0;
    }
}

double calculateDistance(double x1, double x2, double y1, double y2, int distance_type) {
    double distance;
    if (distance_type == 1){
        distance = ((abs(x2 - x1)) + (abs(y2 - y1)));
    }
    else {
        distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }
    return distance;
}
