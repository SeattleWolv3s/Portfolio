#include <iostream>
#include <vector>
using namespace std;

vector <int> vectorManipulation(vector <int> vector1, int eigenvalue);

int main ()
{
    vector <int> gru;
    int input = 0;
    cout << "Enter positive integers (Enter -1 to stop):" << endl;
    while (input != -1)
    {
        cin >> input;
        if (input > 0)
        {
            gru = vectorManipulation(gru, input);
        }
        else if (input == -1)
        {
            break;
        }
        else
        {
            input = 0;
            while (input <= 0 && input != -1)
            {
                cout << "Enter positive integers (Enter -1 to stop):" << endl;
                cin >> input;
            }
            if (input == -1)
            {
                gru = vectorManipulation(gru, input);
            }
            else 
            {
                break;
            }
        }
    };
    int minion = gru.size();
    if (minion > 0)
    {
        cout << "The elements in the vector are: ";
        for (int i = 0; i < minion; i++)
        {
            cout << gru.at(i) << " ";
        }
        cout << endl;
    }
    else 
    {
        cout << "The vector is empty." << endl;
    }
    return 0;
}

vector <int> vectorManipulation(vector <int> vector1, int eigenvalue)
{
    if (eigenvalue != -1)
    {
        if (eigenvalue > 0)
        {
            int size = vector1.size();
            if (size > 0)
            {
                if (eigenvalue % 10 == 0)
                {
                    int first = vector1.at(0);
                    for (int i = 0; i < size - 1; i++)
                    {
                        vector1.at(i) = vector1.at(i + 1);
                    }
                    vector1.at(size - 1) = first;
                    vector1.pop_back();
                    size = vector1.size();
                    if (eigenvalue % 5 == 0 && size > 0)
                    {
                        vector1.pop_back();
                        return vector1;
                    }
                    else 
                    {
                        return vector1;
                    }
                }
                else if (eigenvalue % 5 == 0)
                {
                    vector1.pop_back();
                    return vector1;
                }
                else 
                {
                    vector1.push_back(eigenvalue);
                    return vector1;
                }
            }
            else 
            {
                vector1.push_back(eigenvalue);
                return vector1;
            }
        }
        else 
        {
            return vector1;
        }
    }
    else 
    {
        return vector1;
    }
}