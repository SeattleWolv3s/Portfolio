#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
using namespace std;
struct potion
{
    //Potions have standard information as well as inventory counters and custom descriptions.
    string name;
    char type;
    double value;
    int price;
    char element;
    string description;
    int held;
};

struct equipment
{
    //Equipment has standard values with some broken into two, as well as custom descriptions.
    string name;
    char type;
    string description;
    int price;
    char element;
    double value; 
    double alt_value;
    string owner;
};

//damage is split into a struct to make calculations during combat cleaner and simpler
struct damage
{
    double total_damage;
    double fire_damage;
    double water_damage;
    double earth_damage;
    double air_damage;
};

class Entity
{
    public:
    //Constructors
    Entity();
    Entity(string name, double health, int stamina, int defense, bool advantage, char weakness, int gold, char condition, int damage, bool enemy);

    //single value setters
    void setUser(string name);
    void setName(string name);
    void setBoon(string name);

    void setHP(double health);
    void setStamina(double stamina);
    void setDefense(double defense);
    void setGold(double gold);

    void setNetDamage();
    void setTotalDamage(double damage);
    void setFireDamage(double damage);
    void setWaterDamage(double damage);
    void setAirDamage(double damage);
    void setEarthDamage(double damage);
    
    void setEquipmentCount();
    void setPotionCount();
    void setBackpackCount();
    void setItemTotal();

    void reducePotionsHeld(int index);

    void setLocation(int location);
    void setPlayerCount(int counter);
    void setTurnsTaken();

    void setCondition(char condition);
    void setWeakness(char weakness);

    void setIsEnemy(bool enemy);
    void setAdvantage(bool advantage);

    void setItem(equipment item);
    void setPotion(potion chug_jug);

    //single value getters
    const string getName();
    const string getUser();
    bool findBoon(string boon);

    const double getHP();
    const double getStamina();
    const double getDefense();
    const double getGold();

    const double getTotalDamage();
    const double getFireDamage();
    const double getWaterDamage();
    const double getEarthDamage();
    const double getAirDamage();

    const int getEquipmentCount();
    const int getBackpackCount();
    const int getPotionCount();
    void getItemCounts();
    const int getItemTotal();

    const equipment getActiveEquipment(int index);
    const equipment getStoredEquipment(int index);
    const potion getPotion(int index);
    const int getPotionsHeld(int index);

    bool findEquipment(string name);
    bool findPotion(string name);

    const int getLocation();
    const int getTurnsTaken();
    const int getPlayerCount();

    const char getCondition();
    const char getWeakness();

    const bool getIsEnemy();
    const bool getAdvantage();
    //

    //prints out all the items with full info from the location determined in the function name
    void displayEquipped();
    void displayBackpack();
    void displayPotions();
    //
   
    //background functions used frequently in combat or standard turns that are called on by other functions
    void equipmentFunction(equipment item);
    void equipItem();
    void usePotion();
    void usePotionEnemy();

    void removeBoon(string boon);
    void unequip(string item);
    void discard(string item);
    //

    //displays stats, basic has a set of values while the full function has a menu letting the player see all different stats grouped differently
    void printStats();
    void printBasicStats();

    bool death();

    private:
    string _user;
    string _name;
    string _boon[5];

    double _hp;
    double _stamina;
    double _defense;
    double _gold;
    
    int _potion_count;
    int _equipped_count;
    int _backpack_count;
    int _total_items[2];

    int _location;
    int _player_count;
    int _turns_taken = 0;

    char _weakness;
    char _condition;

    bool _is_enemy;
    bool _advantage;

    damage _damage;

    equipment _equipped[2];
    equipment _backpack[2];
    potion _potion_belt[3];
};
#endif