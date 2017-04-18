#include "Fking.h"

FKing::FKing(int x, int y, int it) : King(x, y, it)
{
  debug_name = "Fking";
}

FKing::~FKing()
{}

string FKing::Move(coord newpos)
{
    return King::Moves(newpos); //Calls the Kings Move(coord newpos) function
}

vector<coord> FKing::validSpots(Chess* c)
{
    return King::validSpots(c); //Calls the Kings validSpots(Chess* c) function
}

//Add Virtual Function

//Add function for leveling up allies
void FKing::Morale(Chess* c)
{
    if(m_level)
    {
        for(int i = 0; i < 14; ++i)
        {
            for(int j = 0; j < 14; ++j)
            {
                if(c->validSpots[i][j] != 0 && c->board[i][j] != NULL) //Checks if it's not a corner and Checks for a piece
                {
                    if(c->board[i][j]->getTeam() == getTeam()) //Checks if piece is our team
                        c->board[i][j]->levelUp(); //Levels piece up
                }
            }
        }
    }
}
