#include <iostream>
using namespace std;

string getColor(int birthmonth);
double getArea(string shape, double size);
double getCost(double area, string color);

int main() {
    int month;
    string shape;
    double size;
    double area;
    string color;
    double cost;
    cout << "Enter your birthmonth:" << endl;
    cin >> month;
    cout << "Enter the Shape of your coaster (square or circle):" << endl;
    cin >> shape;
    cout << "Enter the length of your coaster, or radius for circular coasters (in):" << endl;
    cin >> size;
    color = getColor(month);
    if (color == "fail") {
        return 0;
    }
    else {
    area = getArea(shape, size);
    if (area == 0) {
        return 0;
    }
    else {
    cost = getCost(area, color);
    cout << "The cost of your coaster is: $" << cost << endl;
    }
    }
    return 0;
}

string getColor(int birthmonth) {
    string color;
    if (birthmonth <1 || birthmonth > 12) {
        return color = "fail";
    }
    else {
        if (birthmonth >= 1 && birthmonth <= 3) {color = "green";}
        if (birthmonth >= 4 && birthmonth <= 6) {color = "red";}
        if (birthmonth >= 7 && birthmonth <= 9) {color = "orange";}
        if (birthmonth >= 10 && birthmonth <= 12) {color = "blue";}
        return color;
    }
}

double getArea(string shape, double size) {
    if ((shape != "square" && shape != "circle") || size < 0) {
        return 0;
    }
    else {
        double pi = 3.14159;
        double area;
        if (shape == "square") {area = size * size;}
        if (shape == "circle") {area = pi * size * size;}
        return area;
    }
}

double getCost(double area, string color) {
    double cost_per;
    double cost;
    if (color == "green") {cost_per = 4;}
    if (color == "red") {cost_per = 3;}
    if (color == "orange") {cost_per = 2;}
    if (color == "blue") {cost_per = 1;}
    cost = area * cost_per;
    return cost;
}

