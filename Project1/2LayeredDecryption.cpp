#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

string getLayer2MessageDecryption(string message, string key_phrase);
char shiftChar(char letter, int shift_value);

int main() {
    string message;
    string key_phrase;
    cout << "Enter the message to decrypt :" << endl;
    getline(cin, message);
    cout << "Enter the key phrase :" << endl;
    getline(cin, key_phrase);
    string decryption = getLayer2MessageDecryption(message, key_phrase);
    cout << "Decrypted message is: " << decryption << endl;
    return 0;
}

string getLayer2MessageDecryption(string message, string key_phrase) {
    if (message.length() > 0) {
        string new_message;
        string fragment;
        int entry = 1;
        if (key_phrase.length() > 0) {
                for (int i = 0; i < key_phrase.length(); i++) {
                    if(!isalpha(key_phrase[i]) && key_phrase[i] != ' ' && !(key_phrase[i] > 38 && key_phrase[i] < 47)) {
                        return message;
                    }
                    else {
                        if (!isupper(key_phrase[i]) && key_phrase[i] != ' ') {
                            key_phrase[i] = key_phrase[i] - 32;
                        }
                    }
                }
                fragment[0] = key_phrase[0];
                for (int i = 0; i < key_phrase.length(); i++) {
                    if (key_phrase[i] == ' ') {
                        fragment[entry] = key_phrase[i + 1];
                        entry++;
                    }
                    fragment += fragment[i];
                }
                for (int i = 0; i < message.length(); i++) {
                    char new_letter;
                    if (entry == 1) {
                        int shift_value = -1 * (fragment[0] - 65);
                        if (isalpha(message[i])) {
                        new_letter = shiftChar(message[i], shift_value);
                        }
                        else {
                            new_letter = message[i];
                        }
                        new_message[i] = new_letter;
                    }
                    else if(entry > 1) {
                        if (isalpha(message[i])) {
                            int measure = 0;
                            for (int k = 0; k < i + 1; k++) {
                                if (message[k] == ' ' || !isalpha(message[k])) {
                                    measure ++;
                                }
                            }
                            for (int j = 0; j < entry; j++) {
                                if ( j < ((i - measure) % entry) + 1) {
                                    int shift_value = -1 * (fragment[j] - 65);
                                    if (shift_value == 0) {
                                        new_message[i] = message[i];
                                    }
                                    else if (shift_value > 0 || shift_value < 0) {
                                    new_letter = shiftChar(message[i], shift_value);
                                    new_message[i] = new_letter;
                                    }
                                }
                                else {
                                    
                                }
                            }
                        }
                        else {
                            new_letter = message[i];
                            new_message[i] = new_letter;
                        }
                    }
                    new_message += new_message[i];
                }
                return new_message;
        }
        else {
            return message;
        }
    }
    else {
        return message;
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
