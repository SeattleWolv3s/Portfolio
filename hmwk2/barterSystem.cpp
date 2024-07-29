#include <iostream>
using namespace std;

int main() {
    
    int apple;
    cout << "Enter the number of apples:" << endl;
    cin >> apple;
    int turkey = (apple / 120);
    int apple_1 = apple - (turkey * 120);
    int egg = (apple_1 / 6);
    int apple_2 = apple_1 - (egg * 6);
    int kiwi = (apple_2 / 3); 
    int apple_3 = apple_2 - (kiwi * 3);
    cout << "Maximum number of turkey(s) " << turkey << ", egg(s) " << egg << ", kiwi(s) " << kiwi << ", apple(s)" << apple_3 << endl;

    return 0;
}