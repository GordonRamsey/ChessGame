#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
using namespace std;

Piece* game_board[8][8];

void SetUp()
{
    game_board[0][0] = new Rook();
    game_board[0][0]->setColor('w');
    game_board[0][0]->setPosition(0,0);
    
    game_board[0][1] = new Knight();
    game_board[0][1]->setColor('w');
    game_board[0][1]->setPosition(1,0);

    game_board[0][2] = new Bishop();
    game_board[0][2]->setColor('w');
    game_board[0][2]->setPosition(2,0);

    game_board[0][3] = new Queen();
    game_board[0][3]->setColor('w');
    game_board[0][3]->setPosition(3,0);

    game_board[0][4] = new King();
    game_board[0][4]->setColor('w');
    game_board[0][4]->setPosition(4,0);

    game_board[0][5] = new Bishop();
    game_board[0][5]->setColor('w');
    game_board[0][5]->setPosition(5,0);

    game_board[0][6] = new Knight();
    game_board[0][6]->setColor('w');
    game_board[0][6]->setPosition(6,0);

    game_board[0][7] = new Rook();
    game_board[0][7]->setColor('w');
    game_board[0][7]->setPosition(7,0);

    for(int i = 0; i < 8; ++i)
    {
        game_board[1][i] = new Pawn();
        game_board[1][i]->setColor('w');
        game_board[1][i]->setPosition(1,i);
    }

    for(int i = 2; 2 < 6; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            game_board[i][j] = NULL;
        }
    }

    for(int i = 0; i < 8; ++i)
    {
        game_board[6][i] = new Pawn();
        game_board[6][i]->setColor('b');
        game_board[6][i]->setPosition(6,i);
    }

    game_board[7][0] = new Rook();
    game_board[7][0]->setColor('b');
    game_board[7][0]->setPosition(0,7);

    game_board[7][1] = new Knight();
    game_board[7][1]->setColor('b');
    game_board[7][1]->setPosition(1,7);

    game_board[7][2] = new Bishop();
    game_board[7][2]->setColor('b');
    game_board[7][2]->setPosition(2,7);

    game_board[7][3] = new Queen();
    game_board[7][3]->setColor('b');
    game_board[7][3]->setPosition(3,7);

    game_board[7][4] = new King();
    game_board[7][4]->setColor('b');
    game_board[7][4]->setPosition(4,7);

    game_board[7][5] = new Bishop();
    game_board[7][5]->setColor('b');
    game_board[7][5]->setPosition(5,7);

    game_board[7][6] = new Knight();
    game_board[7][6]->setColor('b');
    game_board[7][6]->setPosition(6,7);

    game_board[7][7] = new Rook();
    game_board[7][7]->setColor('b');
    game_board[7][7]->setPosition(7,7);
}

void Move(int cur_x, int cur_y, int new_x, int new_y)
{
    if(cur_x < 0 || cur_x > 7 || cur_y < 0 || cur_y > 7 || new_x < 0 || new_x > 7 || new_y < 0 || new_y > 7)
    {
        cout << "Invalid Coordinates" << endl;
        return;
    }
    Piece* moving_piece = board[cur_x][cur_y];
    if(moving_piece != NULL)
    {
        Piece* defending_piece = board[new_x][new_y];



int main()
{return 0;}