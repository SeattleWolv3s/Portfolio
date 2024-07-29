#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
using namespace std;

class Entity
{
    public:
    Entity();
    Entity(string name, double health, int gold, char condition, bool enemy);

    const string getName();
    const double getHP();
    const int getGold();
    const char getCondition();
    const bool getIsEnemy();

    void setName(string name);
    void setHP(double health);
    void setGold(int gold);
    void setCondition(char condition);
    void setIsEnemy(bool enemy);

    void printStats();

    private:
    string _name;
    double _hp;
    int _gold;
    char _condition;
    bool _is_enemy;
};
#endif