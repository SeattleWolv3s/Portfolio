#include "board.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctype.h>
#define RED "\033[41m"     
#define GREEN "\033[42m"   
#define BLUE "\033[44m"    
#define MAGENTA "\033[45m" 
#define CYAN "\033[46m"    
#define RESET "\033[0m"
using namespace std;

Board :: Board()
{
    srand(time(NULL));
    //randomly decides tile type for every tile on each players board
    for (int i = 1; i < 51; i++)
    {
        int determinant = rand() % 10 + 1;
        player1_board[i].board_location = i;
        if (determinant >= 1 && determinant <= 5)
        {
            player1_board[i].tile_color = "Blue";
            player1_board[i].tile_type = "Water";
        }

        else if (determinant > 5 && determinant < 8)
        {
            player1_board[i].tile_color = "Green";
            player1_board[i].tile_type = "Island";
        }

        else if (determinant >= 8 && determinant <= 10)
        {
            player1_board[i].tile_color = "Red";
            player1_board[i].tile_type = "Special";
        }
    }
    
    for (int i = 1; i < 51; i++)
    {
        int determinant = rand() % 10 + 1;
        player2_board[i].board_location = i;
        if (determinant >= 1 && determinant <= 5)
        {
            player2_board[i].tile_color = "Blue";
            player2_board[i].tile_type = "Water";
        }

        else if (determinant > 5 && determinant < 9)
        {
            player2_board[i].tile_color = "Green";
            player2_board[i].tile_type = "Island";
        }

        else if (determinant == 9 || determinant == 10)
        {
            player2_board[i].tile_color = "Red";
            player2_board[i].tile_type = "Special";
        }
    }
    return;
}

//prints both maps and uses the included colors to show each tile type
void Board :: mapDisplay()
{
    cout << "Player 1's Map: " << endl;
    for (int i = 0; i < 50; i++)
    {
        if (player1_board[i].tile_color == "Red")
        {
            cout << RED << "1";
            cout << RESET;
        }

        else if (player1_board[i].tile_color == "Green")
        {
            cout << GREEN << "1";
            cout << RESET;
        }

        else if (player1_board[i].tile_color == "Blue")
        {
            cout << BLUE << "1"; 
            cout << RESET;
        }
    }

    cout << RESET << endl << endl;

    cout << "Player 2's Map: " << endl;
    for (int i = 0; i < 50; i++)
    {
        if (player2_board[i].tile_color == "Red")
        {
            cout << RED << "2";
            cout << RESET;
        }

        else if (player2_board[i].tile_color == "Green")
        {
            cout << GREEN << "2";
            cout << RESET;
        }
        
        else if (player2_board[i].tile_color == "Blue")
        {
            cout << BLUE << "2"; 
            cout << RESET;
        }
    }
    cout << RESET << endl;
    return;
}

//returns the entire tile 
const tile Board :: player1TileInfo(int index)
{
    return player1_board[index];
}

const tile Board :: player2TileInfo(int index)
{
    return player2_board[index];
}