#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cassert>
using namespace std;

vector <string> subscribe(vector <string> subscriptions, string new_subscription);
vector <string> unsubscribe(vector <string> subscriptions, string removal);
void printSubscriptions(vector <string> subscriptions);
vector <string> newsletterMenu(vector <string> subscriptions);

int main()
{
    vector <string> subscriptions(1);
    subscriptions = newsletterMenu(subscriptions);
    cout << "Exit" << endl;
    return 0;
}

vector <string> subscribe(vector <string> subscriptions, string new_subscription)
{
    int size = subscriptions.size();
    for (int i = 0; i < size; i++)
    {
        if (new_subscription == subscriptions.at(i))
        {
            return subscriptions;
        }
    }
    subscriptions.push_back(new_subscription);
    return subscriptions;
}

vector <string> unsubscribe(vector <string> subscriptions, string removal)
{
    int size = subscriptions.size();
    int location = -1;
    for (int i = 0; i < size; i++)
    {
        if (subscriptions.at(i) == removal)
        {
            location = i;
        }
    }
    if (location != -1)
    {
        for (int i = location; i < size - 1; i++)
        {
            subscriptions.at(i) = subscriptions.at(i + 1);
        }
        subscriptions.at(size - 1) = subscriptions.at(location);
        subscriptions.pop_back();
        return subscriptions;
    }
    else 
    {
        return subscriptions;
    }
}

void printSubscriptions(vector <string> subscriptions)
{
    int size = subscriptions.size();
    if (subscriptions.size() > 1)
    {
        cout << "Current subscriptions: " << endl;
        for (int i = 1; i < size; i++)
        {
            cout << subscriptions.at(i) << endl;
        }
    }
    else 
    {
        cout << "You are not subscribed to any newsletters." << endl;
    }
    return;
}

vector <string> newsletterMenu(vector <string> subscriptions)
    {
      
        int choice = 1;
        string menu_choice;
  
        string menu0 = "1. Subscribe to a newsletter";
        string menu1 = "2. Unsubscribe from a newsletter";
        string menu2 = "3. Display current subscriptions";
        string menu3 = "4. Exit";
        string menu4 = "Enter your choice:";
        do 
        {

            int menu = 0;
            int test = 0;

            do 
            {
                cout << menu0<< endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl;
                getline(cin, menu_choice);

                while (menu_choice.length() == 0 || menu_choice.length() > 1) 
                {
                    cout << "Invalid choice! Enter a valid choice." << endl;
                    cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl;
                    getline(cin, menu_choice);
                }

                while (!isdigit(menu_choice[0])) 
                {
                    cout << "Invalid choice! Enter a valid choice." << endl;
                    cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl;
                    menu_choice = "";
                    getline(cin, menu_choice);
                }

                test = stoi(menu_choice);
                
                if (!(test < 5 && test > 0)) 
                {
                cout << "Invalid choice! Enter a valid choice." << endl;
                }

            } while (!(test < 5 && test > 0));

            menu = stoi(menu_choice);
            choice = menu;

            if (menu == 1) 
            {
                cout << "Enter the name of the newsletter to subscribe to:" << endl;
                string newsletter = "";
                getline(cin, newsletter);
                subscriptions = subscribe(subscriptions, newsletter);
            }

            else if (menu == 2) 
            {
                cout << "Enter the name of the newsletter to unsubscribe from:" << endl;
                string boredom = "";
                getline(cin, boredom);
                subscriptions = unsubscribe(subscriptions, boredom);
            }

            else if (menu == 3)
            {
                printSubscriptions(subscriptions);
            }
                
            else if (menu == 4)
            {
                break;
            }

        } while (choice < 5 && choice > 0);
    return subscriptions;
}