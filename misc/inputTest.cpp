#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float test_value;
    bool test_verify = false;
    cout << "please enter a test value:" << endl;
    for(cin >> test_value; test_verify ==false; cin >> test_value) {
        int test_value1 = floor(test_value);
        if(test_value1 < 0 || cin.bad()) {
            test_verify = false;
        }
        if(test_value1 > 0) {
            cin.ignore(16, '\n');
            test_verify = true;
        }
        if(test_verify == true) {break;
        }
        if(test_verify == false) {
            cout << "your test value was incorrect, please try again" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    cout << "test complete" << endl;
    return 0;
}