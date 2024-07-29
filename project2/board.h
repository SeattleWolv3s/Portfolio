#ifndef BOARD_H
#define BOARD_H
#include "Entity.h"
#include <iostream>
using namespace std;

//a struct is used for every tile to store the amount of information i want while staying compressed in member functions
struct tile
{
    int board_location;
    string tile_type;
    string tile_color;
};

class Board
{
    public:
    //randomly selects every tile for the map and initializes
    Board();
    //originally planned for enemies to be stored at their tiles but later decided to initialize combat when it is encountered
    void selectEnemy(Entity All_Enemies[], const int enemy_total);
    //prints out the map tiles for each player
    void mapDisplay();
    //getter functions for tiles for the event generator in game.cpp
    const tile player1TileInfo(int index);
    const tile player2TileInfo(int index);

    private:
    tile player1_board[50];
    tile player2_board[50];
};
#endif