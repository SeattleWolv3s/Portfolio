#include <iostream>
#include <string>
using namespace std;

//Functions used to alter characters or entire strings
string getChainDecryption(string message, int method_choice, string key1, string key2, string key_phrase);
string getLayer1MessageDecryption(string encrypted_message, int choice, string key1, string key2);
char shiftChar(char letter, int shift_value);
int getDoubleKeyShiftValue(string key1, string key2);
string getLayer2MessageDecryption(string message, string key_phrase);
string getChainEncryption(string message, int method_choice, string key1, string key2, string key_phrase);
string getLayer2MessageEncryption(string message, string key_phrase);
string getLayer1MessageEncryption(string message, int choice, string key1, string key2);

int main() 
{
    //variable used to maintain dowhile loop that allows main to repeat
    int choice = 1;
    //Strings that receive user input and must be verified
    string message;
    string key1;
    string key2;
    string key_phrase;
    string menu_choice;
    string method_choice;
    string shift_choice;
    //values used to determine what type of encryption/decryption is used
    int shift_value = 0;
    int encrypt_choice = 0;
    //abbreviated initial message for convenience
    string menu0 = "Please input 1-7 followed by enter to navigate the menu:"; 
    string menu1 = "1. Set Encryption Key 1";
    string menu2 = "2. Set Encryption Key 2";
    string menu3 = "3. Set Key Phrase";
    string menu4 = "4. Select Encryption Method";
    string menu5 = "5. Encrypt Message";
    string menu6 = "6. Decrypt Message";
    string menu7 = "7. Exit Program";
    //keeps loop repeating while the users choice is valid and prevents accidental breakage or return0's
    do 
    {
        //menu is used as the switch variable, determining what menu option is picked, test is used to test what menu would be
            int menu = 0;
            int test = 0;
        // until test is between 1 and 7, it will continue to prompt user input, contains a variety of verifications like only digits, and length caps
        do 
        {
            // present menu and initial decision
            cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
            getline(cin, menu_choice);
            // caps the input to one character, limiting incorrect input options
            while (menu_choice.length() == 0 || menu_choice.length() > 1) 
            {
                cout << "Invalid input" << endl;
                cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
                menu_choice = "";
                getline(cin, menu_choice);
            }
            //until the character is a digit, user will be prompted to reenter
            while (!isdigit(menu_choice[0])) 
            {
                cout << "Invalid input" << endl;
                cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl << menu7 << endl;
                menu_choice = "";
                getline(cin, menu_choice);
            }
            //converts the user input into an integer and if it is not a valid option, outputs invalid and resets loop
            test = stoi(menu_choice);
            
            if (!(test < 8 && test > 0)) 
            {
            cout << "Invalid input" << endl;
            }

        } while (!(test < 8 && test > 0));
        //declaration of menu value and setting choice to menu so the dowhile loop continues
        menu = stoi(menu_choice);
        choice = menu;

            if (menu == 1) 
            {
                // prompt user for first key input
                cout << "Enter First key:" << endl;
                getline(cin, key1);
                //if the key length is zero, it will prompt until length is not 0
                while (key1.length() == 0) 
                {
                    cout << "Invalid key" << endl;
                    cout << "Enter First key:" << endl;
                    getline(cin, key1);
                }
                //verifies that the key does not start with a space or null character
                while (int(key1[0]) == 32 || int(key1[0]) == 0) 
                {
                    cout << "Invalid key" << endl;
                    key1 = "";
                    cout << "Enter First key:" << endl;
                    getline(cin, key1);
                }
                // arbitrary starting value
                int i = -1;
                // determines where the below while loop should start for the key and prevents errors from 1 character keys
                if (key1.length() == 1) 
                {
                    i = 0;
                }

                else 
                {
                    i = 1;
                }
                //somewhat of a makeshift for loop that tests every value of the key individually to make sure they are valid and can reset more freely than a for loop
                while (!isalpha(key1[i]) && key1[i] != ' ' && !isdigit(key1[i])) 
                {
                    cout << "Invalid key" << endl;
                    cout << "Enter First key:" << endl;
                    getline(cin, key1);
                    i++;
                }
                //tells user that key input was a success
                cout << "Successfully set first encryption key to " << key1 << endl;
            }

            else if (menu == 2) 
            {
                //input verification for key 2 is the same as key 1, view above comments for explanation
                cout << "Enter Second key:" << endl;
                getline(cin, key2);

                while (key2.length() == 0) 
                {
                    cout << "Invalid key" << endl;
                    cout << "Enter Second key:" << endl;
                    getline(cin, key2);
                }

                while (int(key2[0]) == 32 || int(key2[0]) == 0) 
                {
                    cout << "Invalid key" << endl;
                    key2 = "";
                    cout << "Enter Second key:" << endl;
                    getline(cin, key2);
                }

                int i = -1;

                if (key2.length() == 1) 
                {
                    i = 0;
                }

                else 
                {
                    i = 1;
                }

                while (!isalpha(key2[i]) && key2[i] != ' ' && !isdigit(key2[i])) 
                {
                    cout << "Invalid key" << endl;
                    cout << "Enter Second key:" << endl;
                    getline(cin, key2);
                    i++;
                }

                cout << "Successfully set second encryption key to " << key2 << endl;

            }

            else if (menu == 3) 
            {
                    //prompts user for a keyphrase
                    cout << "Enter keyphrase:" << endl;
                    getline(cin, key_phrase);
                    //prevents keyphrase from being 0 characters
                    while (key_phrase.length() == 0) 
                    {
                        cout << "Invalid keyphrase" << endl;
                        key_phrase = "";
                        cout << "Enter keyphrase:" << endl;
                        getline(cin, key_phrase);
                    }
                    //prevents keyphrase from starting as a non-letter
                    while (!isalpha(key_phrase[0])) 
                    {
                        cout << "Invalid keyphrase" << endl;
                        key_phrase = "";
                        cout << "Enter keyphrase:" << endl;
                        getline(cin, key_phrase);
                    }
                    //applies above tests to every value of keyphrase
                    for (int i = 0; i < key_phrase.length(); i++) 
                    {
                        //length cannot be zero
                        while (key_phrase.length() == 0) 
                        {
                            cout << "Invalid keyphrase" << endl;
                            key_phrase = "";
                            cout << "Enter keyphrase:" << endl;
                            getline(cin, key_phrase);
                        }
                        //cannot start as a non letter
                        while (!isalpha(key_phrase[0])) 
                        {
                            cout << "Invalid keyphrase" << endl;
                            key_phrase = "";
                            cout << "Enter keyphrase:" << endl;
                            getline(cin, key_phrase);
                        }
                        //any given value must be a letter or a space
                        while (!isalpha(key_phrase[i]) && key_phrase[i] != ' ') 
                        {
                        cout << "Invalid keyphrase" << endl;
                        key_phrase = "";
                        cout << "Enter keyphrase:" << endl;
                        getline(cin, key_phrase);
                        }

                    }
                //verifies successful keyphrase entry
                cout << "Successfully set encryption keyphrase to " << key_phrase << endl;

            }

            else if (menu == 4) 
            {
                //arbitrary integer used for testing
                int test1 = 0;
                //repeats user input until an acceptable answer is provided
                do 
                {
                    //prompt user input
                    cout << "Please input 1-3 to decide encryption technique." << endl << "1. Layer 1 Message Encryption" << endl << "2. Layer 2 Message Encryption" << endl << "3. Chain Encryption" << endl;
                    getline(cin, method_choice);
                    //input is a digit so only one character inputs are accepted
                    while (method_choice.length() == 0 || method_choice.length() > 1) 
                    {
                        cout << "Invalid encryption choice" << endl;
                        cout << "Please input 1-3 to decide encryption technique." << endl << "1. Layer 1 Message Encryption" << endl << "2. Layer 2 Message Encryption" << endl << "3. Chain Encryption" << endl;
                        method_choice = "";
                        getline(cin, method_choice);
                    }
                    //input must be a number
                    while (!isdigit(method_choice[0])) 
                    {
                        cout << "Invalid encryption choice" << endl;
                        cout << "Please input 1-3 to decide encryption technique." << endl << "1. Layer 1 Message Encryption" << endl << "2. Layer 2 Message Encryption" << endl << "3. Chain Encryption" << endl;
                        menu_choice = "";
                        getline(cin, method_choice);
                    }
                    //tests to see if the input is 1 2 or 3 and outputs invalid if not then resets loop
                    test1 = stoi(method_choice);
                    
                    if (!(test1 < 4 && test1 > 0)) 
                    {
                    cout << "Invalid encryption choice" << endl;
                    }

                } while (!(test1 < 4 && test1 > 0));
                //sets one variable within menu choice 4 and one outside menu choice 4 to the input
                //for use within menu choice 4
                int Layer1Choice = stoi(method_choice);
                //used in options 5 and 6
                encrypt_choice = Layer1Choice;
                //verifies successful input
                cout << "Successfully set encryption type to " << Layer1Choice << endl;
                //the two options that use character shifting, so the shift value must be determined
                if (Layer1Choice == 1 || Layer1Choice == 3) 
                {

                    int test2 = 0;

                    do 
                    {
                        //repeats until acceptable input is provided
                        cout << "Please input 1-2 to decide Layer-1 encryption technique." << endl << "1. Shift by 13" << endl << "2. Shift by mixed keys" << endl;
                        getline(cin, shift_choice);
                        //input must be a single character
                        while (shift_choice.length() == 0 || shift_choice.length() > 1) 
                        {
                            cout << "Invalid encryption choice" << endl;
                            cout << "Please input 1-2 to decide Layer-1 encryption technique." << endl << "1. Shift by 13" << endl << "2. Shift by mixed keys" << endl;
                            shift_choice = "";
                            getline(cin, shift_choice);
                        }
                        //input must be a number
                        while (!isdigit(shift_choice[0])) 
                        {
                            cout << "Invalid encryption choice" << endl;
                            cout << "Please input 1-2 to decide Layer-1 encryption technique." << endl << "1. Shift by 13" << endl << "2. Shift by mixed keys" << endl;
                            shift_choice = "";
                            getline(cin, shift_choice);
                        }
                        //tests if number provided is an acceptable answer, outputs invalid and resets loop if not
                        test2 = stoi(shift_choice);
                        
                        if (test2 != 1 && test2 != 2) 
                        {
                        cout << "Invalid encryption choice" << endl;
                        }

                    } while (test2 != 1 && test2 != 2);
                    //sets the shift value equal to 1 or 2 once successful, to be used in 5 and 6 
                    shift_value = stoi(shift_choice);

                }
                //assigns arbitrary value to shift value for the method of decryption where it is not needed to prevent inconsistencies
                else if (Layer1Choice == 2) 
                {
                    shift_value = 3;
                }
            
            }

            else if (menu == 5) 
            {
                //verifying that all previous inputs have been provided 
                if (key1.length() > 0 && key2.length() > 0 && key_phrase.length() > 0 && shift_value != 0) 
                {
                    //prompt for user input and initializing final output variable
                    cout << "Enter your message to encrypt:" << endl;
                    getline(cin, message);
                    string encrypted;
                    //callback to menu choice made in 4, what type of encryption would like to be made
                    if (encrypt_choice == 1) 
                    {
                        //provides 1 layer of encryption using a single shift value determined by embedded functions
                        encrypted = getLayer1MessageEncryption(message, shift_value, key1, key2);
                    }

                    else if (encrypt_choice == 2) 
                    {
                        //provides 1 layer of encryption by encrypting each letter from an alternating value out of a key string
                        encrypted = getLayer2MessageEncryption(message, key_phrase);
                    }

                    else if (encrypt_choice == 3) 
                    {
                        //provides 2 layers of encryption using layer1 type first and then layer2 before returning
                        encrypted = getChainEncryption(message, shift_value, key1, key2, key_phrase);
                    }
                    //return the new string
                    cout << encrypted << endl;
                    
                }
                //if not all prior inputs are provided, returns them to menu screen
                else 
                {
                    cout << "You cannot do this until you set both keys, keyphrase and choose an encryption method" << endl;
                    menu = 0;
                }

            }

            else if (menu == 6) {
                //inverse of 5, any form of encryption is instead decryption
                if (key1.length() > 0 && key2.length() > 0 && key_phrase.length() > 0 && shift_value != 0) 
                {
                    cout << "Enter your message to decrypt:" << endl;
                    getline(cin, message);
                    string decrypter;

                    if (encrypt_choice == 1) 
                    {
                        decrypter = getLayer1MessageDecryption(message, shift_value, key1, key2);
                    }

                    else if (encrypt_choice == 2) 
                    {
                        decrypter = getLayer2MessageDecryption(message, key_phrase);
                    }

                    else if (encrypt_choice == 3) 
                    {
                        decrypter = getChainDecryption(message, shift_value, key1, key2, key_phrase);
                    }

                    cout << decrypter << endl;

                }

                else 
                {

                    cout << "You cannot do this until you set both keys, keyphrase and choose an encryption method" << endl;
                    menu = 0;
                }

            }
            //allows the user to terminate the program once finished 
            else if (menu == 7) 
            {
                cout << "Goodbye." << endl;
                return 0;
            }
    //repeats while choice is valid
    } while (choice < 8 && choice > 0);
    //if that loop is broken, the program terminates automatically
    return 0;
}

string getChainEncryption(string message, int method_choice, string key1, string key2, string key_phrase) 
{
    //verifying that every character of the key phrase is a letter, valid symbol, or space, if not it returns the original message
    for (int i = 0; i < key_phrase.length(); i++) 
    {

        if (!isalpha(key_phrase[i]) && key_phrase[i] != ' ' && key_phrase[i] != '.' && key_phrase[i] != '!' && key_phrase[i] != '?' && key_phrase[i] != '+' && !isdigit(key_phrase[i]) ) 
        {
            return message;
        }

    }
    //the encryption choice from the main function, decides what values to use for encryption
    if (method_choice == 1) 
    {
        //verifying the message and key phrase are real
        if (message.length() > 0 && key_phrase.length() > 0) 
        {
            string encrypted = getLayer1MessageEncryption(message, 1, key1, key2);
            string full_encrypted = getLayer2MessageEncryption(encrypted, key_phrase);
            return full_encrypted;
        }

        else 
        {
            return message;
        }

    }
    else if (method_choice == 2) 
    {

        if (message.length() > 0 && key1.length() > 0 && key2.length() > 0 && key_phrase.length() > 0) 
        {
            string encrypted = getLayer1MessageEncryption(message, 2, key1, key2);
            string full_encrypted = getLayer2MessageEncryption(encrypted, key_phrase);
            return full_encrypted;
        }

        else
        {
            return message;
        }

    }

    else 
    {
        return message;
    }

}

string getLayer2MessageEncryption(string message, string key_phrase) 
{
    //verifying message is real
    if (message.length() > 0) 
    {
        //initializing strings to be used in the function and returned
        string new_message;
        string fragment;
        int entry = 1;
        //verifying key phrase is real
        if (key_phrase.length() > 0) 
        {
                //tests every value of the key phrase and returns the message if any value is not a letter, space, number, or accepted symbol
                for (int i = 0; i < key_phrase.length(); i++) 
                {

                    if(!isalpha(key_phrase[i]) && key_phrase[i] != ' ' && !(key_phrase[i] > 38 && key_phrase[i] < 47) && !isdigit(key_phrase[i])) 
                    {
                        return message;
                    }

                    else 
                    {
                        // capitalizes every letter and ignores non-letters
                        if (!isupper(key_phrase[i]) && key_phrase[i] != ' ') 
                        {
                            key_phrase[i] = key_phrase[i] - 32;
                        }

                    }

                }
                //because there is no space before the first letter, the key must be manually set for value 0
                fragment[0] = key_phrase[0];
                //tests the key phrase, for any space, the next value in the key string (fragment) will be the letter immediately following, ignores non-letters
                for (int i = 0; i < key_phrase.length(); i++) 
                {

                    if (key_phrase[i] == ' ') 
                    {

                        if(isalpha(key_phrase[i + 1])) 
                        {
                        fragment[entry] = key_phrase[i + 1];
                        entry++;
                        }

                    }

                    fragment += fragment[i];

                }
                //takes the message and converts every letter from the key to a shifting value and then applies the values in a repeating cycle (i.e. 1,2,3,4,1,2,3,4)
                for (int i = 0; i < message.length(); i++) 
                {
                    char new_letter;
                    //if there is only one key value, it is applied to every letter
                    if (entry == 1) 
                    {
                        int shift_value = fragment[0] - 65;

                        if (isalpha(message[i])) 
                        {
                        new_letter = shiftChar(message[i], shift_value);
                        }

                        else 
                        {
                            new_letter = message[i];
                        }

                        new_message[i] = new_letter;

                    }
                    //if the key has multiple values, the key value will increase and be added as long as it does not go over the modulo of the letter, preventing too many cycles of shifts
                    else if(entry > 1) 
                    {

                        if (isalpha(message[i])) 
                        {
                            int measure = 0;

                            for (int k = 0; k < i + 1; k++) 
                            {

                                if (message[k] == ' ' || !isalpha(message[k])) 
                                {
                                    measure ++;
                                }

                            }

                            for (int j = 0; j < entry; j++) 
                            {

                                if ( j < ((i - measure) % entry) + 1) 
                                {
                                    int shift_value = fragment[j] - 65;

                                    if (shift_value == 0) 
                                    {
                                        new_message[i] = message[i];
                                    }

                                    else if (shift_value > 0) 
                                    {
                                    new_letter = shiftChar(message[i], shift_value);
                                    new_message[i] = new_letter;
                                    }

                                }

                            }

                        }

                        else 
                        {
                            new_letter = message[i];
                            new_message[i] = new_letter;
                        }

                    }
                    //summing all of the new message values from the above loops into a single string
                    new_message += new_message[i];

                }
                //returning the new string
                return new_message;
        
        }
        // if the intial verifications fail, the original message is returned 
        else 
        {
            return message;
        }

    }

    else 
    {
        return message;
    }

}
//function designed to shift a single character by a specific amount while keeping it within the alphabet
char shiftChar(char letter, int shift_value) 
{
    //determines what ascii values should be used as parameters
    if(isupper(letter)) 
    {
        int shifted;
        // if the shift value goes over a full rotation through the alphabet, this wraps the shift back around
       while (shift_value > 26 || shift_value < -26) 
       {
        shift_value = shift_value % 26;
       }

       shifted = letter + shift_value;

       if (shifted > 90) 
       {
        shifted = shifted - 26;
        return shifted;
       }

       else if(shifted < 65) 
       {
        shifted = shifted + 26;
        return shifted;
       }

       else 
       {
        return shifted;
       }

    }
    //same as above but for lower case letters, different ascii parameters
    else if(islower(letter))
    {
        int shifted;

        while (shift_value > 26 || shift_value < -26) 
        {
        shift_value = shift_value % 26;
        }

        shifted = letter + shift_value;

        if (shifted > 122) 
        {
        shifted = shifted - 26;
        return shifted;
        }

        else if(shifted < 97) 
        {
        shifted = shifted + 26;
        return shifted;
        }

        else 
        {
        return shifted;
        }

    }

    else 
    {
        return letter;
    }

}
//function to make use of the shiftChar and DoubleKeyShift functions automatically
string getLayer1MessageEncryption(string message, int choice, string key1, string key2) 
{
    //verification for provided arguments, else return message
    if (message.length() <=0 || (choice != 1 && choice != 2)) 
    {
        return message;
    }

    else 
    {
        // if the user chooses method 1, it shifts all characters by 13
        if(choice == 1) 
        {

            for (int i = 0; i <= message.length(); i++) 
            {
                char letter_value = message[i];
                char new_value = shiftChar(letter_value, 13);
                message[i] = new_value;
            }

            string new_message = message;
            return new_message;

        }
        //if the user chooses method 2, it verifies both keys before measuring the similarities between them using DoubleKeyShift and using that as a shift value
        else if (choice == 2) 
        {

            if (key1.length() <= 0 || key2.length() <= 0) 
            {
                return message;
            }

            else 
            {
                int shifter = getDoubleKeyShiftValue(key1, key2);
                //repeats the shift for every character
                for (int i = 0; i <= message.length(); i++) 
                {
                    char letter_value = message[i];
                    char new_value = shiftChar(letter_value, shifter);
                    message[i] = new_value;
                }

            }
            //sets a new value to return to main function
            string new_message = message;
            return new_message;
        }
        //for input verification failure
        else     
        {
            return message;
        }

    }

}
//inverse of chainEncryption
string getChainDecryption(string message, int method_choice, string key1, string key2, string key_phrase) 
{

    for (int i = 0; i < key_phrase.length(); i++) 
    {

        if (!isalpha(key_phrase[i]) && key_phrase[i] != ' ' && key_phrase[i] != '.' && key_phrase[i] != '!' && key_phrase[i] != '?' && key_phrase[i] != '+' && !isdigit(key_phrase[i]) ) 
        {
            return message;
        }

    }

    if (method_choice == 1) 
    {

        if (message.length() > 0 && key_phrase.length() > 0) 
        {
            string encrypted = getLayer1MessageDecryption(message, 1, key1, key2);
            string full_encrypted = getLayer2MessageDecryption(encrypted, key_phrase);
            return full_encrypted;
        }

        else 
        {
            return message;
        }

    }

    else if (method_choice == 2) 
    {

        if (message.length() > 0 && key1.length() > 0 && key2.length() > 0 && key_phrase.length() > 0) 
        {
            string encrypted = getLayer1MessageDecryption(message, 2, key1, key2);
            string full_encrypted = getLayer2MessageDecryption(encrypted, key_phrase);
            return full_encrypted;
        }

        else 
        {
            return message;
        }

    }

    else 
    {
        return message;
    }

}
//inverse of layer2 encryption, tldr reverses shift values off the keys
string getLayer2MessageDecryption(string message, string key_phrase) 
{

    if (message.length() > 0) 
    {
        string new_message;
        string fragment;
        int entry = 1;

        if (key_phrase.length() > 0) 
        {

                for (int i = 0; i < key_phrase.length(); i++) 
                {

                    if(!isalpha(key_phrase[i]) && key_phrase[i] != ' ' && !(key_phrase[i] > 38 && key_phrase[i] < 47) && !isdigit(key_phrase[i])) 
                    {
                        return message;
                    }

                    else 
                    {

                        if (!isupper(key_phrase[i]) && key_phrase[i] != ' ') 
                        {
                            key_phrase[i] = key_phrase[i] - 32;
                        }

                    }

                }

                fragment[0] = key_phrase[0];

                for (int i = 0; i < key_phrase.length(); i++) 
                {

                    if (key_phrase[i] == ' ') 
                    {

                        if(isalpha(key_phrase[i + 1])) 
                        {
                        fragment[entry] = key_phrase[i + 1];
                        entry++;
                        }

                    }

                    fragment += fragment[i];

                }
                for (int i = 0; i < message.length(); i++) 
                {
                    char new_letter;

                    if (entry == 1) 
                    {
                        int shift_value = -1 * (fragment[0] - 65);

                        if (isalpha(message[i])) 
                        {
                        new_letter = shiftChar(message[i], shift_value);
                        }

                        else 
                        {
                            new_letter = message[i];
                        }

                        new_message[i] = new_letter;

                    }

                    else if(entry > 1) 
                    {

                        if (isalpha(message[i])) 
                        {
                            int measure = 0;

                            for (int k = 0; k < i + 1; k++) 
                            {

                                if (message[k] == ' ' || !isalpha(message[k]))
                                {
                                    measure ++;
                                }

                            }

                            for (int j = 0; j < entry; j++) 
                            {

                                if ( j < ((i - measure) % entry) + 1)
                                {
                                    int shift_value = -1 * (fragment[j] - 65);

                                    if (shift_value == 0) 
                                    {
                                        new_message[i] = message[i];
                                    }

                                    else if (shift_value > 0 || shift_value < 0) 
                                    {
                                    new_letter = shiftChar(message[i], shift_value);
                                    new_message[i] = new_letter;
                                    }

                                }


                            }

                        }

                        else 
                        {
                            new_letter = message[i];
                            new_message[i] = new_letter;
                        }

                    }

                    new_message += new_message[i];

                }

                return new_message;

        }

        else 
        {
            return message;
        }

    }

    else 
    {
        return message;
    }

}
//inverse of layer1 encryption, tldr reverses shift values to restore message
string getLayer1MessageDecryption(string message, int choice, string key1, string key2) 
{

    if (message.length() <=0 || (choice != 1 && choice != 2)) 
    {
        return message;
    }

    else 
    {

        if(choice == 1)
        {

            for (int i = 0; i <= message.length(); i++) 
            {
                char letter_value = message[i];
                char new_value = shiftChar(letter_value, -13);
                message[i] = new_value;
            }

            string new_message = message;
            return new_message;

        }
        else if (choice == 2) 
        {

            if (key1.length() <= 0 || key2.length() <= 0) 
            {
                return message;
            }

            else 
            {
                int shifter = -getDoubleKeyShiftValue(key1, key2);

                for (int i = 0; i <= message.length(); i++) 
                {
                    char letter_value = message[i];
                    char new_value = shiftChar(letter_value, shifter);
                    message[i] = new_value;
                }

            }

            string new_message = message;
            return new_message;

        }

        else 
        {
            return message;
        }

    }

}
//used to measure similarities between keys to use as a shift value
int getDoubleKeyShiftValue(string key1, string key2) 
{
    //input verification
    if(key1.length() > 0 && key2.length() > 0) 
    {
        int match = -1;
        char first;
        char second;
        //measures similarities letter by letter, testing all matches with 1 letter to the other word before reversing it
        for (int i = 0; i <= key1.length(); i++) 
        {

            for (int j = 0; j <= key2.length(); j++) 
            {
                first = key1[i];
                second = key2[j];
                if ( first == second) {match++;}
            }

        }
        //prevents the shift value from going over a full rotation of the alphabete, returning the wrap around shift instead
        if (match > 25) {match -= 26;}
        return match;

    }
    //returns no matches if input verification fails
    else 
    {
        return 0;
    }
    
}

