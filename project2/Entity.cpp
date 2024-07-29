#include "Entity.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

    //constructors
    Entity :: Entity()
    {
        _name = "";
        _hp = 0;
        _gold = 0;
        _condition = 'H';
        _is_enemy = false;
    }
    //input verification for variables handed in construction, defaults to a null value if false
    Entity :: Entity(string name, double health, int stamina, int defense, bool advantage, char weakness, int gold, char condition, int damage, bool enemy)
    {
        _name = name;

        if (health >= 0)
        {
        _hp = health;
        }
        else 
        {
            _hp = 0;
        }

        if (gold >= 0)
        {
        _gold = gold;
        }
        else 
        {
            _gold = 0;
        }

        if (condition == 'H' || condition == 'P' || condition == 'D')
        {
        _condition = condition;
        }
        else
        {
            _condition = 'H';
        }

        _is_enemy = enemy;

        if (stamina >= 0)
        {
            _stamina = stamina;
        }
        else 
        {
            _stamina = 0;
        }

        if (damage >= 0)
        {
            _damage.total_damage = damage;
        }
        else 
        {
            _damage.total_damage = 1;
        }

        if (weakness == 'W' || weakness == 'A' || weakness == 'F' || weakness == 'E')
        {
            _weakness = weakness;
        }
        else
        {
            _weakness = 'H';
        }

        _advantage = advantage;
        _equipped_count = 0;
        _potion_count = 0;
        _turns_taken = 0;
        _location = 0;
    }
    //
    
    //string single value setters with input verification
    void Entity :: setUser(string name)
    {
        if (name.length() > 2 && name != "name")
        {
            _user = name;
        }
        else 
        {
            _user = "User Error";
        }
        return;
    }

    void Entity :: setName(string name)
    {
        if (name.length() > 3 && name != "name")
        {
            _name = name;
        }
        else 
        {
            _name = "Dumb Dumb";
        }
        return;
    }

    void Entity :: setBoon(string boon)
    {
        for (int i = 0; i < 5; i++)
        {
            if (_boon[i] == " " || _boon[i] == "")
            {
                _boon[i] = boon;
                break;
            }
        }
        return;
    }
    //

    //double type single value setters with input verification defaulting to 0
    void Entity ::  setHP(double health)
    {
        if (health >= 0)
        {
            _hp = health;
        }
        else 
        {
            _hp = 0;
        }
        return;
    }

    void Entity ::  setStamina(double stamina)
    {
        if (stamina >= 0)
        {
            _stamina = stamina;
        }
        else 
        {
            _stamina = 0;
        }
        return;
    }

    void Entity ::  setDefense(double defense)
    {
        if (defense >= 0)
        {
            _defense = defense;
        }
        else 
        {
            _defense = 0;
        }
        return;
    }

    void Entity ::  setGold(double gold)
    {
        if (gold >= 0)
        {
            _gold = gold;
        }
        else 
        {
            gold = 0;
        }
        return;
    }
    //

    //damage member setters with input verification that defaults total damage to 1 and elemental components to 0.25
    void Entity :: setNetDamage()
    {
        _damage.total_damage = _damage.fire_damage + _damage.water_damage + _damage.earth_damage + _damage.air_damage + 1;
        return;
    }

    void Entity :: setTotalDamage(double damage)
    {
        if (damage < 0)
        {
            _damage.total_damage = 1;
        }
        else
        {
        _damage.total_damage = damage;
        }
        return;
    }

    void Entity :: setFireDamage(double damage)
    {
        if (damage < 0)
        {
            _damage.fire_damage = 0.25;
        }
        else
        {
        _damage.fire_damage = damage;
        }
        return;
    }

    void Entity :: setWaterDamage(double damage)
    {
        if (damage < 0)
        {
            _damage.water_damage = 0.25;
        }
        else
        {
        _damage.water_damage = damage;
        }
        return;
    }

    void Entity :: setAirDamage(double damage)
    {   
        if (damage < 0)
        {
            _damage.air_damage = 0.25;
        }
        else
        {
        _damage.air_damage = damage;
        }
        return;
    }

    void Entity :: setEarthDamage(double damage)
    {   
        if (damage < 0)
        {
            _damage.earth_damage = 0.25;
        }
        else
        {
        _damage.earth_damage = damage;
        }
        return;
    }
    //

    //inventory counters that count the number of not empty array indexes and set that number as the count
    void Entity :: setEquipmentCount()
    {
        int counter = 0;
        
        for (int i = 0; i < 2; i++)
        {
            if (_equipped[i].name != "" && _equipped[i].name != " ")
            {
                counter = counter + 1;
            }

        }
        _equipped_count = counter;
        return;
    }

    void Entity :: setBackpackCount()
    {
        int counter = 0;
        
        for (int i = 0; i < 2; i++)
        {
            if (_backpack[i].name != "" && _backpack[i].name != " ")
            {
                counter = counter + 1;
            }

        }
        _backpack_count = counter;
        return;
    }

    void Entity :: setPotionCount()
    {
        int counter = 0;
        for (int i = 0; i < 3; i++)
        {
            if (_potion_belt[i].name != " " && _potion_belt[i].name != "")
            {
                counter = counter + 1;
            }
        }
        _potion_count = counter;
        return;
    }

    void Entity ::  setItemTotal()
    {
        _total_items[1] = _equipped_count + _backpack_count;
        _total_items[0] = _potion_count;
        return;
    }

    void Entity :: reducePotionsHeld(int index)
    {
        _potion_belt[index - 1].held = _potion_belt[index - 1].held - 1;
        if (_potion_belt[index - 1].held == 0)
        {
            discard(_potion_belt[index - 1].name);
        }
        return;
    }
    //

    //broad game information counters
    void Entity :: setLocation(int location)
    {
        _location = location;
        return;
    }

    void Entity :: setPlayerCount(int counter)
    {
        _player_count = counter;
        return;
    }

    void Entity :: setTurnsTaken()
    {
        _turns_taken = _turns_taken + 1;
        return;
    }
    //

    //character type setters with input verification defaulting to normal in game values (e.g. H as default status)
    void Entity :: setCondition(char condition)
    {
        if (condition == 'H' || condition == 'P' || condition == 'D')
        {
            _condition = condition;
        }
        else 
        {
            _condition = 'H';
        }
        return;
    }

    void Entity :: setWeakness(char weakness)
    {
        if (weakness == 'W' || weakness == 'A' || weakness == 'F' || weakness == 'E')
        {
            _weakness = weakness;
        }
        else 
        {
            weakness = 'F';
        }
        return;
    }
    //

    //bool setters
    void Entity :: setIsEnemy(bool enemy)
    {
        _is_enemy = enemy;
        return;
    }

    void Entity ::  setAdvantage(bool advantage)
    {
        _advantage = advantage;
        return;
    }
    //

    //array setters count until reaching an empty index and then set the index as the given object, struct, or value, followed by a success output
    //includes options to discard items if all storage for the given type is full (e.g. offer to discard from backpack when equipping item)
    void Entity ::  setItem(equipment item)
    {
        int loop = -1;
        while (loop != 1)
        {
            for (int i = 0; i < 2; i++)
            {
                if (_equipped[i].name == " " || _equipped[i].name == "")
                {
                    _equipped[i] = item;
                    _equipped_count = _equipped_count + 1;
                    cout << item.name << " has been equipped in your open equipment slot." << endl;
                    equipmentFunction(item);
                    setEquipmentCount();
                    return;
                }
                else if (_equipped[0].name != " " && _equipped[1].name != " " && _equipped[0].name != "" && _equipped[1].name != "")
                {
                    if (_backpack[i].name == " ")
                    {
                        _backpack[i] = item;
                        _backpack_count = _backpack_count + 1;
                        setBackpackCount();
                        cout << item.name << " has been stored in your backpack" << endl;
                        return;
                    }
                }
                else if (_equipped[0].name != " " && _equipped[1].name != " " && _backpack[0].name != " " && _backpack[1].name != " " && _equipped[0].name != "" && _equipped[1].name != "" && _backpack[0].name != "" && _backpack[1].name != "")
                {
                    cout << "All storage is currently full, would you like to discard an item to make space?" << endl << "1. Yes" << "     " << "2. No" << endl;
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
                        cout << "That is not a viable option, please try again." << endl;
                        choice = 0;
                        cout << "All Storage is currently full, would you like to discard an item to make space?" << endl << "1. Yes" << "     " << "2. No" << endl;
                        cin >> choice;
                        }
                    }
                    if (choice == 1)
                    {
                        cout << "Where would you like to discard from?" << endl << "1. Equipped items" << endl << "2. Backpack" << endl;
                        int store_choice;
                        cin >> store_choice;
                        while (store_choice != 1 && store_choice != 2)
                        {
                            if (store_choice == 1 || store_choice == 2)
                            {
                                break;
                            }
                            else
                            {
                            cout << "That is not a viable option, please try again." << endl;
                            store_choice = 0;
                            cout << "Where would you like to discard from?" << endl << "1. Equipped items" << "2. Backpack" << endl;
                            cin >> store_choice;
                            }
                        }
                        if (choice == 1)
                        {
                            cout << "What item would you like to discard (1 or 2)?" << endl;
                            displayEquipped();
                            int discard_choice1;
                            cin >> discard_choice1;
                            while (discard_choice1 != 1 && discard_choice1 != 2)
                            {
                                if (discard_choice1 == 1 || discard_choice1 == 2)
                                {
                                    break;
                                }
                                else
                                {
                                cout << "That is not a viable option, please try again." << endl;
                                discard_choice1 = 0;
                                cout << "What item would you like to discard (1 or 2)?" << endl;
                                displayEquipped();
                                cin >> discard_choice1;
                                }
                            }
                            if (discard_choice1 == 1)
                            {
                                discard(_equipped[0].name);
                                setEquipmentCount();
                            }
                            else if (discard_choice1 == 2)
                            {
                                discard(_equipped[1].name);
                                setEquipmentCount();
                            }
                        }
                        else if (choice == 2)
                        {
                            cout << "What item would you like to discard (1 or 2)?" << endl;
                            displayBackpack();
                            int discard_choice2;
                            cin >> discard_choice2;
                            while (discard_choice2 != 1 && discard_choice2 != 2)
                            {
                                if (discard_choice2 == 1 || discard_choice2 == 2)
                                {
                                    break;
                                }
                                else
                                {
                                cout << "That is not a viable option, please try again." << endl;
                                discard_choice2 = 0; 
                                cout << "What item would you like to discard (1 or 2)?" << endl;
                                displayBackpack();
                                cin >> discard_choice2;
                                }
                            }
                            if (discard_choice2 == 1)
                            {
                                discard(_backpack[0].name);
                                setBackpackCount();
                            }
                            else if (discard_choice2 == 2)
                            {
                                discard(_backpack[1].name);
                                setBackpackCount();
                            }
                        }
                    }
                    else if (choice == 2)
                    {
                        cout << "Please return later if you wish to add a piece of equipment" << endl;
                        loop = 1;
                        break;
                    }
                }
            }
        }
        return;
    }
  

    void Entity ::  setPotion(potion chug_jug)
    {
        int loop = -1;
        while (loop != 1)
        {
            if (_potion_count < 3)
            {
            for (int i = 0; i < 3; i++)
            {
                if (_potion_belt[i].name == " " || _potion_belt[i].name == "")
                {
                    _potion_belt[i] = chug_jug;
                    _potion_count = _potion_count + 1;
                    cout << chug_jug.name << " successfully added to your potion belt." << endl;
                    setPotionCount();
                    loop = 1;
                    return;
                }
                else if (chug_jug.name == _potion_belt[i].name)
                {
                    //notification that the potion is already stored and its held value has instead increased 
                    _potion_belt[i].held = _potion_belt[i].held + 1;
                    cout << chug_jug.name << " successfully stored alongside its duplicates you have gathered." << endl;
                    setPotionCount();
                    loop = 1;
                    return;
                }
            }
            }
            else if (_potion_count == 3)
            {
                cout << "Your potion belt is currently full, would you like to discard a potion?" << endl << "1. Yes"  << "     " << "2. No" << endl;
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
                    cout << "That is not a viable option, please try again." << endl;
                    choice = 0;
                    cout << "Your potion belt is currently full, would you like to discard a potion?" << endl << "1. Yes" << "     " << "2. No" << endl;
                    cin >> choice;
                    }
                }
                if (choice == 1)
                {
                    cout << "Which potion would you like to discard (1, 2, or 3)?" << endl;
                    displayPotions();
                    int discarded;
                    cin >> discarded;
                    while (discarded != 1 && discarded != 2 && discarded != 3)
                    {
                        if (discarded == 1 || choice == 2)
                        {
                            break;
                        }
                        else
                        {
                        cout << "That is not a viable option, please try again." << endl;
                        discarded = 0;
                        cout << "Which potion would you like to discard (1, 2, or 3)?" << endl;
                        cin >> discarded;
                        }
                    }
                    discard(_potion_belt[discarded - 1].name);
                    setPotionCount();
                }
                else if (choice == 2)
                {
                    cout << "Please return later after consuming some potions if you wish to add more potions." << endl;
                    loop = 1;
                    break;
                }
            }
        }
        return;
    }
    //

    //string getters
    const string Entity :: getUser()
    {
        return _user;
    }

    const string Entity ::  getName()
    {
        return _name;
    }

    bool Entity :: findBoon(string boon)
    {
        bool boon_found = false;
        for (int i = 0; i < 5; i++)
        {
            if (_boon[i] == boon)
            {
                boon_found = true;
            }
        }
        return boon_found;
    }
    //

    //double getters
    const double Entity ::  getHP()
    {
        return _hp;
    }

    const double Entity ::  getStamina()
    {
        return _stamina;
    }

    const double Entity ::  getDefense()
    {
        return _defense;
    }

    const double Entity ::  getGold()
    {
        return _gold;
    }
    //

    //damage getters
    const double Entity ::  getTotalDamage()
    {
        return _damage.total_damage;
    }

    const double Entity :: getFireDamage()
    {
        return _damage.fire_damage;
    }

    const double Entity :: getWaterDamage()
    {
        return _damage.water_damage;
    }

    const double Entity :: getEarthDamage()
    {
        return _damage.earth_damage;
    }

    const double Entity :: getAirDamage()
    {
        return _damage.air_damage;
    }
    //

    //equipment count getters, cout used for functions that would return multiple values
    const int Entity :: getEquipmentCount()
    {
        return _equipped_count;
    }

    const int Entity :: getBackpackCount()
    {
        return _backpack_count;
    }

    const int Entity :: getPotionCount()
    {
        return _potion_count;
    }

    void Entity :: getItemCounts()
    {
        cout << "Number of potions held:" << _total_items[0] << endl;
        cout << "Number of items held:" << _total_items[1] << endl;
        return;
    }

    const int Entity :: getItemTotal()
    {
        return _total_items[0] + _total_items[1];
    }
    //

    //struct getters/array index getters return a full struct object from the given index 
    const equipment Entity :: getActiveEquipment(int index)
    {
        return _equipped[index - 1];
    }

    const equipment Entity :: getStoredEquipment(int index)
    {
        return _backpack[index - 1];
    }

    const potion Entity :: getPotion(int index)
    {
        return _potion_belt[index - 1];
    }

    const int Entity :: getPotionsHeld(int index)
    {
        return _potion_belt[index - 1].held;
    }

    bool Entity :: findEquipment(string name)
    {
        bool found = false;
        for (int i = 0; i < 2; i++)
        {
            if (name == _equipped[i].name || name == _backpack[i].name)
            {
                found = true;
            }
        }
        return found;
    }

    bool Entity :: findPotion(string name)
    {
        bool found = false;
        for (int i = 0; i < 3; i++)
        {
            if (name == _potion_belt[i].name)
            {
                found = true;
            }
        }
        return found;
    }
    //

    //broad game getters
    const int Entity :: getLocation()
    {
        return _location;
    }

    const int Entity :: getPlayerCount()
    {
        return _player_count;
    }

    const int Entity :: getTurnsTaken()
    {
        return _turns_taken;
    }
    //

    //character getters
    const char Entity ::  getCondition()
    {
        return _condition;
    }

    const char Entity ::  getWeakness()
    {
        return _weakness;
    }
    //

    //bool getters
    const bool Entity ::  getIsEnemy()
    {
        return _is_enemy;
    }

    const bool Entity ::  getAdvantage()
    {
        return _advantage;
    }
    //

    //equipment displays cout a breakdown of the equipment from the selected storage to keep the terminal clean and prevent misinput
    void Entity ::  displayEquipped()
    {
        cout << "Currently equipped:" << endl;;
        for (int i = 0; i < 2; i++)
        {
            if (_equipped[i].name != "" && _equipped[i].name != "")
            {
                cout << "Name: " << _equipped[i].name << endl;

                if (_equipped[i].type == 'D')
                {
                    cout << "Type: Weapon" << endl;
                }
                else if (_equipped[i].type == 'S')
                {
                    cout << "Type: Shield" << endl;
                }
                else if (_equipped[i].type == 'B')
                {
                    cout << "Type: Mythical" << endl;
                }
                else if (_equipped[i].type == 'U')
                {
                    cout << "Type: Unique" << endl;
                }

                cout << "Description: " << _equipped[i].description << endl;
                cout << "Price: " << _equipped[i].price << endl;

                if (_equipped[i].element == 'F')
                {
                    cout << "Element: Fire" << endl;
                }
                else if (_equipped[i].element == 'W')
                {
                    cout << "Element: Water" << endl;
                }
                else if (_equipped[i].element == 'A')
                {
                    cout << "Element: Air" << endl;
                }
                else if (_equipped[i].element == 'E')
                {
                    cout << "Element: Earth" << endl;
                }

                cout << "Owner: " << _equipped[i].owner << endl;

                if (getName() == _equipped[i].owner)
                {
                    cout << "Value: " << _equipped[i].alt_value << endl;
                }
                else 
                {
                    cout << "Value:" << _equipped[i].value << endl;
                }
                cout << "----------------------------------------------" << endl;
            }
        }
    }

    void Entity :: displayBackpack()
    {
        cout << "Stored in backpack:" << endl;
        for (int i = 0; i < 2; i++)
        {
            if (_backpack[i].name != "" && _backpack[i].name != " ")
            {
                cout << "Name: " << _backpack[i].name << endl;

                if (_backpack[i].type == 'D')
                {
                    cout << "Type: Weapon" << endl;
                }
                else if (_backpack[i].type == 'S')
                {
                    cout << "Type: Shield" << endl;
                }
                else if (_backpack[i].type == 'B')
                {
                    cout << "Type: Mythical" << endl;
                }
                else if (_backpack[i].type == 'U')
                {
                    cout << "Type: Unique" << endl;
                }

                cout << "Description: " << _backpack[i].description << endl;
                cout << "Price: " << _backpack[i].price << endl;

                if (_backpack[i].element == 'F')
                {
                    cout << "Element: Fire" << endl;
                }
                else if (_backpack[i].element == 'W')
                {
                    cout << "Element: Water" << endl;
                }
                else if (_backpack[i].element == 'A')
                {
                    cout << "Element: Air" << endl;
                }
                else if (_backpack[i].element == 'E')
                {
                    cout << "Element: Earth" << endl;
                }

                cout << "Owner: " << _backpack[i].owner << endl;

                if (getName() == _backpack[i].owner)
                {
                    cout << "Value: " << _backpack[i].alt_value << endl;
                }
                else 
                {
                    cout << "Value:" << _backpack[i].value << endl;
                }
                cout << "----------------------------------------------" << endl;
            }
        }
        return;
    }

    void Entity ::  displayPotions()
    {
        cout << "Current potions stored in belt:" << endl;
        for (int i = 0; i < 3; i++)
        {
            if (_potion_belt[i].name != "" && _potion_belt[i].name != " ")
            {
                cout << "Name: " << _potion_belt[i].name << endl;

                if (_potion_belt[i].type == 'H')
                {
                    cout << "Type: Healing" << endl;
                }
                else if (_potion_belt[i].type == 'S')
                {
                    cout << "Type: Stamina" << endl;
                }
                else if (_potion_belt[i].type == 'B')
                {
                    cout << "Type: Restoration" << endl;
                }
                else if (_potion_belt[i].type == 'P')
                {
                    cout << "Type: Medicine" << endl;
                }
                else if (_potion_belt[i].type == 'D')
                {
                    cout << "Type: Blessing of Ares" << endl;
                }

                cout << "Description: " << _potion_belt[i].description << endl;
                cout << "Price: " << _potion_belt[i].price << endl;
                cout << "Value:" << _potion_belt[i].value << endl;
                cout << "----------------------------------------------" << endl;
            }
        }
        return;
    }
    //

    //equipment functions for performing background tasks (e.g. adding values when an item is equipped or equipping an item)
    void Entity :: equipmentFunction(equipment item)
    {
        for (int i = 0; i < 2; i++)
        {
            if (getName() != _equipped[i].owner)
            {
                if (_equipped[i].type == 'D')
                {
                    if (_equipped[i].element == 'F')
                    {
                        setFireDamage(_damage.fire_damage + _equipped[i].value);
                    }

                    if (_equipped[i].element == 'W')
                    {
                        setWaterDamage(_damage.water_damage + _equipped[i].value);
                    }

                    if (_equipped[i].element == 'A')
                    {
                        setAirDamage(_damage.air_damage + _equipped[i].value);
                    }

                    if (_equipped[i].element == 'E')
                    {
                        setEarthDamage(_damage.earth_damage + _equipped[i].value);
                    }      
                    setNetDamage();        
                }
                else if (_equipped[i].type == 'S')
                {
                    setDefense(_defense + _equipped[i].value);
                }
                else if (_equipped[i].type == 'B')
                {
                    setDefense(_defense + _equipped[i].value);

                    if (_equipped[i].element == 'F')
                    {
                        setFireDamage(_damage.fire_damage + _equipped[i].value);
                    }

                    if (_equipped[i].element == 'W')
                    {
                        setWaterDamage(_damage.water_damage + _equipped[i].value);
                    }

                    if (_equipped[i].element == 'A')
                    {
                        setAirDamage(_damage.air_damage + _equipped[i].value);
                    }

                    if (_equipped[i].element == 'E')
                    {
                        setEarthDamage(_damage.earth_damage + _equipped[i].value);
                    } 
                    setNetDamage();
                }
                else if (_equipped[i].type == 'C')
                {
                    if (_equipped[i].owner == "Argos")
                    {
                        setBoon("Argos' Bite");
                    }
                    else if (_equipped[i].owner == "Hermes")
                    {
                        setBoon("Flight of Hermes");
                    }
                    else if (_equipped[i].owner == "Athena")
                    {
                        setBoon("Athena's Wisdom");
                    }
                    else if (_equipped[i].owner == "Uranus")
                    {
                        setBoon("Ocean's Grasp");
                    }
                }
                else if (_equipped[i].type == 'U')
                {
                    cout << "Your struggles have not gone unnoticed by the gods and they have rewarded you with a boon." << endl << "Select from the following: " << endl << "1. Gain 20 damage" << endl << "2. Gain 20 defense" << endl;
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
                            cout << "That is not an option offered by the gods, choose again or risk their wrath." << endl << "Select from the following: " << endl << "1. Gain 20 damage" << endl << "2. Gain 20 defense" << endl;
                            choice = 0;
                            cin >> choice;
                        }
                    }
                    if (choice == 1)
                    {
                        cout << "Your eyes grow sharper, as does your blade." << endl;
                        setTotalDamage(_damage.total_damage + 20);
                    }

                    else if (choice == 2)
                    {
                        cout << "Your skin grows tougher and your shield stronger." << endl;
                        setDefense(_defense + 20);
                    }
                }
            }

            else if (getName() == _equipped[i].owner)
            {
                if (_equipped[i].type == 'D')
                {
                    if (_equipped[i].element == 'F')
                    {
                        setFireDamage(_damage.fire_damage + _equipped[i].alt_value);
                    }

                    if (_equipped[i].element == 'W')
                    {
                        setWaterDamage(_damage.water_damage + _equipped[i].alt_value);
                    }

                    if (_equipped[i].element == 'A')
                    {
                        setAirDamage(_damage.air_damage + _equipped[i].alt_value);
                    }

                    if (_equipped[i].element == 'E')
                    {
                        setEarthDamage(_damage.earth_damage + _equipped[i].alt_value);
                    }    
                    setNetDamage();          
                }
                else if (_equipped[i].type == 'S')
                {
                    setDefense(_defense + _equipped[i].alt_value);
                }
                else if (_equipped[i].type == 'B')
                {
                    setDefense(_defense + _equipped[i].alt_value);

                    if (_equipped[i].element == 'F')
                    {
                        setFireDamage(_damage.fire_damage + _equipped[i].alt_value);
                    }

                    if (_equipped[i].element == 'W')
                    {
                        setWaterDamage(_damage.water_damage + _equipped[i].alt_value);
                    }

                    if (_equipped[i].element == 'A')
                    {
                        setAirDamage(_damage.air_damage + _equipped[i].alt_value);
                    }

                    if (_equipped[i].element == 'E')
                    {
                        setEarthDamage(_damage.earth_damage + _equipped[i].alt_value);
                    } 
                    setNetDamage();
                }
                else if (_equipped[i].type == 'C')
                {
                    if (_equipped[i].owner == "Argos")
                    {
                        setBoon("My Bite");
                    }
                    else if (_equipped[i].owner == "Hermes")
                    {
                        setBoon("Flight of Hermes");
                    }
                    else if (_equipped[i].owner == "Athena")
                    {
                        setBoon("Athena's Wisdom");
                    }
                    else if (_equipped[i].owner == "Uranus")
                    {
                        setBoon("Ocean's Grasp");
                    }
                }
                else if (_equipped[i].type == 'U')
                {
                    cout << "Your struggles have not gone unnoticed by the gods and they have rewarded you with a boon." << endl << "Select from the following: " << endl << "1. Gain 20 damage" << endl << "2. Gain 20 defense" << endl;
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
                            cout << "That is not an option offered by the gods, choose again or risk their wrath." << endl << "Select from the following: " << endl << "1. Gain 20 damage" << endl << "2. Gain 20 defense" << endl;
                            choice = 0;
                            cin >> choice;
                        }
                    }

                    if (choice == 1)
                    {
                        cout << "Your eyes grow sharper, as does your blade." << endl;
                        setTotalDamage(_damage.total_damage + 20);
                    }

                    else if (choice == 2)
                    {
                        cout << "Your skin grows tougher and your shield stronger." << endl;
                        setDefense(_defense + 20);
                    }
                    discard("Siren's Salve");
                    setEquipmentCount();
                    setBackpackCount();
                    setItemTotal();
                }
            } 
        }
        return;
    }

    void Entity :: equipItem()
    {
        cout << "What item would you like to equip (1 or 2)?" << endl;
        displayBackpack();
        int equipped;
        cin >> equipped;
        while (equipped != 1 && equipped != 2)
        {
            if (equipped == 1 || equipped == 2)
            {
                break;
            }
            else
            {
                cout << "Not an available option, please try again." << endl;
                equipped = 0;
                cout << "What item would you like to equip (1 or 2)?" << endl;
                displayBackpack();
                cin >> equipped;
            }
        }
        string item = _backpack[equipped - 1].name;
        int loop = -1;
        while (loop != 1)
        {
            if (_equipped_count < 2)
            {
                for (int i = 0; i < 2; i++)
                {
                    if (item == _backpack[i].name)
                    {
                        _equipped[_equipped_count - 1] = _backpack[i];
                        _equipped_count = _equipped_count + 1;
                        equipmentFunction(_backpack[i]);
                        cout << _backpack[i].name << " successfully equipped." << endl;
                        discard(_backpack[i].name);
                        setEquipmentCount();
                        setBackpackCount();
                        loop = 1;
                    }
                    else if (i == 1 && item != _backpack[i].name)
                    {
                        cout << "It appears you do not have this item stored anywhere on you or your ship, please acquire it before trying again." << endl;
                        loop = 1;
                    }
                }
            }
            else if (_equipped_count == 2)
            {
                cout << "Your equipped slots are currently full, would you like to store an item?" << endl << "1. Yes" << "     " << "2. No" << endl;
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
                    cout << "That is not a viable option, please try again." << endl;
                    choice = 0;
                    cout << "Your equipped slots are currently full, would you like to store an item?" << endl << "1. Yes" << "     " << "2. No" << endl;
                    cin >> choice;
                    }
                }
                if (choice == 1)
                {
                    cout << "Which item would you like to store (1 or 2)?" << endl;
                    displayEquipped();
                    int storage;
                    cin >> storage;
                    while (storage != 1 && storage != 2)
                    {
                        if (storage == 1 || storage == 2)
                        {
                            break;
                        }
                        else
                        {
                        cout << "That is not a viable option, please try again." << endl;
                        storage = 0;
                        cout << "Which item would you like to store?" << endl;
                        cin >> storage;
                        }
                    }
                    unequip(_equipped[storage - 1].name);
                    setEquipmentCount();
                    setBackpackCount();
                }
                else if (choice == 2)
                {
                    cout << "This leaves you unable to equip an item, please reselect this option in the main menu if you wish to change your items later." << endl;
                    loop = 1;
                    break;
                }
            }
        }
        setItemTotal();
        return;
    }

    void Entity :: usePotion()
    {
        cout << "Which potion would you like to use (select 1, 2, or 3)?" << endl;
        displayPotions();
        int choice;
        cin >> choice;
        while (choice != 1 && choice != 2 && choice != 3)
        {
            if (choice == 1 || choice == 2 || choice == 3)
            {
                break;
            }
            else 
            {
                cout << "Not an available option, please select again." << endl;
                choice = 0;
                cout << "Which potion would you like to use (select 1, 2, or 3)?" << endl;
                cin >> choice;
            }
        }

        int x = choice - 1;

        if (_potion_belt[x].type == 'H')
        {
            setHP(_hp + _potion_belt[x].value);
        }
        else if (_potion_belt[x].type == 'S')
        {   
            setStamina(_stamina + _potion_belt[x].value);
        }
        else if (_potion_belt[x].type == 'P')
        {
            cout << "You have come across a panacea, how will you use it?" << endl << "1. Restore yourself to health from disease" << endl << "2. Restore yourself to health from posion" << endl;
            int choice = 0;
            cin >> choice;
            while (choice != 1 && choice != 2)
            {
                if (choice == 1 || choice == 2)
                {
                    break;
                }
                else 
                {
                    cout << "The panacea is unable to cure something of that severity, please try treating something less lethal." << endl << "1. Restore yourself to health from disease" << endl << "2. Restore yourself to health from posion" << endl;
                    choice = 0;
                    cin >> choice;
                }
            }
            if (choice == 1)
            {
                setCondition('H');
            }
            else if (choice == 2)
            {
                setCondition('H');
            }
        }
        else if (_potion_belt[x].type == 'B')
        {
            setStamina(_stamina + _potion_belt[x].value);
            setHP(_hp + _potion_belt[x].value);
        }
        else if (_potion_belt[x].type == 'D')
        {
            setTotalDamage(_damage.total_damage + _potion_belt[x].value);
        }

        _potion_belt[x].held = _potion_belt[x].held - 1;

        if (_potion_belt[x].held == 0)
        {
            discard(_potion_belt[x].name);
            setPotionCount();
        }

        setItemTotal();
        return;
    }
    //planned to allow enemies to use potions but it created a lot of difficulties in continuing combat properly and it left less loot for the player
    void Entity :: usePotionEnemy()
    {
        int choice = 1;
        cin >> choice;

        int x = 0;

        if (_potion_belt[x].type == 'H')
        {
            setHP(_hp + _potion_belt[x].value);
        }
        else if (_potion_belt[x].type == 'S')
        {   
            setStamina(_stamina + _potion_belt[x].value);
        }
        else if (_potion_belt[x].type == 'P')
        {
            int choice = 1;
            if (choice == 1)
            {
                setCondition('H');
            }
        }
        else if (_potion_belt[x].type == 'B')
        {
            setStamina(_stamina + _potion_belt[x].value);
            setHP(_hp + _potion_belt[x].value);
        }
        else if (_potion_belt[x].type == 'D')
        {
            setTotalDamage(_damage.total_damage + _potion_belt[x].value);
        }

        _potion_belt[x].held = _potion_belt[x].held - 1;

        if (_potion_belt[x].held == 0)
        {
            discard(_potion_belt[x].name);
            setPotionCount();
        }

        setItemTotal();
        return;
    }
    //

    //removal functions set the array index to all null values
    void Entity :: removeBoon(string boon)
    {
        for (int i = 0; i < 5; i++)
        {
            if (_boon[i] == boon)
            {
                _boon[i] = " ";
            }
        }
    }

    void Entity :: unequip(string item)
    {
        int loop = -1;
        while (loop != 1)
        {
            if (_backpack_count < 2)
            {
                for (int i = 0; i < 2; i++)
                {
                    if (item == _equipped[i].name)
                    {
                        if (getName() != _equipped[i].owner)
                        {
                            if (_equipped[i].type == 'D')
                            {
                                if (_equipped[i].element == 'F')
                                {
                                    setFireDamage(_damage.fire_damage - _equipped[i].value);
                                }

                                if (_equipped[i].element == 'W')
                                {
                                    setWaterDamage(_damage.water_damage - _equipped[i].value);
                                }

                                if (_equipped[i].element == 'A')
                                {
                                    setAirDamage(_damage.air_damage - _equipped[i].value);
                                }

                                if (_equipped[i].element == 'E')
                                {
                                    setEarthDamage(_damage.earth_damage - _equipped[i].value);
                                }  
                                setNetDamage();
                                _backpack[_backpack_count - 1] = _equipped[i];
                                _backpack_count = _backpack_count + 1;
                                discard(_equipped[i].name);   
                                setEquipmentCount();
                                setBackpackCount();
                                loop = 1;     
                            }
                            else if (_equipped[i].type == 'S')
                            {
                                setDefense(_defense - _equipped[i].value);
                                _backpack[_backpack_count - 1] = _equipped[i];
                                _backpack_count = _backpack_count + 1;
                                discard(_equipped[i].name);
                                setEquipmentCount();
                                setBackpackCount();
                                loop = 1;
                            }
                            else if (_equipped[i].type == 'B')
                            {
                                setDefense(_defense - _equipped[i].value);

                                if (_equipped[i].element == 'F')
                                {
                                    setFireDamage(_damage.fire_damage - _equipped[i].value);
                                }

                                if (_equipped[i].element == 'W')
                                {
                                    setWaterDamage(_damage.water_damage - _equipped[i].value);
                                }

                                if (_equipped[i].element == 'A')
                                {
                                    setAirDamage(_damage.air_damage - _equipped[i].value);
                                }

                                if (_equipped[i].element == 'E')
                                {
                                    setEarthDamage(_damage.earth_damage - _equipped[i].value);
                                } 
                                setNetDamage();
                                _backpack[_backpack_count - 1] = _equipped[i];
                                _backpack_count = _backpack_count + 1;
                                discard(_equipped[i].name);
                                setEquipmentCount();
                                setBackpackCount();
                                loop = 1;
                            }
                            else if (_equipped[i].type == 'C')
                            {
                                if (_equipped[i].owner == "Argos")
                                {
                                    removeBoon("Argos' Bite");
                                }
                                else if (_equipped[i].owner == "Hermes")
                                {
                                    removeBoon("Flight of Hermes");
                                }
                                else if (_equipped[i].owner == "Athena")
                                {
                                    removeBoon("Athena's Wisdom");
                                }
                                else if (_equipped[i].owner == "Uranus")
                                {
                                    removeBoon("Ocean's Grasp");
                                }
                                _backpack[_backpack_count - 1] = _equipped[i];
                                _backpack_count = _backpack_count + 1;
                                discard(_equipped[i].name);
                                setEquipmentCount();
                                setBackpackCount();
                            }
                            else if (_equipped[i].type == 'U')
                            {
                                discard(_equipped[i].name);
                                setEquipmentCount();
                                setBackpackCount();
                            }
                        }

                        else if (getName() == _equipped[i].owner)
                        {
                            if (_equipped[i].type == 'D')
                            {
                                if (_equipped[i].element == 'F')
                                {
                                    setFireDamage(_damage.fire_damage - _equipped[i].alt_value);
                                }

                                if (_equipped[i].element == 'W')
                                {
                                    setWaterDamage(_damage.water_damage - _equipped[i].alt_value);
                                }

                                if (_equipped[i].element == 'A')
                                {
                                    setAirDamage(_damage.air_damage - _equipped[i].alt_value);
                                }

                                if (_equipped[i].element == 'E')
                                {
                                    setEarthDamage(_damage.earth_damage - _equipped[i].alt_value);
                                }  
                                setNetDamage();
                                _backpack[_backpack_count - 1] = _equipped[i];
                                _backpack_count = _backpack_count + 1;
                                discard(_equipped[i].name);   
                                setEquipmentCount();
                                setBackpackCount(); 
                                loop = 1;       
                            }
                            else if (_equipped[i].type == 'S')
                            {
                                setDefense(_defense - _equipped[i].alt_value);
                                _backpack[_backpack_count - 1] = _equipped[i];
                                _backpack_count = _backpack_count + 1;
                                discard(_equipped[i].name);
                                setEquipmentCount();
                                setBackpackCount();
                                loop = 1;
                            }
                            else if (_equipped[i].type == 'B')
                            {
                                setDefense(_defense - _equipped[i].alt_value);

                                if (_equipped[i].element == 'F')
                                {
                                    setFireDamage(_damage.fire_damage - _equipped[i].alt_value);
                                }

                                if (_equipped[i].element == 'W')
                                {
                                    setWaterDamage(_damage.water_damage - _equipped[i].alt_value);
                                }

                                if (_equipped[i].element == 'A')
                                {
                                    setAirDamage(_damage.air_damage - _equipped[i].alt_value);
                                }

                                if (_equipped[i].element == 'E')
                                {
                                    setEarthDamage(_damage.earth_damage - _equipped[i].alt_value);
                                } 
                                setNetDamage();
                                _backpack[_backpack_count - 1] = _equipped[i];
                                _backpack_count = _backpack_count + 1;
                                discard(_equipped[i].name);
                                setEquipmentCount();
                                setBackpackCount();
                                loop = 1;
                            }
                            else if (_equipped[i].type == 'C')
                            {
                                if (_equipped[i].owner == "Argos")
                                {
                                    removeBoon("My Bite");
                                }
                                else if (_equipped[i].owner == "Hermes")
                                {
                                    removeBoon("Flight of Hermes");
                                }
                                else if (_equipped[i].owner == "Athena")
                                {
                                    removeBoon("Athena's Wisdom");
                                }
                                else if (_equipped[i].owner == "Uranus")
                                {
                                    removeBoon("Ocean's Grasp");
                                }
                                _backpack[_backpack_count - 1] = _equipped[i];
                                _backpack_count = _backpack_count + 1;
                                discard(_equipped[i].name);
                                setEquipmentCount();
                                setBackpackCount();
                                loop = 1;
                            }
                            else if (_equipped[i].type == 'U')
                            {
                                discard(_equipped[i].name);
                                setEquipmentCount();
                                setBackpackCount();
                                loop = 1;
                            }
                        }
                        setItemTotal(); 
                    }
                    else if (i == 1 && item != _equipped[i].name)
                    {
                        cout << "It appears you do not currently have this item equipped." << endl;
                        loop = 1;
                    }
                }
            }
            else if (_backpack_count == 2)
            {
                cout << "Your backpack is currently full, would you like to discard an item to make space?" << endl << "1. Yes" << "     " << "2. No" << endl;
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
                        cout << "That is not an available option, please try again." << endl;
                        choice = 0;
                        cout << "Your backpack is currently full, would you like to discard an item to make space?" << endl << "1. Yes" << "     " << "2. No" << endl;
                        cin >> choice;
                    }
                }
                if (choice == 1)
                {
                    cout << "What item would you like to discard (1 or 2)?" << endl;
                    displayBackpack();
                    int discard_decision;
                    cin >> discard_decision;
                    while (discard_decision != 1 && discard_decision != 2)
                    {
                        if (discard_decision == 1 || discard_decision == 2)
                        {
                            break;
                        }
                        else 
                        {
                            cout << "Not an available option, please try again." << endl;
                            discard_decision = 0;
                            cout << "What item would you like to discard?" << endl;
                            displayBackpack();
                            cin >> discard_decision;
                        }
                    }
                    if (discard_decision == 1)
                    {
                        discard(_backpack[0].name);
                    }
                    else if (discard_decision == 2)
                    {
                        discard(_backpack[1].name);
                    }
                }
                else if (choice == 2)
                {
                    cout << "Please return to this menu later if you want to unequip an item." << endl;
                    loop = 1;
                    break;
                }
            }
            setItemTotal();
        }
    }

    void Entity :: discard(string item)
    {
        for (int i = 0; i < 2; i++)
        {
            if (_equipped[i].name == item )
            {   
                _equipped[i].name = " ";
                _equipped[i].description = " ";
                _equipped[i].element = ' ';
                _equipped[i].owner = " ";
                _equipped[i].value = 0;
                _equipped[i].alt_value = 0;
                _equipped[i].type = ' ';
                _equipped[i].price = 0;
                setEquipmentCount();
                setItemTotal();
                return;
            }
            else if (_backpack[i].name == item)
            {
                _backpack[i].name = " ";
                _backpack[i].description = " ";
                _backpack[i].owner = " ";
                _backpack[i].type = ' ';
                _backpack[i].element = ' ';
                _backpack[i].value = 0;
                _backpack[i].alt_value = 0;
                _backpack[i].price = 0;
                _backpack_count = _backpack_count - 1;
                setBackpackCount();
                setItemTotal();
                return;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (_potion_belt[i].name == item)
            {
                _potion_belt[i].name = " ";
                _potion_belt[i].description = " ";
                _potion_belt[i].type = ' ';
                _potion_belt[i].element = ' ';
                _potion_belt[i].value = 0;
                _potion_belt[i].price = 0;
                setPotionCount();
                setItemTotal();
                displayPotions();
                return;
            }
        }
    }
    //

    //full stat print menu
    void Entity :: printStats()
    {
        int choice = 1;
        string menu_choice;

        string menu0 = "Select from the following options:"; 
        string menu1 = "1. Display basic stats";
        string menu2 = "2. Display equipped items and active boons";
        string menu3 = "3. Display items in backpack";
        string menu4 = "4. Stored potions";
        string menu5 = "5. Game data";
        string menu6 = "6. Exit";

        do 
        {

            int menu = 0;
            int test = 0;

            do 
            {

                cout << endl << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl;
                cin >> menu_choice;

                while (menu_choice.length() == 0 || menu_choice.length() > 1) 
                {
                    cout << "Invalid input. Please enter a valid choice (1-6)" << endl;
                    cout << endl << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl;
                    cin >> menu_choice;
                }

                while (!isdigit(menu_choice[0])) 
                {
                    cout << "Invalid input. Please enter a valid choice (1-6)" << endl;
                    cout << endl << menu0 << endl << menu1 << endl << menu2 << endl << menu3 << endl << menu4 << endl << menu5 << endl << menu6 << endl;
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
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << getName() << endl;
                    cout << fixed << setprecision(2) << "Health: "  << getHP() << endl;
                    cout << fixed << setprecision(2) << "Stamina: " << getStamina() << endl;
                    cout << fixed << setprecision(2) << "Defense: " << getDefense() << endl;
                    cout << fixed << setprecision(2) << "Gold: " << getGold() << endl;
                    cout << fixed << setprecision(2) << "Total Damage: " << getTotalDamage() << endl;

                    if (getWeakness() == 'F')
                    {
                        cout << "Weakness: Fire" << endl;
                    }
                    else if (getWeakness() == 'W')
                    {
                        cout << "Weakness: Water" << endl;
                    }
                    else if (getWeakness() == 'A')
                    {
                        cout << "Weakness: Air" << endl;
                    }
                    else if (getWeakness() == 'E')
                    {
                        cout << "Weakness: Earth" << endl;
                    }

                    if (getCondition() == 'H')
                    {
                        cout << "Condition: Healthy" << endl;
                    }
                    else if (getCondition() == 'D')
                    {
                        cout << "Condition: Diseased" << endl;
                    }
                    else if (getCondition() == 'P')
                    {
                        cout << "Condition: Poisoned" << endl;
                    }

                    if (getIsEnemy() == true)
                    {
                        cout << "This is an enemy." << endl;
                    }
                    else
                    {
                        cout << "This is not an enemy." << endl;
                    }

                    if (getAdvantage() == true)
                    {
                        cout << "This character currently has advantage." << endl;
                    }
                    else
                    {
                        cout << "This character does not have advantage." << endl;
                    }
                }

                else if (menu == 2) 
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Equipment count: " << _equipped_count << endl;
                    cout << "Currently equipped items:" << endl;
                    for (int i = 0; i < 2; i++)
                    {
                        if (_equipped[i].name != "" && _equipped[i].name != " ")
                        {
                            cout << "Name: " << _equipped[i].name << endl;

                            if (_equipped[i].type == 'D')
                            {
                                cout << "Type: Weapon" << endl;
                            }
                            else if (_equipped[i].type == 'S')
                            {
                                cout << "Type: Shield" << endl;
                            }
                            else if (_equipped[i].type == 'B')
                            {
                                cout << "Type: Mythical" << endl;
                            }
                            else if (_equipped[i].type == 'U')
                            {
                                cout << "Type: Unique" << endl;
                            }

                            cout << "Description: " << _equipped[i].description << endl;
                            cout << "Price: " << _equipped[i].price << endl;

                            if (_equipped[i].element == 'F')
                            {
                                cout << "Element: Fire" << endl;
                            }
                            else if (_equipped[i].element == 'W')
                            {
                                cout << "Element: Water" << endl;
                            }
                            else if (_equipped[i].element == 'A')
                            {
                                cout << "Element: Air" << endl;
                            }
                            else if (_equipped[i].element == 'E')
                            {
                                cout << "Element: Earth" << endl;
                            }

                            cout << "Owner: " << _equipped[i].owner << endl;

                            if (getName() == _equipped[i].owner)
                            {
                                cout << "Value: " << _equipped[i].alt_value << endl;
                            }
                            else 
                            {
                                cout << "Value:" << _equipped[i].value << endl;
                            }
                            cout << endl << "----------------------------------------------" << endl;
                        }
                    }
                    cout << endl << "Current boons:" << endl;
                    for (int i = 0; i < 5; i++)
                    {
                        if (_boon[i] != " " && _boon[i] != "")
                        {
                            cout << endl;
                            cout << _boon[i] << endl;
                        }
                    }
                    cout << endl << "----------------------------------------------" << endl;
                }

                else if (menu == 3) 
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Backpack count: " << _backpack_count << endl;
                    cout << "Currently stored items:" << endl;
                    for (int i = 0; i < 2; i++)
                    {
                        if (_backpack[i].name != "" && _backpack[i].name != " ")
                        {
                            cout << endl;
                            cout << "Name: " << _backpack[i].name << endl;

                            if (_backpack[i].type == 'D')
                            {
                                cout << "Type: Weapon" << endl;
                            }
                            else if (_backpack[i].type == 'S')
                            {
                                cout << "Type: Shield" << endl;
                            }
                            else if (_backpack[i].type == 'B')
                            {
                                cout << "Type: Mythical" << endl;
                            }
                            else if (_backpack[i].type == 'U')
                            {
                                cout << "Type: Unique" << endl;
                            }

                            cout << "Description: " << _backpack[i].description << endl;
                            cout << "Price: " << _backpack[i].price << endl;

                            if (_backpack[i].element == 'F')
                            {
                                cout << "Element: Fire" << endl;
                            }
                            else if (_backpack[i].element == 'W')
                            {
                                cout << "Element: Water" << endl;
                            }
                            else if (_backpack[i].element == 'A')
                            {
                                cout << "Element: Air" << endl;
                            }
                            else if (_backpack[i].element == 'E')
                            {
                                cout << "Element: Earth" << endl;
                            }

                            cout << "Owner: " << _backpack[i].owner << endl;

                            if (getName() == _backpack[i].owner)
                            {
                                cout << "Value: " << _backpack[i].alt_value << endl;
                            }
                            else 
                            {
                                cout << "Value:" << _backpack[i].value << endl;
                            }
                            cout << endl << "----------------------------------------------" << endl;
                        }
                    }
                }

                else if (menu == 4) 
                {
                    cout << endl << "----------------------------------------------" << endl;
                    cout << endl;
                    cout << "Currently held potions:" << endl;
                    for (int i = 0; i < 2; i++)
                    {
                        if (_potion_belt[i].name != "" && _potion_belt[i].name != " ")
                        {
                            cout << endl;
                            cout << "Name: " << _potion_belt[i].name << endl;

                            if (_potion_belt[i].type == 'H')
                            {
                                cout << "Type: Healing" << endl;
                            }
                            else if (_potion_belt[i].type == 'S')
                            {
                                cout << "Type: Stamina" << endl;
                            }
                            else if (_potion_belt[i].type == 'B')
                            {
                                cout << "Type: Restoration" << endl;
                            }
                            else if (_potion_belt[i].type == 'P')
                            {
                                cout << "Type: Medicine" << endl;
                            }
                            else if (_potion_belt[i].type == 'D')
                            {
                                cout << "Type: Blessing of Ares" << endl;
                            }

                            cout << "Description: " << _potion_belt[i].description << endl;
                            cout << "Price: " << _potion_belt[i].price << endl;
                            cout << "Value:" << _potion_belt[i].value << endl;
                            cout << endl << "----------------------------------------------" << endl;
                        }
                    }
                }

                else if (menu == 5) 
                {
                    cout << endl;
                    cout << "User: " << getUser() << endl;
                    cout << "Location: " << getLocation() << endl;
                    cout << "Turns Taken: " << getTurnsTaken() << endl;
                    cout << endl << "----------------------------------------------" << endl;
                }

                else if (menu == 6) 
                {
                    cout << endl << "Enjoy your voyage! I certainly am." << endl << endl << "----------------------------------------------" << endl;
                    break;
                }

        } while (choice < 7 && choice > 0);
        return;
    }
    //
    //miscallaneous functions 
    //checks whether or not the entity is alive, used to end the game/combat
    bool Entity :: death()
    {
        if (_hp <= 0)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    //convenient stat block more often used for enemies than anything else
    void Entity :: printBasicStats()
    {
        cout << "Name: " << getName() << endl;
        cout << "Health: " << getHP() << endl;
        cout << "Stamina: " << getStamina() << endl;
        cout << "Defense: " << getDefense() << endl;
        cout << "Damage: " << getTotalDamage() << endl;
        cout << "Condition: " << getCondition() << endl;

        if (getWeakness() == 'F')
        {
        cout << "Elemental Weakness: Fire" << endl;
        }

        if (getWeakness() == 'W')
        {
        cout << "Elemental Weakness: Water" << endl;
        }

        if (getWeakness() == 'E')
        {
        cout << "Elemental Weakness: Earth" << endl;
        }

        if (getWeakness() == 'A')
        {
        cout << "Elemental Weakness: Air" << endl;
        }


        cout << "Gold: " << getGold() << endl;
        cout << "Starting potion: " << getPotion(1).name << endl;
        cout << "Starting item: " << getActiveEquipment(1).name << endl;
    }


 