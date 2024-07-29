#include <iostream>
#include <string>
using namespace std;

bool validateDouble(string input);

int main()
{
    cout << "Enter your decimal:" << endl;
    string input;
    cin >> input;
    bool test = validateDouble(input);

    if(test == true)
    {
        cout << "Input is a valid double." << endl;
    }

    else
    {
        cout << "Input is not a valid double" << endl;
    }

    return 0;
}

bool validateDouble(string input)
{
    bool holder;

    for (int i = 0; i < input.length(); i++)
    {
        if (i == 0)
        {
        if (input[0] != '-' && !(isnumber(input[0]))) 
        {
            holder = false;
        }
        }

        else 
        {
            if (!(isnumber(input[i])) && input[i] != '.' )
            {
                holder = false;
            }

            else 
            {
                holder = true;
            }
    }
    }
    return holder;
}