#include "Entity.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

     Entity :: Entity()
    {
        _name = "";
        _hp = 0;
        _gold = 0;
        _condition = 'H';
        _is_enemy = false;
    }

     Entity :: Entity(string name, double health, int gold, char condition, bool enemy)
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
    }

    const string Entity ::  getName()
    {
        return _name;
    }

    const double Entity ::  getHP()
    {
        return _hp;
    }

    const int Entity ::  getGold()
    {
        return _gold;
    }

    const char Entity ::  getCondition()
    {
        return _condition;
    }

    const bool Entity ::  getIsEnemy()
    {
        return _is_enemy;
    }

    void Entity ::  setName(string name)
    {
        _name = name;
    }   

    void Entity ::  setHP(double health)
    {
        if (health >= 0)
        {
        _hp = health;
        }
        else 
        {
            _hp = 0.00;
        }
    }

    void Entity ::  setGold(int gold)
    {
        if (gold >= 0)
        {
        _gold = gold;
        }
        else 
        {
            _gold = 0;
        }
    }

    void Entity ::  setCondition(char condition)
    {
        if (condition == 'H' || condition == 'P' || condition == 'D')
        {
        _condition = condition;
        }
        else 
        {
            _condition = 'H';
        }
    }

    void Entity ::  setIsEnemy(bool enemy)
    {
        _is_enemy = enemy;
    }

    void Entity :: printStats()
    {
        cout << getName() << "'s stats:" << endl;
        cout << fixed << setprecision(2) << "HP: " << getHP() << endl;
        cout << "Condition: " << getCondition() << endl;
        cout << fixed << setprecision(2) << "Gold: " << getGold() << endl;
        if (getIsEnemy() == false)
        {
            cout << "Is Enemy: No" << endl;
        }
        else 
        {
            cout << "Is Enemy: Yes" << endl;
        }
    }