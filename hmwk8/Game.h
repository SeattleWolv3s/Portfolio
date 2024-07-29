#ifndef GAME_H
#define GAME_H
#include "Entity.h"
#include "Entity.cpp"
#include <iostream>
using namespace std;

class Game
{
    public:
    Game();
    Game(Entity players[], Entity enemies[], int num_players, int num_enemies);

    const int getNumPlayers();
    const int getNumEnemies();

    void setPlayersList(Entity players[], int num_players);
    void setEnemiesList(Entity enemies[], int num_enemies);

    bool setPlayer(int spot, Entity player);
    bool setEnemy(int spot, Entity enemy);

    Entity getPlayer(string player);
    Entity getEnemy(string enemy);

    const int findPlayer(string player);
    const int findEnemy(string enemy);

    void printAllStats();

    private:
    Entity _players[2];
    Entity _enemies[2];
    int _num_players;
    int _num_enemies;
};
#endif