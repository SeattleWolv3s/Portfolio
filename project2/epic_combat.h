#ifndef EPIC_COMBAT_H
#define EPIC_COMBAT_H
#include "Entity.h"
#include "ItemShop.h"
#include <iostream>
using namespace std;

class Epic_Combat
{
    public:

    //standard constructors and a number generator for boss selection, then similar functions to standard combat, but with a version for each player that is handed a different entity by game
    Epic_Combat();
    Epic_Combat(Entity selected[], Entity epic_enemies[], const int player_count, const int boss_count);

    void bossPicker(Entity selected[], Entity epic_enemies[], const int player_count, const int boss_count);

    void setPlayerTurn();

    Entity player1CombatMenu(Entity player_a, Entity player_b);
    Entity player2CombatMenu(Entity player_b, Entity player_a);
    Entity player1VictoryMenu(Entity player_a);
    Entity player2VictoryMenu(Entity player_b);
    Entity player1ItemMenu(Entity player_a);
    Entity player2ItemMenu(Entity player_b);

    void player1Attack(Entity player_a);
    void player2Attack(Entity player_b);
    //boss attacks whichever player has higher health
    Entity enemyPlayer1Attack(Entity player_a);
    Entity enemyPlayer2Attack(Entity player_b);

    Entity player1StatusCheck(Entity player_a);
    Entity player2StatusCheck(Entity player_b);

    const double getBossHealth();
    const bool getPlayerTurn();


    private:
    //players themselves are handled by game, but passed back and forth to epic_combat, same as combat
    Entity Boss;
    bool player1_turn;
};
#endif