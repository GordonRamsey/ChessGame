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
    if(clickedOn.size() != 1)
        return "ERROR"; 

    if(clickedOn[0] == getPos())
    {
        if(c->board[clickedOn[1].x][clickedOn[1].y]->getTeam() == getTeam())
        {
            if(c->board[clickedOn[2].x][clickedOn[2].y]->getTeam() == getTeam())
            {
                ss.str(""); 
                ss << "MOVE " << getNum() << " " << getPos().x << getPos().y << " ~"; 
                ss << "REMV " << c->board[clickedOn[1].x][clickedOn[1].y]->getNum()<< " ~"; 
                ss << "LVUP " << c->board[clickedOn[2].x][clickedOn[2].y]->getNum()<< " ~"; 
                return ss.str(); 
            }
            else 
                return "DEFAULT"; 
        }
        return "DEFAULT"; 

    }

  return "DEFAULT";
}

