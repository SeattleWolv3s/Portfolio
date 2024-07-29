#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

string getLayer1MessageEncryption(string message, int choice, string key1, string key2);
char shiftChar(char letter, int shift_value);
int getDoubleKeyShiftValue(string key1, string key2);

int main() {
    string message;
    string choose;
    string key1;
    string key2;
    cout << "Enter the message to encrypt :" << endl;
    getline(cin, message);
    cout << "Enter the method choice (1 or 2) :" << endl;
    getline(cin, choose);
    int choice = stoi(choose);
    cout << "Key 1 :" << endl;
    getline(cin, key1);
    cout << "Key 2 :" << endl;
    getline(cin, key2);
    string encrypted = getLayer1MessageEncryption(message, choice, key1, key2);
    cout << "The encrypted message :" << encrypted << endl;
    return 0;
}

string getLayer1MessageEncryption(string message, int choice, string key1, string key2) {
    if (message.length() <=0 || (choice != 1 && choice != 2)) {
        return message;
    }
    else {
        if(choice == 1) {
            for (int i = 0; i <= message.length(); i++) {
                char letter_value = message[i];
                char new_value = shiftChar(letter_value, 13);
                message[i] = new_value;
            }
            string new_message = message;
            return new_message;
        }
        else if (choice == 2) {
            if (key1.length() <= 0 || key2.length() <= 0) {
                return message;
            }
            else {
                int shifter = getDoubleKeyShiftValue(key1, key2);
                for (int i = 0; i <= message.length(); i++) {
                    char letter_value = message[i];
                    char new_value = shiftChar(letter_value, shifter);
                    message[i] = new_value;
                }
            }
            string new_message = message;
            return new_message;
        }
        else {
            return message;
        }
    }
}

char shiftChar(char letter, int shift_value) {
    if(isupper(letter)) {
        int shifted;
       while (shift_value > 26 || shift_value < -26) {
        shift_value = shift_value % 26;
       }
       shifted = letter + shift_value;
       if (shifted > 90) {
        shifted = shifted - 26;
        return shifted;
       }
       else if(shifted < 65) {
        shifted = shifted + 26;
        return shifted;
       }
       else {
        return shifted;
       }
    }
    else if(islower(letter)) {
        int shifted;
        while (shift_value > 26 || shift_value < -26) {
        shift_value = shift_value % 26;
        }
        shifted = letter + shift_value;
        if (shifted > 122) {
        shifted = shifted - 26;
        return shifted;
        }
        else if(shifted < 97) {
        shifted = shifted + 26;
        return shifted;
        }
        else {
        return shifted;
        }
    }
    else {
        return letter;
    }
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
