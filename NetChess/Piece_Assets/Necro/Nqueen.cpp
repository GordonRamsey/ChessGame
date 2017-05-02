#include "Nqueen.h"
using namespace std;

NQueen::NQueen(int x, int y, int it) : Queen(x, y, it)
{
  debug_name = "Nqueen";
}

NQueen::~NQueen()
{}

string NQueen::Move(coord newpos)
{
  return Queen::Move(newpos);
}

vector<coord> NQueen::validSpots(Chess* c)
{
  return Queen::validSpots(c);
}

string NQueen::processClicks(vector<coord> clickedOn, Chess* c)
{
    stringstream ss; 
    if(clickedOn.size() != 2)
      return "ERROR"; 

    if(c->board[clickedOn[0].x/64][clickedOn[0].y/64] == NULL)
      return "ERROR";
    
    if(c->board[clickedOn[1].x/64][clickedOn[1].y/64] == NULL)
      return "ERROR";

    if(c->board[clickedOn[0].x/64][clickedOn[0].y/64]->getTeam() == getTeam())
    {
      if(c->board[clickedOn[1].x/64][clickedOn[1].y/64]->getTeam() == getTeam())
      {
	ss.str(""); 
	ss << "MOVE " << getNum() << " " << getPos().x << " " << getPos().y << " ~"; 
	ss << "REMV " << c->board[clickedOn[0].x/64][clickedOn[0].y/64]->getNum()<< " ~"; 
	ss << "LVUP " << c->board[clickedOn[1].x/64][clickedOn[1].y/64]->getNum()<< " ~"; 
	return ss.str(); 
      }
      else 
	return "ERROR"; 
    }
    return "ERROR"; 

}

