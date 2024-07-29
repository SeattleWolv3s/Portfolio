#include "Game.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

    Game :: Game()
    {
        _num_players = 0;
        _num_enemies = 0;
    }

    Game :: Game(Entity players[], Entity enemies[], int num_players, int num_enemies)
    {
            if (num_players <= 2)
            {
                _num_players = num_players;
                for (int i = 0; i < num_players; i++)
                {
                _players[i] = players[i];
                }
            }
            else if (num_players > 2)
            {
                _num_players = 2;
                for (int i = 0; i < 2; i++)
                {
                _players[i] = players[i];
                }
            }
            if (num_enemies <= 2)
            {
                _num_enemies = num_enemies;
                for (int i = 0; i < num_enemies; i++)
                {
                _enemies[i] = enemies[i];
                }
            }
            else if (num_enemies > 2)
            {
                _num_enemies = 2;
                for (int i = 0; i < 2; i++)
                {
                _enemies[i] = enemies[i];
                }
            }
    }

    const int Game :: getNumPlayers()
    {
        return _num_players;
    }

    const int Game :: getNumEnemies()
    {
        return _num_enemies;
    }

    void Game :: setPlayersList(Entity players[], int num_players)
    {
        if (num_players <= 2)
        {
            _num_players = num_players;
            for (int i = 0; i < num_players; i++)
            {
                _players[i] = players[i];
            }
        }
        else if (num_players > 2)
        {
            _num_players = 2;
            for (int i = 0; i < 2; i++)
            {
                _players[i] = players[i];
            }
        }
    }

    void Game :: setEnemiesList(Entity enemies[], int num_enemies)
    {
        if (num_enemies <= 2)
        {
            _num_enemies = num_enemies;
            for (int i = 0; i < num_enemies; i++)
            {
                _enemies[i] = enemies[i];
            }
        }
        else if (num_enemies > 2)
        {
            _num_enemies = 2;
            for (int i = 0; i < 2; i++)
            {
                _enemies[i] = enemies[i];
            }
        }
    }

    bool Game :: setPlayer(int spot, Entity player)
    {
        if (spot == 0 || spot == 1)
        {
            _players[spot] = player;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Game :: setEnemy(int spot, Entity enemy)
    {
        if (spot == 0 || spot == 1)
        {
            _enemies[spot] = enemy;
            return true;
        }
        else
        {
            return false;
        }
    }

    Entity Game :: getPlayer(string player)
    {
        int tracker = -1;
        for (int i = 0; i < 2; i++)
        {
            if (_players[i].getName() == player)
            {
                tracker = i;
            }
        }
        return _players[tracker];
    }

    Entity Game :: getEnemy(string enemy)
    {
        int tracker = -1;
        for (int i = 0; i < 2; i++)
        {
            if (_enemies[i].getName() == enemy)
            {
                tracker = i;
            }
        }
        return _enemies[tracker];
    }

    const int Game :: findPlayer(string player)
    {
        int count = -1;
        for (int i = 0; i < 2; i++)
        {
            if (_players[i].getName() == player)
            {
                count = count + 1;
            }
        }
        return count;
    }

    const int Game :: findEnemy(string enemy)
    {
        int count = -1;
        for (int i = 0; i < 2; i++)
        {
            if (_enemies[i].getName() == enemy)
            {
                count = 0;
                count = count + 1;
            }
        }
        return count;
    }

    void Game :: printAllStats()
    {
        for (int i = 0; i < 2; i++)
        {
            _players[i].printStats();
            cout << endl;
            for (int i = 0; i < 46; i++)
            {
                cout << "-";
            }
            cout << endl;
        }
        for (int i = 0; i < 2; i++)
        {
            _enemies[i].printStats();
            cout << endl;
            for (int i = 0; i < 46; i++)
            {
                cout << "-";
            }
            cout << endl;
        }
    }

    