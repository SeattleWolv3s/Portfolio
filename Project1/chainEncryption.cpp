#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

string getChainEncryption(string message, int method_choice, string key1, string key2, string key_phrase);
string getLayer2MessageEncryption(string message, string key_phrase);
char shiftChar(char letter, int shift_value);
int getDoubleKeyShiftValue(string key1, string key2);
string getLayer1MessageEncryption(string message, int choice, string key1, string key2);

int main() {
    string message;
    string key_phrase;
    string key1;
    string key2;
    string method_choice;
    cout << "Enter the message to encrypt :" << endl;
    getline(cin, message);
    cout << "Enter method choice (1 or 2) :" << endl;
    getline(cin, method_choice);
    int choice = stoi(method_choice);
    cout << "Enter the first key :" << endl;
    getline(cin, key1);
    cout << "Enter the second key :" << endl;
    getline(cin, key2);
    cout << "Enter the key phrase :" << endl;
    getline(cin, key_phrase);
    string encryption = getChainEncryption(message, choice, key1, key2, key_phrase);
    cout << "The encrypted message : " << encryption << endl;
    return 0;
}

string getChainEncryption(string message, int method_choice, string key1, string key2, string key_phrase) {
    for (int i = 0; i < key_phrase.length(); i++) {
        if (!isalpha(key_phrase[i]) && key_phrase[i] != ' ' && key_phrase[i] != '.' && key_phrase[i] != '!' && key_phrase[i] != '?' && key_phrase[i] != '+' && !isdigit(key_phrase[i]) ) {
            return message;
        }
    }
    if (method_choice == 1) {
        if (message.length() > 0 && key_phrase.length() > 0) {
            string encrypted = getLayer1MessageEncryption(message, 1, key1, key2);
            string full_encrypted = getLayer2MessageEncryption(encrypted, key_phrase);
            return full_encrypted;
        }
        else {
            return message;
        }
    }
    else if (method_choice == 2) {
        if (message.length() > 0 && key1.length() > 0 && key2.length() > 0 && key_phrase.length() > 0) {
            string encrypted = getLayer1MessageEncryption(message, 2, key1, key2);
            string full_encrypted = getLayer2MessageEncryption(encrypted, key_phrase);
            return full_encrypted;
        }
        else {
            return message;
        }
    }
    else {
        return message;
    }
}

string getLayer2MessageEncryption(string message, string key_phrase) {
    if (message.length() > 0) {
        string new_message;
        string fragment;
        int entry = 1;
        if (key_phrase.length() > 0) {
                for (int i = 0; i < key_phrase.length(); i++) {
                    if(!isalpha(key_phrase[i]) && key_phrase[i] != ' ' && !(key_phrase[i] > 38 && key_phrase[i] < 47) && !isdigit(key_phrase[i])) {
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
                        int shift_value = fragment[0] - 65;
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
                                    int shift_value = fragment[j] - 65;
                                    if (shift_value == 0) {
                                        new_message[i] = message[i];
                                    }
                                    else if (shift_value > 0) {
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
