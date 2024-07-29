#include "Game.cpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool loadCharacters(string filename, Entity characters[], const int CHARACTERS_SIZE, bool is_enemy);

int main()
{
    Game new_game;
    const int player_size = 5;
    const int enemy_size = 5;
    Entity players[5];
    Entity enemies[5];
    string playerfile = "players_full.txt";
    string enemyfile = "enemies_full.txt";
    
    int choice = 1;
    string menu_choice;

    string menu0 = "Select from the following options:"; 
    string menu1 = "1. Select Players and Enemies";
    string menu2 = "2. Display Players' stats";
    string menu3 = "3. Display Enemies' stats";
    string menu4 = "4. Edit a Player's Stats";
    string menu5 = "5. Edit an Enemy's Stats";
    string menu6 = "6. Exit";

    string player1;
    string player2;
    string enemy1;
    string enemy2;

    do 
    {

            int menu = 0;
            int test = 0;

        do 
        {

            cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl;
            cin >> menu_choice;

            while (menu_choice.length() == 0 || menu_choice.length() > 1) 
            {
                cout << "Invalid input. Please enter a valid choice (1-6)" << endl;
                cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl;
                cin >> menu_choice;
            }

            while (!isdigit(menu_choice[0])) 
            {
                cout << "Invalid input. Please enter a valid choice (1-6)" << endl;
                cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl;
                menu_choice = "";
                cin >> menu_choice;
            }

            test = stoi(menu_choice);
            
            if (!(test < 7 && test > 0)) 
            {
            cout << "Invalid input. Please enter a valid choice (1-6)" << endl;
            }

        } while (!(test < 7 && test > 0));

        menu = stoi(menu_choice);
        choice = menu;

            if (menu == 1) 
            {
                player1 = "";
                player2 = "";
                enemy1 = "";
                enemy2 = "";
                int players_selected = 0;
                int enemies_selected = 0;
                string player_choice;
                string enemy_choice;
                string players_name[5];
                string enemies_name[5];
                while (players_selected < 2)
                {
                    loadCharacters(playerfile, players, player_size, false);
                    if (players_selected == 0)
                    {
                        cout << "Player 1" << endl;
                    }
                    if (players_selected == 1)
                    {
                        cout << "Player 2" << endl;
                    }
                    cout << "Here is a list of players you can select from: " << endl;
                    for (int i = 0; i < player_size; i++)
                    {
                        if (players[i].getName() != player1 && players[i].getName() != player2)
                        {
                        players[i].printStats();
                        cout << "----------------------------------------------" << endl;
                        players_name[i] = players[i].getName();
                        }
                    }
                    cout << "The selected character is: " << endl;
                    cin >> player_choice;
                    int location = 0;
                    bool valid = false;
                    while (valid == false)
                    {
                    for (int i = 0; i < player_size; i++)
                    {
                        if (player_choice == players_name[i])
                        {
                            location = i;
                            valid = true;
                            break;
                        }
                        else 
                        {
                            if (i == player_size - 1 || player_choice.length() < 3)
                            {
                                player_choice = "";
                                cout << "Invalid selection. Select from the list!" << endl;
                                cout << "The selected character is: " << endl;
                                cin >> player_choice;
                            }
                        }
                    }
                    }
                    new_game.setPlayer(players_selected, players[location]);
                    if (players_selected == 0)
                    {
                        player1 = player_choice;
                    }
                    else if (players_selected == 1)
                    {
                        player2 = player_choice;
                    }
                    players_selected = players_selected + 1;
                }

                while (enemies_selected < 2)
                {
                    loadCharacters(enemyfile, enemies, enemy_size, true);
                    if (enemies_selected == 0)
                    {
                        cout << "Enemy 1" << endl;
                    }
                    if (enemies_selected == 1)
                    {
                        cout << "Enemy 2" << endl;
                    }
                    cout << "Here is a list of enemies you can select from: " << endl;
                    for (int i = 0; i < enemy_size; i++)
                    {
                        if (enemies[i].getName() != enemy1 && enemies[i].getName() != enemy2)
                        {
                        enemies[i].printStats();
                        cout << "----------------------------------------------" << endl;
                        enemies_name[i] = enemies[i].getName();
                        }
                    }
                    cout << "The selected character is: " << endl;
                    cin >> enemy_choice;
                    int location = 0;
                    bool valid = false;
                    while (valid == false)
                    {
                    for (int i = 0; i < enemy_size; i++)
                    {
                        if (enemy_choice == enemies_name[i])
                        {
                            location = i;
                            valid = true;
                            break;
                        }
                        else 
                        {
                            if (i == enemy_size - 1 || enemy_choice.length() < 3)
                            {
                                enemy_choice = "";
                                cout << "Invalid selection. Select from the list!" << endl;
                                cout << "The selected character is: " << endl;
                                cin >> enemy_choice;
                            }
                        }
                    }
                    }
                    new_game.setEnemy(enemies_selected, enemies[location]);
                    if (enemies_selected == 0)
                    {
                        enemy1 = enemy_choice;
                    }
                    else if (enemies_selected == 1)
                    {
                        enemy2 = enemy_choice;
                    }
                    enemies_selected = enemies_selected + 1;
                } 
            }

            else if (menu == 2) 
            {
                int printed = 0;
                while (printed < 2)
                {
                    if (printed == 0)
                    {
                        (new_game.getPlayer(player1)).printStats();
                        cout << "----------------------------------------------" << endl;
                    }
                    else if (printed == 1)
                    {
                        (new_game.getPlayer(player2)).printStats();
                        cout << "----------------------------------------------" << endl;
                    }
                    printed = printed + 1;
                }
            }

            else if (menu == 3) 
            {
                int printed = 0;
                while (printed < 2)
                {
                    if (printed == 0)
                    {
                        (new_game.getEnemy(enemy1)).printStats();
                        cout << "----------------------------------------------" << endl;
                    }
                    else if (printed == 1)
                    {
                        (new_game.getEnemy(enemy2)).printStats();
                        cout << "----------------------------------------------" << endl;
                    }
                    printed = printed + 1;
                }
            }

            else if (menu == 4) 
            {
                int spotsaver = -1;
                cout << "Which player's stats do you want to edit?" << endl;
                int printed = 0;
                while (printed < 2)
                {
                    if (printed == 0)
                    {
                        (new_game.getPlayer(player1)).printStats();
                        cout << "----------------------------------------------" << endl;
                    }
                    else if (printed == 1)
                    {
                        (new_game.getPlayer(player2)).printStats();
                        cout << "----------------------------------------------" << endl;
                    }
                    printed = printed + 1;
                }
                string choice;
                cin >> choice;
                while (choice.length() < 3 || (choice != new_game.getPlayer(player1).getName() && choice != new_game.getPlayer(player2).getName()))
                {
                    choice = "";
                    cout << "Invalid selection. Select from the list!" << endl;
                    cin >> choice;
                }
                if (choice == new_game.getPlayer(player1).getName())
                {
                    spotsaver = 0;
                }
                if (choice == new_game.getPlayer(player2).getName())
                {
                    spotsaver = 1;
                }
                cout << "The selected character is: " << endl << "Editing player " << choice << "'s stats:" << endl;
                cout << "1. Edit hp" << endl << "2. Edit condition" << endl << "3. Edit gold" << endl;
                string int_choice;
                cin >> int_choice;
                while (int_choice.length() > 1 || (stoi(int_choice, 0) != 1 && stoi(int_choice, 0) != 2 && stoi(int_choice, 0) != 3))
                {
                    int_choice = "";
                    cout << "Invalid selection. Select from the list!" << endl;
                    cin >> int_choice;
                }
                int editor = stoi(int_choice, 0);
                if (editor == 1)
                {
                    cout << "Enter the new value: " << endl;
                    string new_value;
                    cin >> new_value;
                    bool valid = false;
                    while (valid == false)
                    {
                        if (!isdigit(new_value[0]))
                        {
                        cout << "Enter a non-negative value!" << endl;
                        new_value = "";
                        cout << "Enter the new value: " << endl;
                        cin >> new_value;
                        }
                        else 
                        {
                            valid = true;
                        }
                    }
                    double update = stod(new_value, 0);
                    Entity median = new_game.getPlayer(choice);
                    median.setHP(update);
                    new_game.setPlayer(spotsaver, median);
                }
                else if (editor == 2)
                {
                    cout << "Enter the new value: " << endl;
                    string new_value;
                    cin >> new_value;
                    bool valid = false;
                    while (valid == false)
                    {
                        if (new_value.length() > 1 || (new_value[0] != 'H' && new_value[0] != 'P' && new_value[0] != 'D'))
                        {
                        cout << "Enter a value among 'H', 'D' or 'P'!" << endl;
                        new_value = "";
                        cout << "Enter the new value: " << endl;
                        cin >> new_value;
                        }
                        else 
                        {
                            valid = true;
                        }
                    }
                    char update = new_value[0];
                    Entity median = new_game.getPlayer(choice);
                    median.setCondition(update);
                    new_game.setPlayer(spotsaver, median);
                }
                else if (editor == 3)
                {
                    cout << "Enter the new value: " << endl;
                    string new_value;
                    cin >> new_value;
                    bool valid = false;
                    while (valid == false)
                    {
                        if (!isdigit(new_value[0]))
                        {
                        cout << "Enter a non-negative value!" << endl;
                        new_value = "";
                        cout << "Enter the new value: " << endl;
                        cin >> new_value;
                        }
                        else
                        {
                            valid = true;
                        }
                    }
                    int update = stoi(new_value, 0);
                    Entity median = new_game.getPlayer(choice);
                    median.setGold(update);
                    new_game.setPlayer(spotsaver, median);
                }
                else 
                {
                    while (int_choice.length() > 1 || (stoi(int_choice, 0) != 1 && stoi(int_choice, 0) != 2 && stoi(int_choice, 0) != 3))
                    {
                        int_choice = "";
                        cout << "Invalid selection. Select from the list!" << endl;
                        cin >> int_choice;
                    }
                }
            }

            else if (menu == 5) 
            {
                int spotsaver = -1;
                cout << "Which enemy's stats do you want to edit?" << endl;
                int printed = 0;
                while (printed < 2)
                {
                    if (printed == 0)
                    {
                        (new_game.getEnemy(enemy1)).printStats();
                        cout << "----------------------------------------------" << endl;
                    }
                    else if (printed == 1)
                    {
                        (new_game.getEnemy(enemy2)).printStats();
                        cout << "----------------------------------------------" << endl;
                    }
                    printed = printed + 1;
                }
                string choice;
                cin >> choice;
                while (choice.length() < 3 || (choice != new_game.getEnemy(enemy1).getName() && choice != new_game.getEnemy(enemy2).getName()))
                {
                    choice = "";
                    cout << "Invalid selection. Select from the list!" << endl;
                    cin >> choice;
                }
                if (choice == new_game.getEnemy(enemy1).getName())
                {
                    spotsaver = 0;
                }
                if (choice == new_game.getEnemy(enemy2).getName())
                {
                    spotsaver = 1;
                }
                cout << "The selected character is: " << endl << "Editing enemy " << choice << "'s stats:" << endl;
                cout << "1. Edit hp" << endl << "2. Edit condition" << endl << "3. Edit gold" << endl;
                string int_choice;
                cin >> int_choice;
                while (int_choice.length() > 1 || (stoi(int_choice, 0) != 1 && stoi(int_choice, 0) != 2 && stoi(int_choice, 0) != 3))
                {
                    int_choice = "";
                    cout << "Invalid selection. Select from the list!" << endl;
                    cin >> int_choice;
                }
                int editor = stoi(int_choice, 0);
                if (editor == 1)
                {
                    cout << "Enter the new value: " << endl;
                    string new_value;
                    cin >> new_value;
                    bool valid = false;
                    while (valid == false)
                    {
                        if (!isdigit(new_value[0]))
                        {
                        cout << "Enter a non-negative value!" << endl;
                        new_value = "";
                        cout << "Enter the new value: " << endl;
                        cin >> new_value;
                        }
                        else 
                        {
                            valid = true;
                        }
                    }
                    double update = stod(new_value, 0);
                    Entity median = new_game.getEnemy(choice);
                    median.setHP(update);
                    new_game.setEnemy(spotsaver, median);
                }
                else if (editor == 2)
                {
                    cout << "Enter the new value: " << endl;
                    string new_value;
                    cin >> new_value;
                    bool valid = false;
                    while (valid == false)
                    {
                        if (new_value.length() > 1 || (new_value[0] != 'H' && new_value[0] != 'P' && new_value[0] != 'D'))
                        {
                        cout << "Enter a value among 'H', 'D' or 'P'!" << endl;
                        new_value = "";
                        cout << "Enter the new value: " << endl;
                        cin >> new_value;
                        }
                        else
                        {
                            valid = true;
                        }
                    }
                    char update = new_value[0];
                    Entity median = new_game.getEnemy(choice);
                    median.setCondition(update);
                    new_game.setEnemy(spotsaver, median);
                }
                else if (editor == 3)
                {
                    cout << "Enter the new value: " << endl;
                    string new_value;
                    cin >> new_value;
                    bool valid = false;
                    while (valid == false)
                    {
                        if (!isdigit(new_value[0]))
                        {
                        cout << "Enter a non-negative value!" << endl;
                        new_value = "";
                        cout << "Enter the new value: " << endl;
                        cin >> new_value;
                        }
                        else 
                        {
                            valid = true;
                        }
                    }
                    int update = stoi(new_value, 0);
                    Entity median = new_game.getEnemy(choice);
                    median.setGold(update);
                    new_game.setEnemy(spotsaver, median);
                }
                else 
                {
                    while (int_choice.length() > 1 || (stoi(int_choice, 0) != 1 && stoi(int_choice, 0) != 2 && stoi(int_choice, 0) != 3))
                    {
                        int_choice = "";
                        cout << "Invalid selection. Select from the list!" << endl;
                        cin >> int_choice;
                    }
                }
            }

            else if (menu == 6) 
            {
                cout << "Bye!!" << endl;
                return 0;
            }

    } while (choice < 7 && choice > 0);
}

bool loadCharacters(string filename, Entity characters[], const int CHARACTERS_SIZE, bool is_enemy)
{
    ifstream npc;
    npc.open(filename);
    if (npc.fail())
    {
        return false;
    }
    else 
    {
        int locate = 0;
        int place = 0;

            while (!npc.eof())
            {
            string line;
            getline(npc, line);
            string holder[5];
            int entry = 0;
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == '|')
                {
                    entry = entry + 1;
                }
                else 
                {
                    holder[entry] = holder[entry] + line[i];
                }
            }
            if (holder[0] != "name")
            {
            string name = holder[0];
            double hp = stod(holder[1], 0);
            int gold = stoi(holder[2], 0);
            char condition = holder[3][0];
            characters[locate] = Entity(name, hp, gold, condition, is_enemy);
            locate = locate + 1;
            }
            place = place + 1;
            if (place > CHARACTERS_SIZE)
            {
                break;
            }
            }
        
        return true;
    }
}

