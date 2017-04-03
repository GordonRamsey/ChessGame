#include "Fking.h"

FKing::FKing(int x, int y, int it) : King(x, y, it)
{
  m_level = "false";
  debug_name = "king";
}

FKing::~FKing()
{}

string FKing::Move(coord newpos)
{
    return King::Moves(newpos); //King doesn't have the function Moves
}

vector<coord> FKing::validSpots(Chess* c)
{
    return King::validSpots(c); //King has a function called ValidMoves()??
}

//Add function for leveling up allies
void FKing::MoraleBoost(Chess* c)
{
    //Go through the board and determine allied pieces using getTeam(), then change their m_level to true
	
}
