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
    return King::Moves(newpos);
}

vector<coord> FKing::validSpots(Chess* c)
{
    return King::validSpots(c);
}

//Add function for leveling up allies
void FKing::MoraleBoost(Chess* c)
{
    //Go through the board and determine allied pieces using getTeam(), then change their m_level to true
}
