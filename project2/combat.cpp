#include "combat.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cassert>
using namespace std;

    Combat :: Combat()
    {
        //assumes enemy goes first
        turn = false;
    }

    Combat :: Combat(Entity all_enemies[], const int enemy_size)    
    {
        EnemySelector(all_enemies, enemy_size);
        //checks for advantage and rolls for iniative if the enemy doesn't have advantage, originally planned to integrate epic combat into this class but didn't
        if (_enemy.getAdvantage() == true)
        {
            turn = false;
        }
        else
        {
            srand(time(NULL));
            int initiative = rand() % 20 + 1;
            if (initiative > 10)
            {
                turn = true;
            }
            else 
            {
                turn = false;
            }
        }
    }

    void Combat :: EnemySelector(Entity all_enemies[], const int enemy_size)
    {
        //rolls a random number then picks that index
        srand(time(NULL));
        int combatant = rand() % enemy_size;
        _enemy = all_enemies[combatant];
        return;
    }

    Entity Combat :: combatMenu(Entity player1)
    {
        Entity _player = player1;
        while (_enemy.getHP() > 0 && _player.getHP() > 0)
        {
            if (_player.death() == false)
            {
                if (turn == true)
                {
                    int choice = 1;
                    string menu_choice;

                    //shows the menu options and has input verification that rejects anything that isn't a number shown, recycled from encryption project
                    string menu0 = "Select from the following options:"; 
                    string menu1 = "1. Attack";
                    string menuA = "2. View Stats";
                    string menu2 = "3. Change Equipment";
                    string menu3 = "4. Use a potion";
                    string menu4 = "5. Attempt to flee";

                    do 
                    {

                        int menu = 0;
                        int test = 0;

                        do 
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            cout << menu0 << endl << menu1 << endl << menuA << endl << menu2 << endl << menu3 << endl << menu4 << endl;
                            cin >> menu_choice;

                            while (menu_choice.length() == 0 || menu_choice.length() > 1) 
                            {
                                cout << endl << "----------------------------------------------" << endl;
                                cout << endl;
                                cout << "Invalid input. Please enter a valid choice (1-4)" << endl;
                                cout << menu0 << endl << menu1 << endl << menuA << endl << menu2 << endl << menu3 << endl << menu4 << endl;
                                cin >> menu_choice;
                            }

                            while (!isdigit(menu_choice[0])) 
                            {
                                cout << endl << "----------------------------------------------" << endl;
                                cout << endl;
                                cout << "Invalid input. Please enter a valid choice (1-4)" << endl;
                                cout << menu0 << endl << menu1 << endl << menuA << endl << menu2 << endl << menu3 << endl << menu4 << endl;
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

                        //checks for non healthy statuses, performs an attack, and ends the turn
                        if (menu == 1) 
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            _player = statusCheck(_player);
                            playerAttack(_player);
                            break;
                        }

                        //displays the stat menu with a wide variety of options for stats, doesn't end turn
                        else if (menu == 2)
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            _player.printStats();
                        }

                        //status check and then offers the option to change equipment, does end turn if selected as changing equipment in d and d takes a full action
                        else if (menu == 3) 
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            _player = statusCheck(_player);
                            _player = itemMenu(_player);
                            break;
                        }

                        //allows the player to use a potion without ending their turn, bonus action in d and d
                        else if (menu == 4) 
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            _player.usePotion();
                        }

                        //status check, stamina reduction, random roll that lets the player escape if high enough but with the coward boon
                        else if (menu == 5) 
                        {
                            cout << endl << "----------------------------------------------" << endl;
                            cout << endl;
                            _player = statusCheck(_player);
                            _player.setStamina(_player.getStamina() - 35);
                            int escape = flee();
                            if (escape >= 7)
                            {
                                cout << endl << "----------------------------------------------" << endl;
                                cout << endl;
                                cout << "You successfully manage to escape combat, but in the hurry all loot was left behind and you find yourself exhausted" << endl;
                                _player.setBoon("Coward");
                                return _player;
                            }
                        }

                    } while (choice < 6 && choice > 0);
                    setTurn();
                }

                //enemy status check, enemy attack, displays enemy stats, then changes the turn
                else 
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    _player = statusCheck(_player);
                    _player = enemyAttack(_player);
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    _enemy.printBasicStats();
                    setTurn();
                }
            }
            else
            {
                return _player;
            }
        }

        //checks if enemy or player is dead and returns accordingly
        if (_enemy.death() == true)
        {   
            cout << endl << "----------------------------------------------" << endl;
            cout << endl;
            _player = statusCheck(_player);
        }
        else if (_player.death() == true)
        {
            cout << "Your warrior has faced a tragic death on the seas, leaving only your opponent standing, may the gods bless you more bountifully next time" << endl;
            assert(1 == 0);
        }
        return _player;
    }

    void Combat :: playerAttack(Entity player1)
    {
        Entity _player = player1;
        //rolls for a miss, ends turn if miss
        srand(time(NULL));
        double attack_roll = rand() % 5 + 1;
        if (attack_roll == 1)
        {
            return;
        }
        else
        {
            //checks for Argos' bite to poison
            if (_player.findBoon("Argos' Bite") == true || _player.findBoon("My Bite") == true)
            {
                srand(time(NULL));
                int poison = rand() % 10;
                if (_player.findBoon("Argos' Bite") == true && poison <= 2)
                {
                    _enemy.setCondition('P');
                    cout << "The enemy has been poisoned!" << endl;
                }
                else if (_player.findBoon("My Bite") == true && poison <= 3)
                {
                    _enemy.setCondition('P');
                    cout << "The enemy has been poisoned!" << endl;
                }
            }
            //calculates the percent from all elements of damage, chose to omit elemental resistances as this would cycle, and damage already feels flimsy
            double percent_fire = _player.getFireDamage() / _player.getTotalDamage();
            double percent_water = _player.getWaterDamage() / _player.getTotalDamage();
            double percent_earth = _player.getEarthDamage() / _player.getTotalDamage();
            double percent_air = _player.getAirDamage() / _player.getTotalDamage();
            double damage = rand() % int(_player.getTotalDamage()) + 1;
            double crit_damage = damage;
            //adds damage based on the enemy's weakness
            if (_enemy.getWeakness() == 'F')
            {
                crit_damage = damage + (damage * percent_fire);
            }

            else if (_enemy.getWeakness() == 'W')
            {
                crit_damage = damage + (damage * percent_water);
            }

            else if (_enemy.getWeakness() == 'E')
            {
                crit_damage = damage + (damage * percent_earth);
            }

            else if (_enemy.getWeakness() == 'A')
            {
                crit_damage = damage + (damage * percent_air);
            }
            double damage_dealt = crit_damage;
            //reduces enemy defense by 15% if athena's spear is equipped and then multiplies by 3.5
            if (_player.findBoon("Athena's Wisdom") == true)
            {
                damage_dealt = (crit_damage - (_enemy.getDefense() * 0.85)) * 3.5;
            }
            else
            {
                damage_dealt = (crit_damage - _enemy.getDefense()) * 3.5;
            }
            if (damage_dealt > 0)
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                //displays how much damage is dealt and reduces enemy health accordingly 
                cout << "You dealt " << damage_dealt << " damage to the enemy!" << endl;
                _enemy.setHP(_enemy.getHP() - damage_dealt);
                cout << _enemy.getHP() << endl;
            }
            else 
            {
                //if damage is 0 due to enemy defense, it is auto set to 3.5 to prevent combat from dragging too long.
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                damage_dealt = 3.5;
                cout << "You dealt " << damage_dealt << " damage to the enemy!" << endl;
                _enemy.setHP(_enemy.getHP() - damage_dealt);
            }
            _enemy.death();
        }
        return;
    }

    Entity Combat :: enemyAttack(Entity player1)
    {
        //most functions act as pass-by-reference for entity objects, a handwritten alternative to pointers, cloning the player, altering, and returning the changed clone
        Entity _player = player1;
        srand(time(NULL));

            int attack_roll = rand() % 5 + 1;
            if (attack_roll == 1)
            {
                return _player;
            }
            else
            {
                //roll for dodge
                if (_player.findBoon("Flight of Hermes") == true)
                {
                    srand(time(NULL));
                    int dodge = rand() % 5 + 1;
                    if (dodge == 1)
                    {
                        cout << "Hermes' winged sandals answer your call and safely carry you from the enemy's swing" << endl;
                        return _player;
                    }
                }
                double percent_fire = _enemy.getFireDamage() / _enemy.getTotalDamage();
                //poseidon's shell damage reduction is just a permanent application to the enemy
                if (_player.findBoon("Ocean's Grasp") == true)
                {
                    _enemy.setWaterDamage(_enemy.getWaterDamage() * 0.8);
                    _enemy.setNetDamage();
                }
                double percent_water = _enemy.getWaterDamage() / _enemy.getTotalDamage();
                double percent_earth = _enemy.getEarthDamage() / _enemy.getTotalDamage();
                double percent_air = _enemy.getAirDamage() / _enemy.getTotalDamage();
                double damage = rand() % int(_enemy.getTotalDamage()) + 1;
                double crit_damage = damage;
                //all damage is calculated the same as the player, but default damage is set to 1 instead of 2.5 as players died too quickly at 2.5 or not at all at 0
                if (_player.getWeakness() == 'F')
                {
                    crit_damage = damage + (damage * percent_fire);
                }

                else if (_player.getWeakness() == 'W')
                {
                    crit_damage = damage + (damage * percent_water);
                }

                else if (_player.getWeakness() == 'E')
                {
                    crit_damage = damage + (damage * percent_earth);
                }

                else if (_player.getWeakness() == 'A')
                {
                    crit_damage = damage + (damage * percent_air);
                }
                double damage_dealt = (crit_damage - _player.getDefense()) * 2.5;
                if (damage_dealt > 0)
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "The enemy dealt " << damage_dealt << " to you!" << endl;
                    _player.setHP(_player.getHP() - damage_dealt);
                }
                else
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    damage_dealt = 1;
                    cout << "The enemy dealt " << damage_dealt << " to you!" << endl;
                    _player.setHP(_player.getHP() - damage_dealt);
                }
                _player.death();
            }
        return _player;
    }

    Entity Combat :: itemMenu(Entity player1)
    {
        //standard pass by reference function with my menu skeleton being refitted for various entity member functions
        Entity _player = player1;
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
            _player.displayEquipped();
            _player.displayBackpack();
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
                //the next 30 lines show the standard input verification applied across the game, while I wish i had implented an exit option smoother, it still functions well
                cout << "What item do you want to unequip (1 or 2)?" << endl;
                _player.displayEquipped();
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
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                _player.unequip(_player.getActiveEquipment(removed - 1).name);
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                _player.equipItem();
                turn = false;
            }
        }
        return _player;
    }

    void Combat :: setTurn()
    {
        //just flips the bool and ends
        if (turn == true)
        {
            turn = false;
            return;
        }

        if (turn == false)
        {
            turn = true;
            return;
        }
    }

    const int Combat :: flee()
    {
        //only generates the random number, the rest is handled by the combat menu as that is what is called on in the game class
        cout << endl << "----------------------------------------------" << endl;
        cout << endl;
        cout << "You attempt to flee from combat" << endl;
        srand(time(NULL));
        int escape_chance = rand() % 10 + 1;
        return escape_chance;
    }

    Entity Combat :: victoryMenu(Entity player1)
    {
        //standard pass by reference menu with standard refit skeleton using enemy values to add loot
        Entity _player = player1;
        int choice = 1;
        string menu_choice;

        string menu0 = "Select from the following options:"; 
        string menu1 = "1. Item Menu";
        string menu2 = "2. Loot enemy";
        string menu4 = "3. Depart";

        do 
        {

                int menu = 0;
                int test = 0;

            do 
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << menu0 << endl << menu1 << endl << menu2  << endl << menu4 << endl;
                cin >> menu_choice;

                while (menu_choice.length() == 0 || menu_choice.length() > 1) 
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Invalid input. Please enter a valid choice (1-3)" << endl;
                    cout << menu0 << endl << menu1 << endl << menu2 << endl << menu4 << endl;
                    cin >> menu_choice;
                }

                while (!isdigit(menu_choice[0])) 
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Invalid input. Please enter a valid choice (1-3)" << endl;
                    cout << menu0 << endl << menu1 << endl << menu2 << endl << menu4 << endl;
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
                _player = itemMenu(_player);
            }

            else if (menu == 2) 
            {
                cout << endl << "----------------------------------------------" << endl;
                cout << endl;
                cout << "Available Loot: " << endl;
                cout << "Gold: " << _enemy.getGold() << endl;
                _enemy.displayEquipped();
                _enemy.displayPotions();
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
                    _player.setGold(_player.getGold() + _enemy.getGold());
                }   

                else if (looter == 2)
                {
                    _player.setGold(_player.getGold() + _enemy.getGold());
                    equipment loot = _enemy.getActiveEquipment(1);
                    _player.setItem(loot);
                    cout << "Successfully looted" << endl;
                }

                else if (looter == 3)
                {
                    _player.setGold(_player.getGold() + _enemy.getGold());
                    _player.setPotion(_enemy.getPotion(1));
                    cout << "Successfully looted" << endl;
                }

                else if (looter == 4)
                {
                    _player.setGold(_player.getGold() + _enemy.getGold());
                    cout << "tick" << endl;
                    _player.setItem(_enemy.getActiveEquipment(1));
                    _player.setPotion(_enemy.getPotion(1));
                    cout << "Successfully looted" << endl;
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
        return _player;
    }

    Entity Combat :: statusCheck(Entity player1)
    {
        //checks the status of an entity based off the status of bool turn and applies value changes accordingly
        Entity _player = player1;
        if (turn == true)
        {
            if (_player.getCondition() == 'D')
            {
                _player.setStamina(_player.getStamina() - 5);
            }
            
            else if (_player.getCondition() == 'P')
            {
                _player.setHP(_player.getHP() - 5);
            }

            if (_player.getStamina() == 0)
            {
                _player.setStamina(_player.getStamina() + 10);
                setTurn();
            }
        }

        else if (turn == false)
        {
            if (_enemy.getCondition() == 'D')
            {
                _enemy.setStamina(_enemy.getStamina() - 5);
            }
            
            else if (_enemy.getCondition() == 'P')
            {
                _enemy.setHP(_enemy.getHP() - 5);
            }

            if (_enemy.getStamina() == 0)
            {
                _enemy.setStamina(_enemy.getStamina() + 10);
                setTurn();
            }
        }
        return _player;
    }

