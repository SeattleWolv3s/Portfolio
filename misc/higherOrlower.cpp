#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    int setter =  rand() % 10+1;
    string guess;
    int controlled = 5;
    do {
        cout << "The current value is " << controlled << ", guess higher or lower." << endl;

    } while (controlled != setter);
}