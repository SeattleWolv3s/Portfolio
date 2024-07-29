#include "Game.h"
#include "Entity.h"
#include "combat.h"
#include "epic_combat.h"
#include "board.h"
#include "ItemShop.h"
#include <iostream>
#include <cassert>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctype.h>
using namespace std;

void gameStart();
void gameEnd();

//starts a new game and displays the game menu that loops on its own
int main()
{
    Game test_game("a_players.txt", "a_enemies.txt", "a_epic_enemies.txt", "a_items.txt", "a_potions.txt", "a_riddles.txt");
    gameStart();
    test_game.startMenu();
    test_game.gameMenu();
    test_game.finalPrintOut();
    gameEnd();
    return 0;
}

//displays an introduction with a guide to how to play
void gameStart()
{
    cout << "Welcome to the beautiful world of the Odyssey!" << endl;
    cout << "Today I, the amazing greek god of partying and wine and everything else fun, Dionysus, will be the host for your adventure through ancient greece." << endl;
    cout << "To start this game, I will provide a brief overview of the rules and functions before allowing you to select your starting gear and carry on with your journey." << endl;
    cout << "This game will function like a board game as our two heros race across the Aegian sea to reach Ithaca, though it will not be an easy quest." << endl;
    cout << "As you direct your players, their crew will encounter natural calamities, enemies of old, hidden treasures, the boons of the gods, mythical beasts, and many more surprises." << endl;
    cout << "To begin, select your players from the menu that will be displayed below, and make sure to view your player's stats and to visit the item shop before departing." << endl;
    cout << "My last piece of advice to you is to type in the player names, but to enter number inputs prompted by my handyman, Jason of the argonauts, for the rest of adventure." << endl;
    cout << "With that, I will allow you to depart, so best wishes on your journey, and make sure to entertain the gods, lest they wreak havoc on you." << endl;
    return;
}

//conclusion lines and tells the user where to find game info
void gameEnd()
{
    cout << "With that, our journey has come to an end, whether it be from a fallen hero or a hero with the speed of hermes and the blessings of poseidon." << endl;
    cout << "I must admit that this has been far more entertaining then I ever could have hoped, so to those of you behind the keyboard, thank you." << endl;
    cout << "Though our journey has concluded, it would not be very greek of me to let such an event pass without trace, so if you'd like to revisit this trip, please open the text file titled final stats to view each players stats at the end of the game." << endl;
    cout << "With that, I plan to go drink or party or something some more, and I'm sure you have more productive things to be spending your time on, so best of luck and may nike bless the victor!" << endl;
    return;
}