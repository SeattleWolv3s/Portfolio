#ifndef COMBAT_H
#define COMBAT_H
#include "Entity.h"
#include <iostream>
using namespace std;

class Combat
{
    public:
    Combat();
    //both initalize a fight but the lower constructor also determines initiative and uses the enemy selector to randomly select an enemy from the array
    Combat(Entity all_enemies[], const int enemy_size);

    //rolls a random number to pull the enemy from that index of the array
    void EnemySelector(Entity all_enemies[], const int enemy_size);

    //displays the options for the players turn and calls each other function based on user input, then calls enemy attack and resets turn
    Entity combatMenu(Entity player1);
    void playerAttack(Entity player1);
    Entity enemyAttack(Entity player1);
    Entity itemMenu(Entity player1);
    //flips bool
    void setTurn();
    //rolls a random number and adds a boon, success is determined when the number is returned to the combat menu
    const int flee();
    //applies buffs or debuffs by checking the player's status
    Entity statusCheck(Entity player1);
    //shows options for looting and switching items, item shop is shown separately after in the game class
    Entity victoryMenu(Entity player1);

    private:
    Entity _enemy;
    bool turn;
};
#endif