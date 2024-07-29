#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool validateDouble(string input);

int split(string input_string, char separator, string arr[], const int ARR_SIZE);

double centerOfMass(string fulltext, double center[], const int length);

int main()
{
    const int length = 3;
    double center[length];
    int counter = 0; 
    ifstream my_file("coordinates1.txt");
    string fulltext;
    while (getline(my_file, fulltext))
    {
        centerOfMass(fulltext, center[], length);
        counter = counter + 1;
    }

    return 0;
}

double centerOfMass(string fulltext, double center[], const int length)
{
    
}









int split(string input_string, char separator, string arr[], const int ARR_SIZE)
{
    int splits = 1;
    int entry = 0;
    int input_length = input_string.length();

    if (input_length < 2)
    {
        return 0;
    }

    for (int i = 0; i < input_length; i++)
    {

        if (input_string[i] == separator)
        {
            entry++;
        }

        else 
        {
        arr[entry] += input_string[i];
        }

        if (entry == ARR_SIZE)
        {
            break;
        }
    }

    splits = entry + 1;

    if (entry == ARR_SIZE) 
    {
        return -1;
    }

    else 
    {
        return splits;
    }
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