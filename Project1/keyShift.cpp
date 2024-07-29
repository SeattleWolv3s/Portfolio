#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

int getDoubleKeyShiftValue(string key1, string key2);

int main() {
    string key1;
    string key2;
    int matching = 0;
    cout << "What is your first key?" << endl;
    getline(cin, key1);
    cout << "what is your second key?" << endl;
    getline(cin, key2);
    matching = getDoubleKeyShiftValue(key1, key2);
    cout << "The shift distance: " << matching << endl;
    return 0;
}

int getDoubleKeyShiftValue(string key1, string key2) {
    if(key1.length() > 0 && key2.length() > 0) {
        int match = -1;
        char first;
        char second;
        for (int i = 0; i <= key1.length(); i++) {
            for (int j = 0; j <= key2.length(); j++) {
                first = key1[i];
                second = key2[j];
                if ( first == second) {match++;}
            }
        }

        if (match > 25) {match -= 26;}
        return match;
    }

    else {
        return 0;
    }
}
