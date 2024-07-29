#include <iostream>
using namespace std;

char encryptUpper(char shifted, int shift_value);

int main() {
    char shifted;
    int shift_value;
    cout << "Enter an uppercase letter to encrypt:" << endl;
    cin >> shifted;
    cout << "Enter the encryption value:" << endl;
    cin >> shift_value;
    if (shifted <= 122 && shifted >= 92) {
        cout << "Letter " << shifted << " was encrypted to " << shifted << endl;
        return 0;
    }
    else {
        char encryption;
        encryption = encryptUpper(shifted, shift_value);
        if (encryption < 32 || encryption > 126) {
            cout << "Letter " << shifted << " was encrypted to " << shifted << endl;
            return 0;
        }
        else {
            cout << "Letter " << shifted << " was encrypted to " << encryption << endl;
            return 0;
        }
        return 0;
    }
    return 0;
}

char encryptUpper(char shifted, int shift_value) {
    char encryption;
    encryption = shifted + shift_value;
    return encryption;
}