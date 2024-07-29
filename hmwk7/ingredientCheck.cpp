#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int readIngredients(string filename, string ingredients[], const int max_ingredients);
int compareIngredients(string original_ingredients[], string friend_ingredients[], int original_ingredients_size, int friend_ingredients_size, string missing_ingredients[]);
int split(string input_string, char separator, string arr[], const int ARR_SIZE);

int main()
{
    string list = "ingredients.txt";
    string friend1_list = "friend1ingredients.txt";
    string friend2_list = "friend2ingredients.txt";
    const int max_ingredients = 30; 
    string ingredients[max_ingredients];
    string friend1_ingredients[max_ingredients];
    string friend2_ingredients[max_ingredients];
    string friend1_missing[max_ingredients];
    string friend2_missing[max_ingredients];
    int original_list = readIngredients(list, ingredients, max_ingredients);
    cout << "The ingredients needed are:" << endl;
    for (int i = 0; i < original_list; i++)
    {
        cout << ingredients[i] << endl;
    }
    int friend_1list = readIngredients(friend1_list, friend1_ingredients, max_ingredients);
    cout << "Friend 1 has the following ingredients:" << endl;
    for (int i = 0; i < friend_1list; i++)
    {
        cout << friend1_ingredients[i] << endl;
    }
    int friend_2list = readIngredients(friend2_list, friend2_ingredients, max_ingredients);
    cout << "Friend 2 has the following ingredients:" << endl;
    for (int i = 0; i < friend_2list; i++)
    {   
        cout << friend2_ingredients[i] << endl;
    }
    int friend_1missing = compareIngredients(ingredients, friend1_ingredients, max_ingredients, max_ingredients, friend1_missing);
    cout << "Friend 1 is missing the following ingredients:" << endl;
    for (int i = 0; i < friend_1missing; i++)
    {
        cout << friend1_missing[i] << endl;
    }
    int friend_2missing = compareIngredients(ingredients, friend2_ingredients, max_ingredients, max_ingredients, friend2_missing);
    cout << "Friend 2 is missing the following ingredients:" << endl;
    for (int i = 0; i < friend_2missing; i++)
    {
        cout << friend2_missing[i] << endl;
    }
    return 0;
}

int readIngredients(string filename, string ingredients[], const int max_ingredients)
{
    ifstream list_reader(filename);
    if (list_reader.fail())
    {
        return -1;
    }
    int tracker = 0;
    while(!list_reader.eof())
    {
        string ingredient;
        getline(list_reader, ingredient);
        ingredients[tracker] = ingredient;
        tracker = tracker + 1;
        if (tracker > max_ingredients)
        {
            break;
        }
    }
    return tracker;
}

int compareIngredients(string original_ingredients[], string friend_ingredients[], int original_ingredients_size, int friend_ingredients_size, string mising_ingredients[])
{
    if (original_ingredients_size == 0)
    {
        return 0;
    }
    int tracker = 0;
    bool present;
    for (int i = 0; i < original_ingredients_size; i++)
    {
        string words[30];
        int splitter = split(original_ingredients[i], ' ', words, 30);
        for (int j = 0; j <= splitter; j++)
        {
            for (int k = 0; k < friend_ingredients_size; k++)
            {
                if (words[j] == friend_ingredients[k])
                {
                    present = true;
                    break;
                }
            }
        }
        if (present == false)
        {
            mising_ingredients[tracker] = original_ingredients[i];
            tracker = tracker + 1;
        }
    }
    return tracker;
}

int split(string input_string, char separator, string arr[], const int ARR_SIZE)
{
    int entry = 0;
    int input_length = input_string.length();

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
    return entry;
}