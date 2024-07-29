#include <iostream>
#include <string>
using namespace std;

string getChainDecryption(string message, int method_choice, string key1, string key2, string key_phrase);
string getLayer1MessageDecryption(string encrypted_message, int choice, string key1, string key2);
char shiftChar(char letter, int shift_value);
int getDoubleKeyShiftValue(string key1, string key2);
string getLayer2MessageDecryption(string message, string key_phrase);
string getChainEncryption(string message, int method_choice, string key1, string key2, string key_phrase);
string getLayer2MessageEncryption(string message, string key_phrase);
string getLayer1MessageEncryption(string message, int choice, string key1, string key2);

int main() {
    int choice = 1;
    string message;
    string key1;
    string key2;
    string key_phrase;
    string menu_choice;
    string method_choice;
    int shift_choice = 0;
    int shift_value = 0;
    string menu0 = "Please input 1-7 followed by enter to navigate the menu:"; 
    string menu1 = "1. Set Encryption Key 1";
    string menu2 = "2. Set Encryption Key 2";
    string menu3 = "3. Set Key Phrase";
    string menu4 = "4. Select Encryption Method";
    string menu5 = "5. Encrypt Message";
    string menu6 = "6. Decrypt Message";
    string menu7 = "7. Exit Program";
    cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
    do {
    do {
        getline(cin, menu_choice);
        int menu = stoi(menu_choice);
        choice = menu;
        if (menu > 7 || menu < 1 || cin.fail()) {
            cout << "Invalid input" << endl;
            menu = -5000;
            cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
            getline(cin, menu_choice);
        }
        else {
            if (menu == 1) {
                cout << "Enter First key:" << endl;
                getline(cin, key1);
                if (key1.length() > 0) {
                    int length = key1.length();
                    for (int i = 0; i < length; i++) {
                        if (i == 0) {
                            if (!isalpha(key1[i])) {
                                cout << "Invalid key" << endl;
                                i = 0;
                                cout << "Enter First key:" << endl;
                                getline(cin, key1);
                                length = key1.length();
                            }
                        }
                        else {
                            if ((!isalpha(key1[i]) && key1[i] != ' ')) {
                                cout << "Invalid key" << endl;
                                cout << "Enter First key:" << endl;
                                getline(cin, key1);
                                length = key1.length();
                                cout << length << endl;
                            }
                        }
                    }
                    cout << "Successfully set first encryption key to " << key1 << endl;
                    cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
                }
                else {
                    cout << "Invalid key" << endl;
                    key1 = "/";
                    cout << "Enter First key:" << endl;
                    getline(cin, key1);
                }
                
            }
            else if (menu == 2) {
                cout << "Enter second key:" << endl;
                getline(cin, key2);
                if (key2.length() > 0 && !cin.fail()) {
                        for (int i = 0; i < key2.length(); i++) {
                            if (i == 0) {
                                if (!isalpha(key2[i])) {
                                    cout << "Invalid key" << endl;
                                    cout << "Enter second key:" << endl;
                                    getline(cin, key2);
                                }
                            }
                            else if (i > 0) {
                            if ((!isalpha(key2[i] && int(key2[i]) != 32))) {
                                cout << "Invalid key" << endl;
                                cout << "Enter First key:" << endl;
                                i = i - 1;
                                getline(cin, key1);
                            }
                        }
                    }
                    cout << "Successfully set second encryption key to " << key2 << endl;
                    cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
                }
                else {
                    cout << "Invalid key" << endl;
                    key1 = "/";
                    cout << "Enter second key:" << endl;
                    getline(cin, key2);
                }
            }
            else if (menu == 3) {
                cout << "Enter keyphrase:" << endl;
                getline(cin, key_phrase);
                for (int i = 0; i < key_phrase.length(); i++) {
                    while ((!isalpha(key_phrase[i]) && !isdigit(key_phrase[i]) && key_phrase[i] != ' ')) {
                        cout << "Invalid keyphrase" << endl;
                        getline(cin, key_phrase);
                    }
                }
                cout << "Successfully set encryption keyphrase to " << key_phrase << endl;
                cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
            }
            else if (menu == 4) {
                int technique = 1;
                do {
                cout << "Please input 1-3 to decide encryption technique." << endl << "1. Layer 1 Message Encryption" << endl << "2. Layer 2 Message Encryption" << endl << "3. Chain Encryption" << endl;
                string tech_choice;
                getline(cin, tech_choice);
                technique = stoi(tech_choice);
                if (technique == 1 || technique == 2 || technique == 3) {
                    if (technique == 1) {
                        cout << "Please input 1-2 to decide Layer-1 encryption technique." << endl << "1. Shift by 13" << endl << "2. Shift by mixed keys" << endl;
                        string layer1tech;
                        getline(cin, layer1tech);
                        int l1t = stoi(layer1tech);
                        if (l1t == 1 || l1t == 2) {
                            if (l1t == 1) {
                                shift_value = 1;
                                cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
                            }
                            if (l1t == 2) {
                                shift_value = 2;
                                cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
                            }

                        }
                        else {
                            cout << "Invalid encryption choice" << endl;
                            layer1tech = "0";
                            getline(cin, layer1tech);
                        }
                        cout << "Successfully set encryption type to " << technique << endl;
                        cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
                    }
                    else if (technique == 2) {
                        cout << "Successfully set encryption type to " << technique << endl;
                        cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
                    }
                    else if (technique == 3) {
                        cout << "Please input 1-2 to decide Layer-1 encryption technique." << endl << "1. Shift by 13" << endl << "2. Shift by mixed keys" << endl;
                        string layer1tech;
                        getline(cin, layer1tech);
                        int l1t = stoi(layer1tech);
                        if (l1t == 1 || l1t == 2) {
                            if (l1t == 1) {
                                shift_value = 1;
                                cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
                            }
                            if (l1t == 2) {
                                shift_value = 2;
                                cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
                            }
                        }
                        else {
                            cout << "Invalid encryption choice" << endl;
                            getline(cin, layer1tech);
                            l1t = stoi(layer1tech);
                        }
                        cout << "Successfully set encryption type to " << technique << endl;
                        cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
                    }
                    shift_choice = technique;
                }
                else {
                    cout << "Invalid encryption choice" << endl;
                }
                } while (technique != 1 && technique != 2 && technique != 3);
            }
            else if (menu == 5) {
                if (key1.length() > 0 && key2.length() > 0 && key_phrase.length() > 0 && shift_value != 0) {
                    cout << "Enter your message to encrypt:" << endl;
                    getline(cin, message);
                    string encrypted;
                    if (shift_choice == 1) {
                        encrypted = getLayer1MessageEncryption(message, shift_value, key1, key2);
                    }
                    else if (shift_choice == 2) {
                        encrypted = getLayer2MessageEncryption(message, key_phrase);
                    }
                    else if (shift_choice == 3) {
                        encrypted = getChainEncryption(message, shift_value, key1, key2, key_phrase);
                    }
                    cout << encrypted << endl;
                    cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
                }
                else {
                    cout << "You cannot do this until you set both keys, keyphrase, and choose an encryption technique" << endl;
                    menu = 0;
                    cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
                }
            }
            else if (menu == 6) {
                if (key1.length() > 0 && key2.length() > 0 && key_phrase.length() > 0 && shift_value != 0) {
                    cout << "Enter your message to encrypt:" << endl;
                    getline(cin, message);
                    string decrypted;
                    if (shift_choice == 1) {
                        decrypted = getLayer1MessageDecryption(message, shift_value, key1, key2);
                    }
                    else if (shift_choice == 2) {
                        decrypted = getLayer2MessageDecryption(message, key_phrase);
                    }
                    else if (shift_choice == 3) {
                        decrypted = getChainDecryption(message, shift_value, key1, key2, key_phrase);
                    }
                    cout << decrypted << endl;
                    cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
                }
                else {
                    cout << "You cannot do this until you set both keys, keyphrase, and choose an encryption technique" << endl;
                    menu = 0;
                    cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
                }

            }
            else if (menu == 7) {
                cout << "Goodbye." << endl;
                return 0;
            }
        }

    } while (choice > 7 || choice < 1);
    } while (choice != 7);
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

string getChainDecryption(string message, int method_choice, string key1, string key2, string key_phrase) {
    for (int i = 0; i < key_phrase.length(); i++) {
        if (!isalpha(key_phrase[i]) && key_phrase[i] != ' ' && key_phrase[i] != '.' && key_phrase[i] != '!' && key_phrase[i] != '?' && key_phrase[i] != '+' && !isdigit(key_phrase[i]) ) {
            return message;
        }
    }
    if (method_choice == 1) {
        if (message.length() > 0 && key_phrase.length() > 0) {
            string encrypted = getLayer1MessageDecryption(message, 1, key1, key2);
            string full_encrypted = getLayer2MessageDecryption(encrypted, key_phrase);
            return full_encrypted;
        }
        else {
            return message;
        }
    }
    else if (method_choice == 2) {
        if (message.length() > 0 && key1.length() > 0 && key2.length() > 0 && key_phrase.length() > 0) {
            string encrypted = getLayer1MessageDecryption(message, 2, key1, key2);
            string full_encrypted = getLayer2MessageDecryption(encrypted, key_phrase);
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

string getLayer2MessageDecryption(string message, string key_phrase) {
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

string getLayer1MessageDecryption(string message, int choice, string key1, string key2) {
    if (message.length() <=0 || (choice != 1 && choice != 2)) {
        return message;
    }
    else {
        if(choice == 1) {
            for (int i = 0; i <= message.length(); i++) {
                char letter_value = message[i];
                char new_value = shiftChar(letter_value, -13);
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
                int shifter = -getDoubleKeyShiftValue(key1, key2);
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

