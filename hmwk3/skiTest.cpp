#include <iostream>
using namespace std;

int main() {
    double basic = 250.15;
    double intermediate = 479.85;
    double advanced = 684.29;
    double platinum = 950.33;
    double budget;
    char pass;
    cout << "What is your budget?" << endl;
    cin >> budget;
    cout << "Which of these passes would you like to take (B, I, A, P)?" << endl;
    cin >> pass;
    if( (pass != 'B' && pass != 'I' && pass != 'A' && pass != 'P') || budget < 0 || cin.fail()) {
        cout << "Please enter a valid input." << endl;
    }
    else {
    if( pass == 'B' && budget >= basic) {
        cout << "This pass is within your budget!" << endl;
    }
    else if ( pass == 'I' && budget >= intermediate) {
        cout << "This pass is within your budget" << endl;
    }
    else if ( pass == 'A' && budget >= advanced) {
        cout << "This pass is within your budget" << endl;
    }
    else if ( pass == 'P' && budget >= platinum) {
        cout << "This pass is within your budget" << endl;
    }
    else if ( pass == 'B' && budget < basic) {
        cout << "Sorry, this pass is outside your budget." << endl;
    }
    else if ( pass == 'I' && budget < intermediate) {
        cout << "Sorry, this pass is outside your budget." << endl;
    }
    else if ( pass == 'A' && budget < advanced) {
        cout << "Sorry, this pass is outside your budget." << endl;
    }
    else if ( pass == 'P' && budget < platinum) {
        cout << "Sorry, this pass is outside your budget." << endl;
    }
    }
    return 0;
}