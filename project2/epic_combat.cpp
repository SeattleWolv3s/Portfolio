#include "epic_combat.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

//as all functions have a duplicate, i will only be commenting on one of each

    Epic_Combat :: Epic_Combat()
    {
        //the standard initializer is never used but i prefer to have it present anyway
    }

    Epic_Combat :: Epic_Combat(Entity selected_players[], Entity epic_enemies[], const int player_count, const int boss_count)
    {
        //adaptable randomizer to select the boss from the given array followed by a series of determinants for who goes first, a player turn consists of player 1 and player 2 going, followed by the boss
        srand(time(NULL));
        int boss_choice = rand() % boss_count;
        Boss = epic_enemies[boss_choice];
        Entity player1 = selected_players[0];
        Entity player2 = selected_players[1];

        if (player1.getAdvantage() == true && player2.getAdvantage() == false)
        {
            player1_turn = true;
        }

        else if ((player1.getAdvantage() == true && player2.getAdvantage() == true) || (player1.getAdvantage() == false && player2.getAdvantage() == false))
        {
            int dice_roll = rand() % 20 + 1;

            if (dice_roll >= 1 && dice_roll <= 10)
            {
                player1_turn = true;
            }

            else 
            {
                player1_turn = false;
            }
        }

        else if (player1.getAdvantage() == false && player2.getAdvantage() == true)
        {
            player1_turn = false;
        }

        if (Boss.getAdvantage() == true && (player1.getAdvantage() == true || player2.getAdvantage() == true))
        {
            int initiative = rand() % 20 + 1;

            if (initiative >=15)
            {
                player1_turn = true;
            }

            else 
            {
                player1_turn = false;
            }
        }
        
        else if (Boss.getAdvantage() == true && (player1.getAdvantage() == false and player2.getAdvantage() == false))
        {
            player1_turn = false;
        }
    }

    void Epic_Combat :: bossPicker(Entity selected_players[], Entity epic_enemies[], const int player_count, const int boss_count)
    {
        //clone of constructor above, used in instances where default constructor is called, never actually called on in game
        Entity player1 = selected_players[0];
        Entity player2 = selected_players[1];
        srand(time(NULL));
        int boss_choice = rand() % boss_count;
        Boss = epic_enemies[boss_choice];

        if (player1.getAdvantage() == true && player2.getAdvantage() == false)
        {
            player1_turn = true;
        }

        else if ((player1.getAdvantage() == true && player2.getAdvantage() == true) || (player1.getAdvantage() == false && player2.getAdvantage() == false))
        {
            int dice_roll = rand() % 20 + 1;

            if (dice_roll >= 1 && dice_roll <= 10)
            {
                player1_turn = true;
            }

            else 
            {
                player1_turn = false;
            }
        }

        else if (player1.getAdvantage() == false && player2.getAdvantage() == true)
        {
            player1_turn = false;
        }

        if (Boss.getAdvantage() == true && (player1.getAdvantage() == true || player2.getAdvantage() == true))
        {
            int initiative = rand() % 20 + 1;

            if (initiative >=15)
            {
                player1_turn = true;
            }

            else 
            {
                player1_turn = false;
            }
        }
        
        else if (Boss.getAdvantage() == true && (player1.getAdvantage() == false and player2.getAdvantage() == false))
        {
            player1_turn = false;
        }
        return;
    }

    Entity Epic_Combat :: player2CombatMenu(Entity player_b, Entity player_a)
    {
        //duplicate of combat menu from combat, but with no flee option, and only runs while both players are above 0 health.
        Entity player1 = player_a;
        Entity player2 = player_b;
        if (Boss.getHP() > 0 && (player1.getHP() > 0 || player2.getHP() > 0))
        {
                player2 = player2StatusCheck(player2);
                int choice = 1;
                string menu_choice;

                string menu0 = "Player 2, select from the following options:"; 
                string menu1 = "1. Attack";
                string menu2 = "2. Change Equipment";
                string menu3 = "3. Use a potion";

                do 
                {

                    int menu = 0;
                    int test = 0;

                    do 
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl;
                        cin >> menu_choice;

                        while (menu_choice.length() == 0 || menu_choice.length() > 1) 
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "Invalid input. Please enter a valid choice (1-3)" << endl;
                            cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl;
                            cin >> menu_choice;
                        }

                        while (!isdigit(menu_choice[0])) 
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "Invalid input. Please enter a valid choice (1-3)" << endl;
                            cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl;
                            menu_choice = "";
                            cin >> menu_choice;
                        }

                        test = stoi(menu_choice);
                        
                        if (!(test < 4 && test > 0)) 
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "Invalid input. Please enter a valid choice (1-3)" << endl;
                        }

                    } while (!(test < 4 && test > 0));

                    menu = stoi(menu_choice);
                    choice = menu;

                    if (menu == 1) 
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        player2Attack(player2);
                    }

                    else if (menu == 2) 
                    {
                        player2 = player2ItemMenu(player2);
                    }

                    else if (menu == 3) 
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        player2.usePotion();
                        break;
                    }

                } while (choice < 4 && choice > 0);

        }
        player2.death();
        return player2;
    }

    Entity Epic_Combat :: player1CombatMenu(Entity player_a, Entity player_b)
    {
        //duplicate of above
        Entity player1 = player_a;
        Entity player2 = player_b;
        if (Boss.getHP() > 0 && (player1.getHP() > 0 || player2.getHP() > 0))
        {
                player1 = player1StatusCheck(player1);
                int choice = 1;
                string menu_choice;

                string menu0 = "Player 1, select from the following options:"; 
                string menu1 = "1. Attack";
                string menu2 = "2. Change Equipment";
                string menu3 = "3. Use a potion";

                do 
                {

                        int menu = 0;
                        int test = 0;

                    do 
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl;
                        cin >> menu_choice;

                        while (menu_choice.length() == 0 || menu_choice.length() > 1) 
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "Invalid input. Please enter a valid choice (1-3)" << endl;
                            cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl;
                            cin >> menu_choice;
                        }

                        while (!isdigit(menu_choice[0])) 
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "Invalid input. Please enter a valid choice (1-3)" << endl;
                            cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl;
                            menu_choice = "";
                            cin >> menu_choice;
                        }

                        test = stoi(menu_choice);
                        
                        if (!(test < 4 && test > 0)) 
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << "Invalid input. Please enter a valid choice (1-3)" << endl;
                        }

                    } while (!(test < 4 && test > 0));

                    menu = stoi(menu_choice);
                    choice = menu;

                    if (menu == 1) 
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        player1Attack(player1);
                    }

                    else if (menu == 2) 
                    {
                        player1 = player1ItemMenu(player1);
                    }

                    else if (menu == 3) 
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        player1.usePotion();
                        break;
                    }

                } while (choice < 4 && choice > 0);
        }
        player1.death();
        return player1;
    }

    void Epic_Combat :: player1Attack(Entity player_a)
    {
        //same as standard combat attack
        Entity player1 = player_a;
        srand(time(NULL));
        int attack_roll = rand() % 5 + 1;
        if (attack_roll == 1)
        {
            return;
        }
        else
        {
            if (player1.findBoon("Argos' Bite") == true || player1.findBoon("My Bite") == true)
            {
                srand(time(NULL));
                int poison = rand() % 10 + 1;
                if (player1.findBoon("Argos' Bite") == true && poison <= 2)
                {
                    Boss.setCondition('P');
                }
                else if (player1.findBoon("My Bite") == true && poison <= 3)
                {
                    Boss.setCondition('P');
                }
            }
            double percent_fire = player1.getFireDamage() / player1.getTotalDamage();
            double percent_water = player1.getWaterDamage() / player1.getTotalDamage();
            double percent_earth = player1.getEarthDamage() / player1.getTotalDamage();
            double percent_air = player1.getAirDamage() / player1.getTotalDamage();
            double damage = rand() % int(player1.getTotalDamage()) + 1;
            double crit_damage = damage;
            if (Boss.getWeakness() == 'F')
            {
                crit_damage = damage + (damage * percent_fire);
            }

            else if (Boss.getWeakness() == 'W')
            {
                crit_damage = damage + (damage * percent_water);
            }

            else if (Boss.getWeakness() == 'E')
            {
                crit_damage = damage + (damage * percent_earth);
            }

            else if (Boss.getWeakness() == 'A')
            {
                crit_damage = damage + (damage * percent_air);
            }
            double damage_dealt = crit_damage;
            if (player1.findBoon("Athena's Wisdom") == true)
            {
                damage_dealt = (crit_damage - (Boss.getDefense() * 0.85)) * 3.5;
            }
            else
            {
                damage_dealt = (crit_damage - Boss.getDefense()) * 3.5;
            }
            if (damage_dealt > 0)
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "Player 1 dealt " << damage_dealt << " damage to the enemy!" << endl;
                Boss.setHP(Boss.getHP() - damage_dealt);
            }
            else
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "Player 1 dealt 0 damage to the enemy" << endl;
            }
            Boss.death();
            return;
        }
    }

    void Epic_Combat :: player2Attack(Entity player_b)
    {
        //duplicate of above
        Entity player2 = player_b;
        srand(time(NULL));
        int attack_roll = rand() % 5 + 1;
        if (attack_roll == 1)
        {
            return;
        }
        else
        {
            if (player2.findBoon("Argos' Bite") == true || player2.findBoon("My Bite") == true)
            {
                srand(time(NULL));
                int poison = rand() % 10 + 1;
                if (player2.findBoon("Argos' Bite") == true && poison <= 2)
                {
                    Boss.setCondition('P');
                }
                else if (player2.findBoon("My Bite") == true && poison <= 3)
                {
                    Boss.setCondition('P');
                }
            }
            double percent_fire = player2.getFireDamage() / player2.getTotalDamage();
            double percent_water = player2.getWaterDamage() / player2.getTotalDamage();
            double percent_earth = player2.getEarthDamage() / player2.getTotalDamage();
            double percent_air = player2.getAirDamage() / player2.getTotalDamage();
            double damage = rand() % int(player2.getTotalDamage()) + 1;
            double crit_damage = damage;
            if (Boss.getWeakness() == 'F')
            {
                crit_damage = damage + (damage * percent_fire);
            }

            else if (Boss.getWeakness() == 'W')
            {
                crit_damage = damage + (damage * percent_water);
            }

            else if (Boss.getWeakness() == 'E')
            {
                crit_damage = damage + (damage * percent_earth);
            }

            else if (Boss.getWeakness() == 'A')
            {
                crit_damage = damage + (damage * percent_air);
            }
            double damage_dealt = crit_damage;
            if (player2.findBoon("Athena's Wisdom") == true)
            {
                damage_dealt = (crit_damage - (Boss.getDefense() * 0.85)) * 3.5;
            }
            else
            {
                damage_dealt = (crit_damage - Boss.getDefense()) * 3.5;
            }
            if (damage_dealt > 0)
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "Player 2 dealt " << damage_dealt << " damage to the enemy!" << endl;
                Boss.setHP(Boss.getHP() - damage_dealt);
            }
            else
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "Player 2 dealt 0 damage to the enemy" << endl;
            }
            Boss.death();
            return;
        }
    }

    Entity Epic_Combat :: enemyPlayer1Attack(Entity player_a)
    {
        //same as normal enemy attack, just split for player 1 and player 2 as my pass by reference method cannot pass two entities back at once
        Entity player1 = player_a;
        srand(time(NULL));
        if (Boss.getHP() < 25)
        {
            //a function originally implemented in standard combat but left too little loot behind and caused more bugs than it was worth, trying to implement in epic combat but may be deleted
            Boss.usePotionEnemy();
            return player1;
        }

        else
        {
            srand(time(NULL));
            int miss = rand() % 5 + 1;
            if (miss == 1)
            {
                return player1;
            }
            else 
            {
                double percent_fire = Boss.getFireDamage() / Boss.getTotalDamage();
                if (player1.findBoon("Ocean's Grasp") == true)
                {
                    Boss.setWaterDamage(Boss.getWaterDamage() * 0.8);
                    Boss.setNetDamage();
                }
                double percent_water = Boss.getWaterDamage() / Boss.getTotalDamage();
                double percent_earth = Boss.getEarthDamage() / Boss.getTotalDamage();
                double percent_air = Boss.getAirDamage() / Boss.getTotalDamage();
                double damage = rand() % int(Boss.getTotalDamage()) + 1;
                double crit_damage = damage;
                if (player1.findBoon("Flight of Hermes") == true)
                {
                    srand(time(NULL));
                    int dodge = rand() % 5 + 1;
                    if (dodge == 1)
                    {
                        return player1;
                    }
                }
                else 
                {
                    if (player1.getWeakness() == 'F')
                    {
                        crit_damage = damage + (damage * percent_fire);
                    }

                    else if (player1.getWeakness() == 'W')
                    {
                        crit_damage = damage + (damage * percent_water);
                    }

                    else if (player1.getWeakness() == 'E')
                    {
                        crit_damage = damage + (damage * percent_earth);
                    }

                    else if (player1.getWeakness() == 'A')
                    {
                        crit_damage = damage + (damage * percent_air);
                    }
                    double damage_dealt = (crit_damage - player1.getDefense()) * 2.5;
                    if (damage_dealt > 0)
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "The enemy dealt " << damage_dealt << " to player 1!" << endl;
                        player1.setHP(player1.getHP() - damage_dealt);
                    }
                    else
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "The enemy dealt 0 damage to player 1!" << endl;
                    }
                    player1.death();
                }
            }
        }
        return player1;
    }

    Entity Epic_Combat :: enemyPlayer2Attack(Entity player_b)
    {
        //duplicate of above
        Entity player2 = player_b;
        srand(time(NULL));
        if (Boss.getHP() < 25)
        {
            Boss.usePotionEnemy();
            return player2;
        }

        else
        {
            srand(time(NULL));
            int miss = rand() % 5 + 1;
            if (miss == 1)
            {
                return player2;
            }
            else 
            {
                double percent_fire = Boss.getFireDamage() / Boss.getTotalDamage();
                if (player2.findBoon("Ocean's Grasp") == true)
                {
                    Boss.setWaterDamage(Boss.getWaterDamage() * 0.8);
                    Boss.setNetDamage();
                }
                double percent_water = Boss.getWaterDamage() / Boss.getTotalDamage();
                double percent_earth = Boss.getEarthDamage() / Boss.getTotalDamage();
                double percent_air = Boss.getAirDamage() / Boss.getTotalDamage();
                double damage = rand() % int(Boss.getTotalDamage()) + 1;
                double crit_damage = damage;
                if (player2.findBoon("Flight of Hermes") == true)
                {
                    srand(time(NULL));
                    int dodge = rand() % 5 + 1;
                    if (dodge == 1)
                    {
                        return player2;
                    }
                }
                else 
                {
                    if (player2.getWeakness() == 'F')
                    {
                        crit_damage = damage + (damage * percent_fire);
                    }

                    else if (player2.getWeakness() == 'W')
                    {
                        crit_damage = damage + (damage * percent_water);
                    }

                    else if (player2.getWeakness() == 'E')
                    {
                        crit_damage = damage + (damage * percent_earth);
                    }

                    else if (player2.getWeakness() == 'A')
                    {
                        crit_damage = damage + (damage * percent_air);
                    }
                    double damage_dealt = (crit_damage - player2.getDefense()) * 2.5;
                    if (damage_dealt > 0)
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "The enemy dealt " << damage_dealt << " to player 2!" << endl;
                        player2.setHP(player2.getHP() - damage_dealt);
                    }
                    else
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "The enemy dealt 0 damage to player 2!" << endl;
                    }
                    player2.death();
                }
            }
        }
        return player2;
    }


    Entity Epic_Combat :: player1ItemMenu(Entity player_a)
    {
        //same as standard combat menu 
        Entity player1 = player_a;
        cout << endl << "----------------------------------------------" << endl;
        cout << endl;
        cout << "In the midst of combat, you have the opportunity to access your gear, do you wish to change your equipment or use a potion?" << endl << "1. Change Equipment" << endl << "2. Use a potion" << endl;
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
                cout << "In the midst of combat, you have the opportunity to access your gear, do you wish to change your equipment or use a potion?" << endl << "1. Change Equipment" << endl << "2. Use a potion" << endl;
                cin >> choice;
            }
        }

        if (choice == 1)
        {
            cout << endl << "----------------------------------------------" << endl;
            cout << endl;
            player1.displayEquipped();
            player1.displayBackpack();
            cout << endl << "----------------------------------------------" << endl;
            cout << endl;
            cout << "Do you want to change your equipment?" << endl << "1. Yes" << endl << "2. No" << endl;
            int gear_swap;
            cin >> gear_swap;
            while (gear_swap != 1 && gear_swap != 2)
            {
                if (gear_swap == 1 || gear_swap == 2)
                {
                    break;
                }

                else 
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Not an available option, please try again" << endl;
                    gear_swap = 0;
                    cout << "Do you want to change your equipment?" << endl << "1. Yes" << endl << "2. No" << endl;
                    cin >> gear_swap;
                }
            }
                
            if (gear_swap == 1)
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "What item do you want to unequip (1 or 2)?" << endl;
                player1.displayEquipped();
                int removed;
                cin >> removed;
                while (removed != 1 && removed != 2)
                {
                    if (removed == 1 || removed == 2)
                    {
                        break;
                    }
                        
                    else
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "Not an available option, please try again" << endl;
                        removed = 0;
                        cout << "What item do you want to unequip (1 or 2)?" << endl;
                        cin >> removed;
                    }
                }
                player1.unequip(player1.getActiveEquipment(removed - 1).name);
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                player1.equipItem();
            }
        }
        return player1;
    }

    Entity Epic_Combat :: player2ItemMenu(Entity player_b)
    {
        //duplicate of above
        Entity player2 = player_b;
        cout << endl << "----------------------------------------------" << endl;
        cout << endl;
        cout << "In the midst of combat, you have the opportunity to access your gear, do you wish to change your equipment or use a potion?" << endl << "1. Change Equipment" << endl << "2. Use a potion" << endl;
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
                cout << "In the midst of combat, you have the opportunity to access your gear, do you wish to change your equipment or use a potion?" << endl << "1. Change Equipment" << endl << "2. Use a potion" << endl;
                cin >> choice;
            }
        }

        if (choice == 1)
        {
            cout << endl << "----------------------------------------------" << endl;
            cout << endl;
            player2.displayEquipped();
            player2.displayBackpack();
            cout << endl << "----------------------------------------------" << endl;
            cout << endl;
            cout << "Do you want to change your equipment?" << endl << "1. Yes" << endl << "2. No" << endl;
            int gear_swap;
            cin >> gear_swap;
            while (gear_swap != 1 && gear_swap != 2)
            {
                if (gear_swap == 1 || gear_swap == 2)
                {
                    break;
                }

                else 
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Not an available option, please try again" << endl;
                    gear_swap = 0;
                    cout << "Do you want to change your equipment?" << endl << "1. Yes" << endl << "2. No" << endl;
                    cin >> gear_swap;
                }
            }
                
            if (gear_swap == 1)
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "What item do you want to unequip (1 or 2)?" << endl;
                player2.displayEquipped();
                int removed;
                cin >> removed;
                while (removed != 1 && removed != 2)
                {
                    if (removed == 1 || removed == 2)
                    {
                        break;
                    }
                        
                    else
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "Not an available option, please try again" << endl;
                        removed = 0;
                        cout << "What item do you want to unequip (1 or 2)?" << endl;
                        cin >> removed;
                    }
                }
                player2.unequip(player2.getActiveEquipment(removed - 1).name);
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                player2.equipItem();
            }
        }
        return player2;
    }

    Entity Epic_Combat :: player2VictoryMenu(Entity player_b)
    {
        //same as combat victory menu though both players have the chance to take all available loot as only one felt unfair
        Entity player2 = player_b;
        int choice = 1;
        string menu_choice;

        string menu0 = "Select from the following options:"; 
        string menu1 = "1. Item Menu";
        string menu2 = "2. Loot enemy";
        string menu3 = "3. Depart";

        do 
        {

            int menu = 0;
            int test = 0;

            do 
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl;
                cin >> menu_choice;

                while (menu_choice.length() == 0 || menu_choice.length() > 1) 
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Invalid input. Please enter a valid choice (1-3)" << endl;
                    cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl;
                    cin >> menu_choice;
                }

                while (!isdigit(menu_choice[0])) 
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Invalid input. Please enter a valid choice (1-3)" << endl;
                    cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl;
                    menu_choice = "";
                    cin >> menu_choice;
                }

                test = stoi(menu_choice);
                    
                if (!(test < 5 && test > 0)) 
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Invalid input. Please enter a valid choice (1-3)" << endl;
                }

            } while (!(test < 4 && test > 0));

            menu = stoi(menu_choice);
            choice = menu;

            if (menu == 1) 
            {
                player2 = player2ItemMenu(player2);
            }

            else if (menu == 2) 
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "Available Loot: " << endl;
                cout << "Gold: " << Boss.getGold() << endl;
                Boss.displayEquipped();
                Boss.displayPotions();
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "What would you like to take?" << endl << "1. Just gold" << endl << "2. Enemy Item and gold" << endl << "3. Enemy potion and gold" << endl << "4. All available loot" << endl;
                int looter;
                cin >> looter;
                while (looter != 1 && looter != 2 && looter != 3 && looter != 4)
                {
                    if (looter == 1 || looter == 2 || looter == 3 || looter == 4)
                    {
                        break;
                    }

                    else 
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "Not an available option, please try again" << endl;
                        looter = 0;
                        cout << "What would you like to take?" << endl << "1. Just gold" << endl << "2. Enemy Item and gold" << endl << "3. Enemy potion and gold" << endl << "4. All available loot" << endl;
                        cin >> looter;
                    }
                }

                if (looter == 1)
                {
                    player2.setGold(player2.getGold() + Boss.getGold());
                }   

                else if (looter == 2)
                {
                    player2.setGold(player2.getGold() + Boss.getGold());
                    player2.setItem(Boss.getActiveEquipment(1));
                }

                else if (looter == 3)
                {
                    player2.setGold(player2.getGold() + Boss.getGold());
                    player2.setPotion(Boss.getPotion(1));
                }

                else if (looter == 4)
                {
                    player2.setGold(player2.getGold() + Boss.getGold());
                    player2.setItem(Boss.getActiveEquipment(1));
                    player2.setPotion(Boss.getPotion(1));
                }
            }

            else if (menu == 3) 
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "The gods smile upon you for providing them entertainment and secretly hope to watch you make it to Ithaca" << endl;
                break;
            }
        } while (choice < 4 && choice > 0);
        return player2;
    }

    Entity Epic_Combat :: player1VictoryMenu(Entity player_a)
    {
        //duplicate of above
        Entity player1 = player_a;
        int choice = 1;
        string menu_choice;

        string menu0 = "Select from the following options:"; 
        string menu1 = "1. Item Menu";
        string menu2 = "2. Loot enemy";
        string menu3 = "3. Depart";

        do 
        {

            int menu = 0;
            int test = 0;

            do 
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl;
                cin >> menu_choice;

                while (menu_choice.length() == 0 || menu_choice.length() > 1) 
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Invalid input. Please enter a valid choice (1-3)" << endl;
                    cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl;
                    cin >> menu_choice;
                }

                while (!isdigit(menu_choice[0])) 
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Invalid input. Please enter a valid choice (1-3)" << endl;
                    cout << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl;
                    menu_choice = "";
                    cin >> menu_choice;
                }

                test = stoi(menu_choice);
                    
                if (!(test < 5 && test > 0)) 
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Invalid input. Please enter a valid choice (1-3)" << endl;
                }

            } while (!(test < 4 && test > 0));

            menu = stoi(menu_choice);
            choice = menu;

            if (menu == 1) 
            {
                player1 = player1ItemMenu(player1);
            }

            else if (menu == 2) 
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "Available Loot: " << endl;
                cout << "Gold: " << Boss.getGold() << endl;
                Boss.displayEquipped();
                Boss.displayPotions();
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "What would you like to take?" << endl << "1. Just gold" << endl << "2. Enemy Item and gold" << endl << "3. Enemy potion and gold" << endl << "4. All available loot" << endl;
                int looter;
                cin >> looter;
                while (looter != 1 && looter != 2 && looter != 3 && looter != 4)
                {
                    if (looter == 1 || looter == 2 || looter == 3 || looter == 4)
                    {
                        break;
                    }

                    else 
                    {
                        cout << endl << "----------------------------------------------" << endl;
                        cout << endl;
                        cout << "Not an available option, please try again" << endl;
                        looter = 0;
                        cout << "What would you like to take?" << endl << "1. Just gold" << endl << "2. Enemy Item and gold" << endl << "3. Enemy potion and gold" << endl << "4. All available loot" << endl;
                        cin >> looter;
                    }
                }

                if (looter == 1)
                {
                    player1.setGold(player1.getGold() + Boss.getGold());
                }   

                else if (looter == 2)
                {
                    player1.setGold(player1.getGold() + Boss.getGold());
                    player1.setItem(Boss.getActiveEquipment(1));
                }

                else if (looter == 3)
                {
                    player1.setGold(player1.getGold() + Boss.getGold());
                    player1.setPotion(Boss.getPotion(1));
                }

                else if (looter == 4)
                {
                    player1.setGold(player1.getGold() + Boss.getGold());
                    player1.setItem(Boss.getActiveEquipment(1));
                    player1.setPotion(Boss.getPotion(1));
                }
            }

            else if (menu == 3) 
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "The gods smile upon you for providing them entertainment and secretly hope to watch you make it to Ithaca" << endl;
                break;
            }
        } while (choice < 4 && choice > 0);
        return player1;
    }

    Entity Epic_Combat :: player1StatusCheck(Entity player_a)
    {
        //runs status based on turn, same as standard combat
        Entity player1 = player_a;
        if (player1_turn == true)
        {
            if (player1.getCondition() == 'D')
            {
                player1.setStamina(player1.getStamina() - 5);
            }
            
            else if (player1.getCondition() == 'P')
            {
                player1.setHP(player1.getHP() - 5);
            }

            if (player1.getStamina() == 0)
            {
                player1.setStamina(player1.getStamina() + 10);
            }
            return player1;
        }

        else if (player1_turn == false)
        {
            if (Boss.getCondition() == 'D')
            {
                Boss.setStamina(Boss.getStamina() - 5);
            }
            
            else if (Boss.getCondition() == 'P')
            {
                Boss.setHP(Boss.getHP() - 5);
            }

            if (Boss.getStamina() == 0)
            {
                Boss.setStamina(Boss.getStamina() + 10);
            }
            return player1;
        }
        return player1;
    }
    
    Entity Epic_Combat :: player2StatusCheck(Entity player_b)
    {
        //duplicate of above
        Entity player2 = player_b;
        if (player1_turn == true)
        {
            if (player2.getCondition() == 'D')
            {
                player2.setStamina(player2.getStamina() - 5);
            }
            
            else if (player2.getCondition() == 'P')
            {
                player2.setHP(player2.getHP() - 5);
            }

            if (player2.getStamina() == 0)
            {
                player2.setStamina(player2.getStamina() + 10);
            }
            return player2;
        }

        else if (player1_turn == false)
        {
            if (Boss.getCondition() == 'D')
            {
                Boss.setStamina(Boss.getStamina() - 5);
            }
            
            else if (Boss.getCondition() == 'P')
            {
                Boss.setHP(Boss.getHP() - 5);
            }

            if (Boss.getStamina() == 0)
            {
                Boss.setStamina(Boss.getStamina() + 10);
            }
            return player2;
        }
        return player2;
    }

    //getters are called on in game class to manage flow and stoppage of combat
    const double Epic_Combat :: getBossHealth()
    {
        return Boss.getHP();
    }

    const bool Epic_Combat :: getPlayerTurn()
    {
        return player1_turn;
    }

    //flips bool and ends
    void Epic_Combat :: setPlayerTurn()
    {
        if (player1_turn == true)
        {
            player1_turn = false;
            return;
        }
        else if (player1_turn == false)
        {
            player1_turn = true;
            return;
        }
    }

 
