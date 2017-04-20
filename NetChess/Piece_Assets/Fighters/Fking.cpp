#include "Fking.h"

FKing::FKing(int x, int y, int it) : King(x, y, it)
{
  cerr << "Fking construct" << endl;
  debug_name = "Fking";
  cerr << "Fking: Debug name:" << debug_name << endl;
}

FKing::~FKing()
{}

string FKing::processClicks(vector<coord> clickedOn, Chess* c)
{
  if(m_level)
  {
    stringstream ss;
    if(clickedOn.size() != 1)
      return "ERROR";

    if(clickedOn[0] == getSpot())
    {
      ss.str(Morale(c));
      return ss.str();
    }
    else
      return "DEFAULT";
  }
  else
    return "DEFAULT";
}

string FKing::Move(coord newpos)
{
  return King::Move(newpos); //Calls the Kings Move(coord newpos) function
}

vector<coord> FKing::validSpots(Chess* c)
{
  return King::validSpots(c); //Calls the Kings validSpots(Chess* c) function
}

//Add function for leveling up allies
string FKing::Morale(Chess* c)
{
  stringstream ss;
 
  if(m_level)
  {
    for(int i = 0; i < 14; ++i)
    {
      for(int j = 0; j < 14; ++j)
      {
	if(c->validspots[i][j] != 0 && c->board[i][j] != NULL) //Checks if it's not a corner and Checks for a piece
	{
	  if(c->board[i][j]->getTeam() == getTeam()) //Checks if piece is our team
	    ss << "LVUP " << c->board[i][j]->getNum() << " ~";
	}
      }
    }
  }
}
