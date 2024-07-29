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
    string shift_choice;
    int shift_value = 0;
    int encrypt_choice = 0;
    string menu0 = "Please input 1-7 followed by enter to navigate the menu:"; 
    string menu1 = "1. Set Encryption Key 1";
    string menu2 = "2. Set Encryption Key 2";
    string menu3 = "3. Set Key Phrase";
    string menu4 = "4. Select Encryption Method";
    string menu5 = "5. Encrypt Message";
    string menu6 = "6. Decrypt Message";
    string menu7 = "7. Exit Program";

    do {

            int menu = 0;

            int test = 0;

        do {
            cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;

            getline(cin, menu_choice);

            while (menu_choice.length() == 0 || menu_choice.length() > 1) {

                cout << "Invalid input" << endl;

                cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;

                menu_choice = "";

                getline(cin, menu_choice);

            }

            while (!isdigit(menu_choice[0])) {

                cout << "Invalid input" << endl;

                cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;

                menu_choice = "";

                getline(cin, menu_choice);

            }

            test = stoi(menu_choice);
            
            if (!(test < 8 && test > 0)) {
            cout << "Invalid input" << endl;
            }

        } while (!(test < 8 && test > 0));

        menu = stoi(menu_choice);

        choice = menu;

            if (menu == 1) {

                cout << "Enter First key:" << endl;

                getline(cin, key1);

                while (key1.length() == 0) {

                    cout << "Invalid key" << endl;

                    cout << "Enter First key:" << endl;

                    getline(cin, key1);

                }

                while (int(key1[0]) == 32 || int(key1[0]) == 0) {

                    cout << "Invalid key" << endl;

                    key1 = "";

                    cout << "Enter First key:" << endl;

                    getline(cin, key1);

                }

                int i = 1;

                     while (!isalpha(key1[i]) && key1[i] != ' ' && !isdigit(key1[i])) {

                        cout << "Invalid key" << endl;

                        cout << "Enter First key:" << endl;

                        getline(cin, key1);

                        i++;

                    }

                cout << "Successfully set first encryption key to " << key1 << endl;



            }

            else if (menu == 2) {

                cout << "Enter Second key:" << endl;

                getline(cin, key2);

                while (key2.length() == 0) {

                    cout << "Invalid key" << endl;

                    cout << "Enter Second key:" << endl;

                    getline(cin, key2);

                }

                while (int(key2[0]) == 32 || int(key2[0]) == 0) {

                    cout << "Invalid key" << endl;

                    key2 = "";

                    cout << "Enter Second key:" << endl;

                    getline(cin, key2);

                }

                int i = 1;

                     while (!isalpha(key2[i]) && key2[i] != ' ' && !isdigit(key2[i])) {

                        cout << "Invalid key" << endl;

                        cout << "Enter Second key:" << endl;

                        getline(cin, key2);

                        i++;

                    }

                cout << "Successfully set second encryption key to " << key2 << endl;

 

            }

            else if (menu == 3) {

                    cout << "Enter keyphrase:" << endl;

                    getline(cin, key_phrase);

                    while (key_phrase.length() == 0) {
                        
                        cout << "Invalid key" << endl;

                        key_phrase = "";

                        cout << "Enter keyphrase:" << endl;

                        getline(cin, key_phrase);

                    }

                    while (!isalpha(key_phrase[0])) {

                        cout << "Invalid key" << endl;

                        key_phrase = "";

                        cout << "Enter keyphrase:" << endl;

                        getline(cin, key_phrase);

                    }

                    for (int i = 0; i < key_phrase.length(); i++) {

                        while (key_phrase.length() == 0) {
                            
                            cout << "Invalid key" << endl;

                            key_phrase = "";

                            cout << "Enter keyphrase:" << endl;

                            getline(cin, key_phrase);

                        }

                        while (!isalpha(key_phrase[0])) {

                            cout << "Invalid key" << endl;

                            key_phrase = "";

                            cout << "Enter keyphrase:" << endl;

                            getline(cin, key_phrase);

                        }

                        while (!isalpha(key_phrase[i]) && key_phrase[i] != ' ') {

                        cout << "Invalid key" << endl;

                        key_phrase = "";

                        cout << "Enter keyphrase:" << endl;

                        getline(cin, key_phrase);

                        }

                    }

                cout << "Successfully set encryption keyphrase to " << key_phrase << endl;

            }

            else if (menu == 4) {

                int test1 = 0;

                do {
                    cout << "Please input 1-3 to decide encryption technique." << endl << "1. Layer 1 Message Encryption" << endl << "2. Layer 2 Message Encryption" << endl << "3. Chain Encryption" << endl;

                    getline(cin, method_choice);

                    while (method_choice.length() == 0 || method_choice.length() > 1) {

                        cout << "Invalid input" << endl;

                        cout << "Please input 1-3 to decide encryption technique." << endl << "1. Layer 1 Message Encryption" << endl << "2. Layer 2 Message Encryption" << endl << "3. Chain Encryption" << endl;

                        method_choice = "";

                        getline(cin, method_choice);

                    }

                    while (!isdigit(method_choice[0])) {

                        cout << "Invalid input" << endl;

                        cout << "Please input 1-3 to decide encryption technique." << endl << "1. Layer 1 Message Encryption" << endl << "2. Layer 2 Message Encryption" << endl << "3. Chain Encryption" << endl;

                        menu_choice = "";

                        getline(cin, method_choice);

                    }

                    test1 = stoi(method_choice);
                    
                    if (!(test1 < 4 && test1 > 0)) {
                    cout << "Invalid input" << endl;
                    }

                } while (!(test1 < 4 && test1 > 0));

                int Layer1Choice = stoi(method_choice);

                cout << "Successfully set encryption type to " << Layer1Choice << endl;

                if (Layer1Choice == 1 || Layer1Choice == 3) {

                    int test2 = 0;

                    do {
                        cout << "Please input 1-2 to decide Layer-1 encryption technique." << endl << "1. Shift by 13" << endl << "2. Shift by mixed keys" << endl;

                        getline(cin, shift_choice);

                        while (shift_choice.length() == 0 || shift_choice.length() > 1) {

                            cout << "Invalid input" << endl;

                            cout << "Please input 1-2 to decide Layer-1 encryption technique." << endl << "1. Shift by 13" << endl << "2. Shift by mixed keys" << endl;

                            shift_choice = "";

                            getline(cin, shift_choice);

                        }

                        while (!isdigit(shift_choice[0])) {

                            cout << "Invalid input" << endl;

                            cout << "Please input 1-2 to decide Layer-1 encryption technique." << endl << "1. Shift by 13" << endl << "2. Shift by mixed keys" << endl;

                            shift_choice = "";

                            getline(cin, shift_choice);

                        }

                        test2 = stoi(shift_choice);
                        
                        if (test2 != 1 && test2 != 2) {
                        cout << "Invalid input" << endl;
                        }

                    } while (test2 != 1 && test2 != 2);

                    shift_value = stoi(shift_choice);

                }
            
            }

            else if (menu == 5) {

                if (key1.length() > 0 && key2.length() > 0 && key_phrase.length() > 0 && shift_value != 0) {

                    cout << "Enter your message to encrypt:" << endl;

                    getline(cin, message);

                    string encrypted;

                    if (encrypt_choice == 1) {

                        encrypted = getLayer1MessageEncryption(message, shift_value, key1, key2);

                    }

                    else if (encrypt_choice == 2) {

                        encrypted = getLayer2MessageEncryption(message, key_phrase);

                    }

                    else if (encrypt_choice == 3) {

                        encrypted = getChainEncryption(message, shift_value, key1, key2, key_phrase);

                    }

                    cout << encrypted << endl;

                    

                }

                else {
                    cout << "You cannot do this until you set both keys, keyphrase and choose an encryption method" << endl;

                    menu = 0;

                    

                }

            }

            else if (menu == 6) {

                if (key1.length() > 0 && key2.length() > 0 && key_phrase.length() > 0 && shift_value != 0) {

                    cout << "Enter your message to encrypt:" << endl;

                    getline(cin, message);

                    string decrypted;

                    if (encrypt_choice == 1) {

                        decrypted = getLayer1MessageDecryption(message, shift_value, key1, key2);

                    }

                    else if (encrypt_choice == 2) {

                        decrypted = getLayer2MessageDecryption(message, key_phrase);

                    }

                    else if (encrypt_choice == 3) {

                        decrypted = getChainDecryption(message, shift_value, key1, key2, key_phrase);

                    }

                    cout << decrypted << endl;

                    cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;

                }

                else {

                    cout << "You cannot do this until you set both keys, keyphrase and choose an encryption method" << endl;

                    menu = 0;

                    cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;

                }

            }

            else if (menu == 7) {

                cout << "Goodbye." << endl;

                return 0;

            }

    } while (choice < 8 && choice > 0);

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

