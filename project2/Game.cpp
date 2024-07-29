#include "Game.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctype.h>
using namespace std;

//all of my loading functions, not considered member functions, but called in member functions
void loadCharacters(string filename, Entity _load_to[], const int loading_size, bool is_enemy, equipment _All_Items[], potion _All_Potions[], const int item_size, const int potion_size);
void loadItems(string filename, equipment _load_to[], const int loading_size);
void loadPotions(string filename, potion _load_to[], const int loading_size);
void loadRiddles(string filename, riddle _load_to[], const int loading_size);
    //normal constructor and one that loads all items, players, enemies, and riddles using preset file names
    Game :: Game()
    {
        player1_turn = true;
        Game_Map = Board();
    }

    Game :: Game(string playerfile, string enemyfile, string bossfile, string itemfile, string potionfile, string riddlefile)
    {
        loadItems("a_items.txt", All_Items, 21);
        loadPotions("a_potions.txt", All_Potions, 9);
        loadCharacters("a_enemies.txt", All_Enemies, 7, true, All_Items, All_Potions, 21, 9);
        loadCharacters("a_epic_enemies.txt", All_Epic_Enemies, 3, true, All_Items, All_Potions, 21, 9);
        loadCharacters("a_players.txt", All_Players, 4, false, All_Items, All_Potions, 21, 9);
        loadRiddles("a_riddles.txt", riddles, 15);
        srand(time(NULL));
        int coin_flip = rand() % 2 + 1;
        if (coin_flip == 1)
        {
            player1_turn = true;
        }
        else 
        {
            player1_turn = false;
        }
    }
    //starting menu for the game, showing character selection, stats, and the first item shop
    void Game :: startMenu()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << endl;
        }
        cout << "Before beginning, please enter your names, player 1 first, and then player 2:" << endl;
        string player1_user;
        string player2_user;
        cin >> player1_user;
        cin >> player2_user;
        selected_players[0].setUser(player1_user);
        selected_players[1].setUser(player2_user);
        int choice = 1;
        string menu_choice;

        string menu0 = "Select from the following options:"; 
        string menu1 = "1. Select Players";
        string menu2 = "2. Display Players' stats";
        string menu3 = "3. Visit the Item Shop";
        string menu4 = "4. Depart!";

        string player1;
        string player2;

        do 
        {

                int menu = 0;
                int test = 0;

            do 
            {

                cout << endl << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl;
                cin >> menu_choice;

                while (menu_choice.length() == 0 || menu_choice.length() > 1) 
                {
                    cout << "Invalid input. Please enter a valid choice (1-4)" << endl;
                    cout << endl << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl;
                    cin >> menu_choice;
                }

                while (!isdigit(menu_choice[0])) 
                {
                    cout << "Invalid input. Please enter a valid choice (1-4)" << endl;
                    cout << endl << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl;
                    menu_choice = "";
                    cin >> menu_choice;
                }

                test = stoi(menu_choice);
                
                if (!(test < 5 && test > 0)) 
                {
                cout << "Invalid input. Please enter a valid choice (1-4)" << endl;
                }

            } while (!(test < 5 && test > 0));

            menu = stoi(menu_choice);
            choice = menu;

                if (menu == 1) 
                {
                    player1 = "";
                    player2 = "";

                    int players_selected = 0;

                    string player_choice;

                    string players_name[4];

                    while (players_selected < 2)
                    {
                        
                        if (players_selected == 0)
                        {
                            cout << endl << "Player 1" << endl;
                        }
                        if (players_selected == 1)
                        {
                            cout << endl << "Player 2" << endl;
                        }
                        cout << "Here is a list of players you can select from: " << endl;
                        for (int i = 0; i < 4; i++)
                        {
                            if (All_Players[i].getName() != player1 && All_Players[i].getName() != player2)
                            {
                                cout << endl;
                            All_Players[i].printBasicStats();
                            cout << endl << "----------------------------------------------" << endl; 
                            players_name[i] = All_Players[i].getName();
                            }
                        }
                        cout << "The selected character is: " << endl;
                        cin >> player_choice;
                        int location = 0;
                        bool valid = false;
                        while (valid == false)
                        {
                        for (int i = 0; i < 4; i++)
                        {
                            if (player_choice == players_name[i])
                            {
                                location = i;
                                valid = true;
                                break;
                            }
                            else 
                            {
                                if (i == 4 - 1 || player_choice.length() < 3)
                                {
                                    player_choice = "";
                                    cout << "Invalid selection. Select from the list!" << endl;
                                    cout << "The selected character is: " << endl;
                                    cin >> player_choice;
                                }
                            }
                        }
                        }
                        selected_players[players_selected] = All_Players[location];
                        if (players_selected == 0)
                        {
                            player1 = player_choice;
                            selected_players[0].setPlayerCount(1);
                        }
                        else if (players_selected == 1)
                        {
                            player2 = player_choice;
                            selected_players[1].setPlayerCount(2);
                        }
                        players_selected = players_selected + 1;
                    }
                }

                else if (menu == 2) 
                {
                    cout << "Which player's stats would you like to view (1 or 2)?" << endl;
                    int selected;
                    cin >> selected;
                    while (selected != 1 && selected != 2)
                    {
                        if (selected == 1 || selected == 2)
                        {
                            break;
                        }
                        else
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "Not an available option, please try again" << endl;
                            selected = 0;
                            cout << "Which player's stats would you like to view (1 or 2)?" << endl;
                            cin >> selected;
                        }
                    }
                    if (selected == 1)
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        selected_players[0].printStats();
                    }
                    else if (selected == 2)
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        selected_players[1].printStats();
                    }
                }

                else if (menu == 3) 
                {
                    shopCall();
                }

                else if (menu == 4) 
                {
                    break;
                }

        } while (choice < 5 && choice > 0);
        return;
    }
    //central function to the game, shows the menu to a player based on whose turn it is and contains all turn options (e.g. print map and use potion and movement)
    void Game :: gameMenu()
    {
        while (Victory() == false && selected_players[0].death() == false && selected_players[1].death() == false)
        {
            if (selected_players[0].death() == false && selected_players[1].death() == false)
            {
                    if (player1_turn == true)
                    {
                        for (int i = 0; i < 10; i++)
                        {
                            cout << endl;
                        }
                        int choice = 1;
                        string menu_choice;
            
                        string menu6 = "Player 1 ";
                        string menu0 = "select from the following options:"; 
                        string menu1 = "1. View stats";
                        string menu2 = "2. Change equipment";
                        string menu3 = "3. Use a potion";
                        string menu4 = "4. View Map";
                        string menu5 = "5. Press forward (This will end your turn)";

                        do 
                        {

                            int menu = 0;
                            int test = 0;

                            do 
                            {
                                cout << endl << "----------------------------------------------" << endl;
                                cout << endl;
                                cout << menu6 << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl;
                                cin >> menu_choice;

                                while (menu_choice.length() == 0 || menu_choice.length() > 1) 
                                {
                                    cout << endl << "----------------------------------------------" << endl;
                                    cout << endl;
                                    cout << "Invalid input. Please enter a valid choice (1-5)" << endl;
                                    cout << menu6 << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl;
                                    cin >> menu_choice;
                                }

                                while (!isdigit(menu_choice[0])) 
                                {
                                    cout << endl << "----------------------------------------------" << endl;
                                    cout << endl;
                                    cout << "Invalid input. Please enter a valid choice (1-5)" << endl;
                                    cout << menu6 << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl;
                                    menu_choice = "";
                                    cin >> menu_choice;
                                }

                                test = stoi(menu_choice);
                                
                                if (!(test < 6 && test > 0)) 
                                {
                                    cout << endl << "----------------------------------------------" << endl;
                                    cout << endl;
                                    cout << "Invalid input. Please enter a valid choice (1-4)" << endl;
                                }

                            } while (!(test < 6 && test > 0));

                            menu = stoi(menu_choice);
                            choice = menu;

                            if (menu == 1) 
                            {
                                cout << endl << "----------------------------------------------" << endl;
                                cout << endl;
                                selected_players[0].printStats();
                            }

                            else if (menu == 2) 
                            {
                                cout << endl << "----------------------------------------------" << endl;
                                cout << endl;
                                itemMenu();
                            }

                            else if (menu == 3) 
                            {
                                cout << endl;
                                selected_players[0].usePotion();
                            }

                            else if (menu == 4)
                            {
                                cout << endl << "----------------------------------------------" << endl;
                                cout << endl;
                                Game_Map.mapDisplay();
                            }

                            else if (menu == 5) 
                            {
                                cout << endl << "----------------------------------------------" << endl;
                                cout << endl;
                                srand(time(NULL));
                                int dice_roll = 1;
                                dice_roll = rand() % 6 + 1;
                                Movement(dice_roll);
                                cout << selected_players[0].getLocation() << endl;
                                eventGenerator();
                                selected_players[0].setTurnsTaken();
                                cout << endl << "----------------------------------------------" << endl;
                                setTurn();
                                break;
                            }

                        } while (choice < 6 && choice > 0);
                    }
                        
                if (player1_turn == false)
                {
                    for (int i = 0; i < 10; i++)
                    {
                        cout << endl;
                    }

                    int choice = 1;
                    string menu_choice;
                    string menu6 = "Player 2 ";
                    string menu0 = "select from the following options:"; 
                    string menu1 = "1. View stats";
                    string menu2 = "2. Change equipment";
                    string menu3 = "3. Use a potion";
                    string menu4 = "4. View Map";
                    string menu5 = "5. Press forward (This will end your turn)";

                    do 
                    {

                        int menu = 0;
                        int test = 0;

                        do 
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << menu6 << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl;
                            cin >> menu_choice;

                            while (menu_choice.length() == 0 || menu_choice.length() > 1) 
                            {
                                cout << endl << "----------------------------------------------" << endl;
                                cout << endl;
                                cout << "Invalid input. Please enter a valid choice (1-5)" << endl;
                                cout << menu6 << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl;
                                cin >> menu_choice;
                            }

                            while (!isdigit(menu_choice[0])) 
                            {
                                cout << endl << "----------------------------------------------" << endl;
                                cout << endl;
                                cout << "Invalid input. Please enter a valid choice (1-5)" << endl;
                                cout << menu6 << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl;
                                menu_choice = "";
                                cin >> menu_choice;
                            }

                            test = stoi(menu_choice);
                            
                            if (!(test < 6 && test > 0)) 
                            {
                                cout << endl << "----------------------------------------------" << endl;
                                cout << endl;
                                cout << "Invalid input. Please enter a valid choice (1-5)" << endl;
                            }

                        } while (!(test < 6 && test > 0));

                        menu = stoi(menu_choice);
                        choice = menu;

                        if (menu == 1) 
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            selected_players[1].printStats();
                        }

                        else if (menu == 2) 
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            itemMenu();
                        }

                        else if (menu == 3) 
                        {
                            cout << endl;
                            selected_players[1].usePotion();
                        }

                        else if (menu == 4)
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            Game_Map.mapDisplay();
                        }

                        else if (menu == 5) 
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            srand(time(NULL));
                            int dice_roll = 1;
                            dice_roll = rand() % 6 + 1;
                            Movement(dice_roll);
                            cout << selected_players[1].getLocation() << endl;
                            eventGenerator();
                            selected_players[1].setTurnsTaken();
                            cout << endl << "----------------------------------------------" << endl;
                            setTurn();
                            break;
                        }

                    } while (choice < 6 && choice > 0);
                }
            }
            else
            {
                break;
            }
        }
        return;
    }
    //standard bool flip
    void Game :: setTurn()
    {
        if (player1_turn == true)
        {
            player1_turn = false;
            victoryTracker();
            return;
        }

        else if (player1_turn == false)
        {
            player1_turn = true;
            victoryTracker();
            return;
        }
    }
    //menu for changing equipment with options to discard or swap items
    void Game :: itemMenu()
    {
        if (player1_turn == true)
        {
            cout << endl << "----------------------------------------------" << endl;
            cout << endl;
            cout << "You find a moment of respite on the choppy waters and have the opportunity to change your equipment, would you like to?" << endl << "1. Yes" << "2. No" << endl;
            int choice;
            cin >> choice;
            while (choice != 1 && choice != 2)
            {
                if (choice == 1 || choice == 2)
                {
                    break;
                }

                else
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Not an available option, please try again" << endl;
                    choice = 0;
                    cout << "You find a moment of respite on the choppy waters and have the opportunity to change your equipment, would you like to?" << endl << "1. Yes" << "2. No" << endl;
                    cin >> choice;
                }
            }
            if (choice == 1)
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                selected_players[0].displayEquipped();
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "Which item would you like to remove (1 or 2)?" << endl;
                int removal;
                cin >> removal;
                while (removal != 1 && removal != 2)
                {
                    if (removal == 1 || removal == 2)
                    {
                        break;
                    }
                    else 
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "Not an available option, please try again" << endl;
                        removal = 0;
                        cout << "Which item would you like to change (1 or 2)?" << endl;
                        cin >> removal;
                    }
                }
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                selected_players[0].unequip(selected_players[0].getActiveEquipment(removal - 1).name);
                selected_players[0].equipItem();
            }
        }

        if (player1_turn == false)
        {
            cout << endl << "----------------------------------------------" << endl;
            cout << endl;
            cout << "You find a moment of respite on the choppy waters and have the opportunity to change your equipment, would you like to?" << endl << "1. Yes" << "2. No" << endl;
            int choice;
            cin >> choice;
            while (choice != 1 && choice != 2)
            {
                if (choice == 1 || choice == 2)
                {
                    break;
                }

                else
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Not an available option, please try again" << endl;
                    choice = 0;
                    cout << "You find a moment of respite on the choppy waters and have the opportunity to change your equipment, would you like to?" << endl << "1. Yes" << "2. No" << endl;
                    cin >> choice;
                }
            }
            if (choice == 1)
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                selected_players[1].displayEquipped();
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "Which item would you like to remove (1 or 2)?" << endl;
                int removal;
                cin >> removal;
                while (removal != 1 && removal != 2)
                {
                    if (removal == 1 || removal == 2)
                    {
                        break;
                    }
                    else 
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "Not an available option, please try again" << endl;
                        removal = 0;
                        cout << "Which item would you like to change (1 or 2)?" << endl;
                        cin >> removal;
                    }
                }
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                selected_players[1].unequip(selected_players[1].getActiveEquipment(removal - 1).name);
                selected_players[1].equipItem();
            }
        }
        return;
    }
    //checks the tile location using board functions and generates a number corresponding to an event based on the tile description
    void Game :: eventGenerator()
    {
        if (selected_players[0].getLocation() == selected_players[1].getLocation())
        {
            startBossFight();
            return;
        }
        else
        {
            srand(time(NULL));
            if (player1_turn == true)
            {
                    if (Game_Map.player1TileInfo(selected_players[0].getLocation()).tile_type == "Water")
                    {
                        srand(time(NULL));
                        int calamity = rand() % 100 + 1;
                        if (selected_players[0].findBoon("Helios' Light") == true)
                        {
                            calamity = calamity + 5;
                        }
                        if (calamity <= 30)
                        {
                            srand(time(NULL));
                            int determinant = rand() % 100 + 1;
                            if (determinant >= 1 && determinant <= 44)
                            {
                                cout << endl << "----------------------------------------------" << endl;
                                cout << endl;   
                                cout << "With each passing moment, the storm grows fiercer, testing your courage and resolve as you struggle to keep your ship afloat amidst the wrath of Poseidon." << endl;
                                srand(time(NULL));
                                int movement = rand() % 3 + 1;
                                Movement(-1 * movement);
                                return;
                            }

                            else if (determinant > 45 && determinant <= 79)
                            {
                                cout << endl << "----------------------------------------------" << endl;
                                cout << endl;
                                cout << "The spread of the plague seems unstoppable, defying your best efforts to contain it and leaving you to confront the harsh reality of your own mortality." << endl;
                                selected_players[0].setCondition('D');
                                return;
                            }
                                
                            else if (determinant > 79 && determinant <= 100)
                            {
                                cout << endl << "----------------------------------------------" << endl;
                                cout << endl;
                                cout << "Much to your dismay, it seems you are not the only one on your ship." << endl;
                                selected_players[0].setCondition('P');
                                return;
                            }
                        }
                        else
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "The waves are calm and rock your ship from side to side as you peacefully carry on with your journey" << endl;
                            return;
                        }
                    }

                    else if (Game_Map.player1TileInfo(selected_players[0].getLocation()).tile_type == "Island")
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "You dock your boat on a small island and begin to explore, but it would seem the island is not deserted" << endl;
                        selected_players[0] = startCombat(selected_players[0]);
                        if (selected_players[0].findBoon("Coward") == true)
                        {
                            selected_players[0].removeBoon("Coward");
                            return;
                        }
                        else if (selected_players[0].getHP() > 0)
                        {
                            selected_players[0] = soloShopCall(selected_players[0]);
                            return;
                        }
                        else
                        {
                            victoryTracker();
                            return;
                        }
                    }

                    else if (Game_Map.player1TileInfo(selected_players[0].getLocation()).tile_type == "Special")
                    {
                        srand(time(NULL));
                        int special_type = rand() % 5;
                        if (special_type == 0)
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "Your spirits soar as you're propelled four tiles ahead. Ithaca isn't far." << endl;
                            Movement(4);
                            return;
                        }

                        else if (special_type == 1)
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout <<  "As the Siren's Song echoes through the air, you sense its magical pull, an otherworldly force that toys with the hearts of those who dare to listen. You stop in your tracks." << endl;
                            selected_players[0].setBoon("Siren's Song");
                            return;
                        }

                        else if (special_type == 2)
                        {
                            cout << "As you stand in the brilliance of Helios' Beacon, you feel the warmth of the sun god's favor shining upon you. You feel luckier." << endl;
                            selected_players[0].setBoon("Helios' Favor");
                            return;
                        }

                        else if (special_type == 3)
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "In the embrace of the Nymph's Spring, you feel the embrace of nature itself." << endl;
                            selected_players[0].setStamina(selected_players[0].getStamina() + 50);
                            return;
                        }

                        else if (special_type == 4 || special_type == 5)
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "You have come across a treasure chest drifing across the waves, the lock appears to be a string of characters with a riddle carves below." << endl;
                            srand(time(NULL));
                            int riddle = rand() % 15;
                            cout << riddles[riddle].riddle << endl;
                            string answer;
                            cin >> answer;
                            if (answer == riddles[riddle].answer)
                            {
                                srand(time(NULL));
                                int reward = rand() % 10 + 1;
                                if (reward >= 1 && reward <= 3)
                                {
                                    selected_players[0].setStamina(100);
                                }
                                else if (reward >= 4 && reward <= 6)
                                {
                                    srand(time(NULL));
                                    double gold_fall = rand() % 50 + 10;
                                    selected_players[0].setGold(selected_players[0].getGold() + gold_fall);
                                }
                            }
                        }
                    }
                }
            }

            if (player1_turn == false)
            {
                if (selected_players[0].getLocation() == selected_players[1].getLocation())
                {
                    startBossFight();
                }
                else 
                {
                    if (Game_Map.player2TileInfo(selected_players[1].getLocation()).tile_type == "Water")
                    {
                        srand(time(NULL));
                        int calamity = rand() % 100 + 1;
                        if (selected_players[1].findBoon("Helios' Light") == true)
                        {
                            calamity = calamity + 5;
                        }
                        if (calamity <= 30)
                        {
                            srand(time(NULL));
                            int determinant = rand() % 100 + 1;
                            if (determinant >= 1 && determinant <= 44)
                            {
                                cout << endl << "----------------------------------------------" << endl;
                                cout << endl;
                                cout << "With each passing moment, the storm grows fiercer, testing your courage and resolve as you struggle to keep your ship afloat amidst the wrath of Poseidon." << endl;
                                srand(time(NULL));
                                int movement = rand() % 3 + 1;
                                Movement(-1 * movement);
                                return;
                            }

                            else if (determinant > 45 && determinant <= 79)
                            {
                                cout << endl << "----------------------------------------------" << endl;
                                cout << endl;
                                cout << "The spread of the plague seems unstoppable, defying your best efforts to contain it and leaving you to confront the harsh reality of your own mortality." << endl;
                                selected_players[1].setCondition('D');
                                return;
                            }
                                
                            else if (determinant > 79 && determinant <= 100)
                            {
                                cout << endl << "----------------------------------------------" << endl;
                                cout << endl;
                                cout << "Much to your dismay, it seems you are not the only one on your ship." << endl;
                                selected_players[1].setCondition('P');
                                return;
                            }
                        }
                    }

                    else if (Game_Map.player2TileInfo(selected_players[1].getLocation()).tile_type == "Island")
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "You dock your boat on a small island and begin to explore, but it would seem the island is not deserted" << endl;
                        selected_players[1] = startCombat(selected_players[1]);
                        if (selected_players[1].findBoon("Coward") == true)
                        {
                            selected_players[1].removeBoon("Coward");
                            return;
                        }
                        else if (selected_players[1].getHP() > 0)
                        {
                            selected_players[1] = soloShopCall(selected_players[1]);
                            return;
                        }
                        else 
                        {
                            victoryTracker();
                            return;
                        }
                    }

                    else if (Game_Map.player2TileInfo(selected_players[1].getLocation()).tile_type == "Special")
                    {
                        srand(time(NULL));
                        int special_type = rand() % 3;
                        if (special_type == 0)
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "Your spirits soar as you're propelled four tiles ahead. Ithaca isn't far." << endl;
                            Movement(4);
                            return;
                        }

                        else if (special_type == 1)
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout <<  "As the Siren's Song echoes through the air, you sense its magical pull, an otherworldly force that toys with the hearts of those who dare to listen. You stop in your tracks." << endl;
                            selected_players[1].setBoon("Siren's Song");
                            return;
                        }

                        else if (special_type == 2)
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "As you stand in the brilliance of Helios' Beacon, you feel the warmth of the sun god's favor shining upon you. You feel luckier." << endl;
                            selected_players[1].setBoon("Helios' Favor");
                            return;
                        }

                        else if (special_type == 3)
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "In the embrace of the Nymph's Spring, you feel the embrace of nature itself." << endl;
                            selected_players[1].setStamina(selected_players[1].getStamina() + 50);
                            return;
                        }
                    }
                }
        }
    }
    //checks player turn to check for non-healthy statuses and apply appropriate debuffs 
    void Game :: statusCheck()
    {
        if (player1_turn == true)
        {
            if (selected_players[0].getCondition() == 'D')
            {
                selected_players[0].setStamina(selected_players[0].getStamina() - 5);
            }
            
            else if (selected_players[0].getCondition() == 'P')
            {
                selected_players[0].setHP(selected_players[0].getHP() - 5);
            }

            if (selected_players[0].getStamina() == 0)
            {
                setTurn();
                selected_players[0].setStamina(selected_players[0].getStamina() + 10);
            }
        }

        if (player1_turn == false)
        {
            if (selected_players[1].getCondition() == 'D')
            {
                selected_players[1].setStamina(selected_players[1].getStamina() - 5);
            }
            
            else if (selected_players[1].getCondition() == 'P')
            {
                selected_players[1].setHP(selected_players[0].getHP() - 5);
            }

            if (selected_players[1].getStamina() == 0)
            {
                setTurn();
                selected_players[1].setStamina(selected_players[1].getStamina() + 10);
            }
        }
        return;
    }
    //checks player conditions to determine if someone has won the game
    void Game :: victoryTracker()
    {
        if (selected_players[0].getLocation() >= 50)
        {
            player1_victory = true;
        }
        if (selected_players[0].getHP() <= 0)
        {
            player2_victory = true;
        }
        if (selected_players[1].getLocation() >= 50)
        {
            player2_victory = true;
        }
        if (selected_players[1].getHP() <= 0)
        {
            player1_victory = true;
        }
        return;
    }
    //different loaders were needed for every struct type as the process of offloading filtered llines into respective struct locations didn't correspond
    void loadCharacters(string filename, Entity _load_to[], const int loading_size, bool is_enemy, equipment _All_Items[], potion _All_Potions[], const int item_size, const int potion_size)
    {
        ifstream npc;
        npc.open(filename);
        int place = 0;

        while (!npc.eof())
        {
            string line;
            getline(npc, line);
            string holder[13];
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
            _load_to[place].setPotionCount();
            _load_to[place].setEquipmentCount();
            _load_to[place].setBackpackCount();
            _load_to[place].setName(holder[0]);
            _load_to[place].setHP(stod(holder[2], 0));
            _load_to[place].setStamina(stod(holder[3], 0));
            _load_to[place].setDefense(stod(holder[4], 0));
            _load_to[place].setCondition(holder[5][0]);
            if (holder[6] == "False")
            {
                _load_to[place].setAdvantage(false);
            }
            else if (holder[6] == "True")
            {
                _load_to[place].setAdvantage(true);
            }
            _load_to[place].setWeakness(holder[7][0]);
            _load_to[place].setGold(stod(holder[8], 0));
            _load_to[place].setAirDamage(0.25);
            _load_to[place].setFireDamage(0.25);
            _load_to[place].setWaterDamage(0.25);
            _load_to[place].setEarthDamage(0.25);
            for (int i = 0; i < 9; i++)
            {
                string potion_name = _All_Potions[i].name;
                if (holder[9] == potion_name)
                {
                    _load_to[place].setPotion(_All_Potions[i]);
                    break;
                }
            }

            for (int i = 0; i < 21; i++)
            {
                if (holder[10] == _All_Items[i].name)
                {
                    _load_to[place].setItem(_All_Items[i]);
                    break;
                }
            }
            _load_to[place].setEquipmentCount();
            _load_to[place].setNetDamage();
            _load_to[place].setPotionCount();
            _load_to[place].setLocation(0);
            _load_to[place].setIsEnemy(is_enemy);
            place = place + 1;
        }
        for (int i = 0; i < 80; i++)
        {
            cout << endl;
        }
        return;
    }

    void loadItems(string filename, equipment _load_to[], const int loading_size)
    {
        ifstream npc;
        npc.open(filename);
        int place = 0;

        while (!npc.eof())
        {
            string line;
            getline(npc, line);
            string holder[8];
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
            _load_to[place].name = holder[0];
            _load_to[place].description = holder[1];
            _load_to[place].type = holder[2][0];
            if (holder[2][0] != 'D' && holder[2][0] != 'S' && holder[2][0] != 'B' && holder[2][0] != 'U')
            {
            _load_to[place].value = stod(holder[3], 0) / 100;
            _load_to[place].alt_value = stod(holder[4], 0) / 100;
            }
            else 
            {
            _load_to[place].value = stod(holder[3], 0);
            _load_to[place].alt_value = stod(holder[4], 0);
            }
            _load_to[place].element = holder[5][0];
            _load_to[place].price = stod(holder[6], 0);
            _load_to[place].owner = holder[7];
            place = place + 1;
        }
        return;
    }

    void loadPotions(string filename, potion _load_to[], const int loading_size)
    {
        ifstream npc;
        npc.open(filename);
        int place = 0;

        while (!npc.eof())
        {
            string line;
            getline(npc, line);
            string holder[6];
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
            _load_to[place].name = holder[0];
            _load_to[place].description = holder[1];
            _load_to[place].type = holder[2][0];
            _load_to[place].value = stod(holder[3], 0);
            _load_to[place].price = stod(holder[5], 0);
            _load_to[place].held = 1;
            place = place + 1;
        }
        return;
    }
    //implemented to compress both victories into one bool that could be returned to the main function, acts like an OR gate
    const bool Game :: Victory()
    {
        if (player1_victory == true || player1_victory == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //movement function that takes a given number and uses it to move the player, allowing for backwards movement by calamity, also accounts for boon system and automatically ends if the sirens song boon is found
    void Game :: Movement(int movement)
    {
        if (selected_players[0].findBoon("Siren's Song") == true && player1_turn == true)
        {
            selected_players[0].setStamina(selected_players[0].getStamina() + 10);
            selected_players[0].removeBoon("Siren's Song");
            return;
        }

        else if (selected_players[1].findBoon("Siren's Song") == true && player1_turn == false)
        {
            selected_players[1].setStamina(selected_players[1].getStamina() + 10);
            selected_players[1].removeBoon("Siren's Song");
            return;
        }

        else 
        {
            if (player1_turn == true)
            {
                if (movement > 0)
                {
                    bool combat = false;
                    for (int i = 0; i < movement; i++)
                    {
                        if (Game_Map.player1TileInfo(selected_players[0].getLocation() + i).tile_type == "Island")
                        {
                            combat = true;
                            selected_players[0].setLocation(selected_players[0].getLocation() + i);
                            cout << "Player 1 moved " << i << " spaces!" << endl;
                            cout << "Player 1 is now at location " << selected_players[0].getLocation() << endl;
                            break;
                        }
                    }

                    if (combat == true)
                    {
                        return;
                    }
                    else
                    {
                        selected_players[0].setLocation(selected_players[0].getLocation() + movement);
                        cout << "Player 1 moved " << movement << " spaces!" << endl;
                        cout << "Player 1 is now at location " << selected_players[0].getLocation() << endl;
                        return;
                    }
                }

                else if (movement < 0)
                {
                    bool combat = false;
                    for (int i = 0; i > movement; i = i - 1)
                    {
                        if (Game_Map.player1TileInfo(selected_players[0].getLocation() + i).tile_type == "Island")
                        {
                            combat = true;
                            selected_players[0].setLocation(selected_players[0].getLocation() + i);
                            cout << "Player 1 moved backwards " << i << " spaces!" << endl;
                            cout << "Player 1 is now at location " << selected_players[0].getLocation() << endl;
                            break;
                        }
                    }

                    if (combat == true)
                    {
                        return;
                    }
                    else
                    {
                        selected_players[0].setLocation(selected_players[0].getLocation() + movement);
                        cout << "Player 1 moved backwards " << movement << " spaces!" << endl;
                        cout << "Player 1 is now at location " << selected_players[0].getLocation() << endl;
                        return;
                    }
                }
            }    
                    
            if (player1_turn == false)
            {
                if (movement > 0)
                {
                    bool combat = false;
                    for (int i = 0; i < movement; i++)
                    {
                        if (Game_Map.player2TileInfo(selected_players[1].getLocation() + i).tile_type == "Island")
                        {
                            combat = true;
                            selected_players[1].setLocation(selected_players[1].getLocation() + i);
                            cout << "Player 2 moved " << i << " spaces!" << endl;
                            cout << "Player 2 is now at location " << selected_players[1].getLocation() << endl;
                            break;
                        }
                    }

                    if (combat == true)
                    {
                        return;
                    }
                    else
                    {
                        selected_players[1].setLocation(selected_players[1].getLocation() + movement);
                        cout << "Player 2 moved " << movement << " spaces!" << endl;
                        cout << "Player 2 is now at location " << selected_players[1].getLocation() << endl;
                        return;
                    }
                }

                else if (movement < 0)
                {
                    bool combat = false;
                    for (int i = 0; i > movement; i = i - 1)
                    {
                        if (Game_Map.player2TileInfo(selected_players[1].getLocation() + i).tile_type == "Island")
                        {
                            combat = true;
                            selected_players[1].setLocation(selected_players[1].getLocation() + i);
                            cout << "Player 2 moved backwards " << i << " spaces!" << endl;
                            cout << "Player 2 is now at location " << selected_players[1].getLocation() << endl;
                            break;
                        }
                    }

                    if (combat == true)
                    {
                        return;
                    }
                    else
                    {
                        selected_players[1].setLocation(selected_players[1].getLocation() + movement);
                        cout << "Player 2 moved backwards " << movement << " spaces!" << endl;
                        cout << "Player 2 is now at location " << selected_players[1].getLocation() << endl;
                        return;
                    }
                }
            }
        }
    }
    //generates a combat object and passes the player to it, checking how they left afterwards to block showing a shop if they flee
    Entity Game :: startCombat(Entity player1)
    {
        Entity player = player1;
        Combat fight = Combat(All_Enemies, 7);
        fight.EnemySelector(All_Enemies, 7);
        player = fight.combatMenu(player);
        if (player.getHP() > 0 && player.findBoon("Coward") == false)
        {
            player = fight.victoryMenu(player);
            player = soloShopCall(player);
        }
        else
        {
            player.removeBoon("Coward");
            victoryTracker();
        }
        return player;
    }
    //generates an epic combat encounter and manages the turn rotation externally, verifying both players are alive and the enemy is alive each round
    void Game :: startBossFight()
    {
        Epic_Combat fight = Epic_Combat(selected_players, All_Epic_Enemies, 2, 3);
        while (fight.getBossHealth() > 0 && selected_players[0].getHP() > 0 && selected_players[1].getHP() > 0)
        {
            if (fight.getPlayerTurn() == true)
            {
                if (selected_players[0].getStamina() > 0)
                {
                    selected_players[0] = fight.player1CombatMenu(selected_players[0], selected_players[1]);
                }
                else 
                {
                    selected_players[0] = fight.player1StatusCheck(selected_players[0]);
                }
                if (selected_players[1].getStamina() > 0)
                {
                    selected_players[1] = fight.player2CombatMenu(selected_players[1], selected_players[0]);
                }
                else 
                {
                    selected_players[1] = fight.player2StatusCheck(selected_players[1]);
                }
                fight.setPlayerTurn();
            }
            else
            {
                if (selected_players[0].getHP() > selected_players[1].getHP())
                {
                    selected_players[0] = fight.enemyPlayer1Attack(selected_players[0]);
                }
                else
                {
                    selected_players[1] = fight.enemyPlayer2Attack(selected_players[1]);
                }
                selected_players[1] = fight.player2StatusCheck(selected_players[1]);
                fight.setPlayerTurn();
            }
        }
        selected_players[0] = fight.player1VictoryMenu(selected_players[0]);
        selected_players[1] = fight.player2VictoryMenu(selected_players[1]);
        shopCall();
        return;
    }
    //generates a shop and randomizes the items, shows it to player with advantage, then to player without, randomizing in between
    void Game :: shopCall()
    {
        Item_Shop Big_Store = Item_Shop(All_Items, All_Potions, 21, 9);
        Big_Store.storeRefresh();
        if (player1_turn == true)
        {
            cout << endl << "----------------------------------------------" << endl;
            cout << endl;
            selected_players[0] = Big_Store.shopMenu(selected_players[0]);
            Big_Store.storeRefresh();
            cout << endl << "----------------------------------------------" << endl;
            cout << endl;
            selected_players[1] = Big_Store.shopMenu(selected_players[1]);
            return;
        }
        else if (player1_turn == false)
        {
            cout << endl << "----------------------------------------------" << endl;
            cout << endl;
            selected_players[1] = Big_Store.shopMenu(selected_players[1]);
            Big_Store.storeRefresh();
            cout << endl << "----------------------------------------------" << endl;
            cout << endl;
            selected_players[0] = Big_Store.shopMenu(selected_players[0]);
            return;
        }
    }
    //generates a shop and passes the player to it
    Entity Game :: soloShopCall(Entity player1)
    {
        Entity player = player1;
        cout << endl << "----------------------------------------------" << endl;
        cout << endl;
        cout << "Would you like to visit the shop?" << endl << "1. Yes" << "     " << "2. No" << endl;
        int choice;
        cin >> choice;
        while (choice != 1 && choice != 2)
        {
            if (choice == 1 || choice == 2)
            {
                break;
            }
            else
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "Not an available option, please try again" << endl;
                choice = 0;
                cout << "Would you like to visit the shop?" << endl << "1. Yes" << "     " << "2. No" << endl;
                cin >> choice;
            }
        }
        if (choice == 1)
        {
            Item_Shop store = Item_Shop(All_Items, All_Potions, 21, 9);
            store.storeRefresh();
            player = store.shopMenu(player);
            return player;
        }
        else
        {
            return player;
        }
    }

    void loadRiddles(string filename, riddle _load_to[], const int loading_size)
    {
        ifstream npc;
        npc.open(filename);
        int place = 0;

        while (!npc.eof())
        {
            string line;
            getline(npc, line);
            string holder[2];
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
            _load_to[place].riddle = holder[0];
            _load_to[place].answer = holder[1];
            place = place + 1;
        }
        return;
    }
    //prints a wide variety of stats to the final stats exit file, might add a system line to print the file at the end of combat using cat
void Game :: finalPrintOut()
{
    ofstream printer;
    printer.open("a_finalstats.txt");
    printer << "New game: " << endl << endl;
    printer << "----------------------------------------------" << endl << endl;
    printer << "User: " << selected_players[0].getUser() << endl;
    printer << "Character: " << selected_players[0].getName() << endl;
    printer << "Health: " << selected_players[0].getHP() << endl;
    printer << "Stamina: " << selected_players[0].getStamina() << endl;
    printer << "Location: " << selected_players[0].getLocation() << endl;
    printer << "Gold: " << selected_players[0].getGold() << endl;
    printer << "Item Count: " << selected_players[0].getEquipmentCount() << endl << selected_players[0].getBackpackCount() << endl;
    printer << "Potion Count: " << selected_players[0].getPotionCount() << endl;
    printer << "Dead: " << selected_players[0].death() << endl;
    printer << "Turns taken: " << selected_players[0].getTurnsTaken() << endl;
    printer << endl << "----------------------------------------------" << endl << endl;
    printer << "User: " << selected_players[1].getUser() << endl;
    printer << "Character: " << selected_players[1].getName() << endl;
    printer << "Health: " << selected_players[1].getHP() << endl;
    printer << "Stamina: " << selected_players[1].getStamina() << endl;
    printer << "Location: " << selected_players[0].getLocation() << endl;
    printer << "Gold: " << selected_players[1].getGold() << endl;
    printer << "Item Count: " << selected_players[1].getEquipmentCount() << endl << selected_players[1].getBackpackCount() << endl;
    printer << "Potion Count: " << selected_players[1].getPotionCount() << endl;
    printer << "Dead: " << selected_players[1].death() << endl;
    printer << "Turns taken: " << selected_players[1].getTurnsTaken() << endl;
    printer << endl << "----------------------------------------------" << endl << endl;
    printer.close();
    return;
}