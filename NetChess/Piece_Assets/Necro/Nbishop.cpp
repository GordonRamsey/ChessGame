#include "Nbishop.h"
using namespace std;

NBishop::NBishop(int x, int y, int it) : Bishop(x, y, it)
{
    debug_name = "Nbishop";
}

NBishop::~NBishop()
{}

string NBishop::Move(coord newpos)
{
  return Bishop::Move(newpos);
}

string NBishop::processClicks(vector<coord> clickedOn, Chess* c)
{
    stringstream ss; 
    if(clickedOn.size() != 1)
        return "ERROR"; 
    
    if(clickedOn[0] == getPos())
    {
        if(c->board[clickedOn[1].x][clickedOn[1].y]->getTeam() == getTeam())
        {
            ss.str(""); 
            int tmp = c->board[clickedOn[1].x][clickedOn[1].y]->getNum(); 
            ss << "REMV " << tmp << " ~"; 
            //How do we determine which piece they want? 
            ss << "PLAC " << tmp << " ~"; 
            return ss.str(); 
        }
        return "DEFAULT"; 

    }
    return "DEFAULT";
}

vector<coord> NBishop::validSpots(Chess* c)
{
  return Bishop::validSpots(c);
}

