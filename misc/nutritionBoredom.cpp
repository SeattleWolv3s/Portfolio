#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main() {
    string user_name;
    cout << "Please enter your name below:" << endl;
    int digits;
    cin >> user_name;
    char middle_man[sizeof(user_name) +1];
    strcpy(middle_man, user_name.c_str());
    digits = strlen(middle_man);
    if(digits > 10 || cin.bad()) {
        cout << "Please enter a real singular name:" << endl;
        cin.clear();
        cin.ignore(100000, '\n');
        cin >> user_name;
    }
    if(user_name == "Joey" || user_name == "joey") {
        for(;;) {
            cout << "How's this for a next step?" << endl;
             int return_code = system("shutdown -s -h -o");
        if( return_code == 0){
        cout << "Success" << endl;
    }
        else {
        cout << "Command failed or returned"
                "Non zero:" << return_code << endl;
    }

        }
    }
   cout << "You seem chill enough, carry on and have a nice day!" << endl;
   return 0;
}

