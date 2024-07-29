#ifndef GAME_H
#define GAME_H
#include "Entity.h"
#include "board.h"
#include "epic_combat.h"
#include "combat.h"
#include "ItemShop.h"
#include <iostream>
#define RED "\033[41m"     
#define GREEN "\033[42m"   
#define BLUE "\033[44m"    
#define MAGENTA "\033[45m" 
#define CYAN "\033[46m"    
#define RESET "\033[0m"
using namespace std;

struct riddle
{
    string riddle;
    string answer;
};

class Game
{
    public:

    //default empty constructor and one that uses all provided files to initialize other objects and fill all needed arrays
    Game();
    Game(string playerfile, string enemyfile, string bossfile, string itemfile, string potionfile, string riddlefile);
    //the main function used for the flow of the game, shows all options to be taken during a turn and extras like displaying the map and changing equipment
    void gameMenu();
    //displays the options for selecting characters, seeing stats, and visiting the shop before beginning the game
    void startMenu();
    //flips the bool to regulate player turns
    void setTurn();
    //standard item menu, very similar to those from combat or epic combat 
    void itemMenu();
    //function used to initialize a combat object and select an enemy before loading whichever player was picked into the fight, also regulates victory conditions and rewards
    Entity startCombat(Entity player1);
    //similar to the function above, initializes an epic combat and manages the turn order and rewards as two players must be handled
    void startBossFight();
    //generates an item shop and sends each player there, randomizing items in between visits
    void shopCall();
    //generates an item shop for one player to visit
    Entity soloShopCall(Entity player);
    //generates a number that determines how far the player moves, moves them that far, and then calls the event generator
    void Movement(int movement);
    //determines if and what event will occur based on what tile type the player lands on
    void eventGenerator();
    //checks for non healthy statuses and applies debuffs accordingly
    void statusCheck();
    //stores all conditions for player victory and checks if victory is true at any point
    void victoryTracker();
    //returns a bool if one of the victories is true, ending the game
    const bool Victory();
    //prints all stats to an external file
    void finalPrintOut();

    private:
    //collection of arrays storing all information from text files so they can be accessed without an ifstream call
    riddle riddles[15];
    Entity All_Players[4];
    Entity All_Enemies[7];
    Entity All_Epic_Enemies[3];
    equipment All_Items[21];
    potion All_Potions[9];
    //objects/variables used frequently and necessary to game function
    Board Game_Map;
    Entity selected_players[2];
    bool player1_turn;
    //victory bools
    bool player1_victory;
    bool player2_victory;
};
#endif