#ifndef CHESS_H
#define CHESS_H
#include <vector>
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
using namespace std;

void SetUp();
void Move(int cur_x, int cur_y, int new_x, int new_y);
vector<coord> ValidMoves(const int x, const int y);
   
