#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countIfConditions(string line);
int countLoopConditions(string line);


int main()
{
    ifstream code_runner("func1_cpp.txt");
    int if_repeats = 0;
    int loop_repeats = 0;
    while (!code_runner.eof())
    {
        string test;
        getline(code_runner, test);
        if_repeats = if_repeats + countIfConditions(test);
        loop_repeats = loop_repeats + countLoopConditions(test);
    }
    int complexity = if_repeats + loop_repeats;
    cout << "Condition in ifs: " << if_repeats << endl << "Condition in loops: " << loop_repeats << endl << "Cyclomatic complexity: " << complexity << endl;
    if (complexity <= 10)
    {
        cout << "It is a good function!" << endl;
    }
    else 
    {
        cout << "It is not a good function!" << endl;
    }
}

int countIfConditions(string line)
{
    int boundary = 0;
    if (line.length() == 0 || line.length() >= 40)
    {
        return 0;
    }
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ' ')
        {
            boundary = boundary + 1;
        }
    }
    if (boundary + 1 > 40)
    {
        return 0;
    }
    int occurences = 0;
    string measure = "if";
    string measure1 = "else";
    int measuring_length = measure.length();
    int measuring_length1 = measure1.length();
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == '/' && line[i + 1] == '/')
        {
            break;
        }
        if (measure1 == line.substr(i, measuring_length1))
        {
            occurences = occurences + 1;
        }
        else if (measure == line.substr(i, measuring_length))
        {
            occurences = occurences + 1;
        }
        occurences = occurences + countLoopConditions(line);
    }
    return occurences;
}

int countLoopConditions(string line)
{
    int boundary = 0;
    if (line.length() == 0)
    {
        return 0;
    }
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ' ')
        {
            boundary = boundary + 1;
        }
    }
    if (boundary + 1 > 40)
    {
        return 0;
    }
    int loop_occurences = 0;
    string measure1 = "for";
    string measure2 = "while";
    int measure1_length = measure1.length();
    int measure2_length = measure2.length();
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == '/' && line[i + 1] == '/')
        {
            break;
        }
        if (measure1 == line.substr(i, measure1_length))
        {
            loop_occurences = loop_occurences + 1;
        }
        else if (measure2 == line.substr(i, measure2_length))
        {
            loop_occurences = loop_occurences + 1;
        }
        loop_occurences = loop_occurences + countIfConditions(line);
    }
    return loop_occurences;
}