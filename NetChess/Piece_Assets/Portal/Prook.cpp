#include "Prook.h"
using namespace std;

PRook::PRook(int x, int y, int it) : Rook(x, y, it)
{
    debug_name = "Prook";
}

PRook::~PRook()
{}

string PRook::Move(coord newpos)
{
    return Rook::Move(newpos);
}

string PRook::processClicks(vector<coord> clickedOn, Chess* c)
{
  return "DEFAULT";
}

vector<coord> PRook::validSpots(Chess* c)
{
  return Rook::validSpots(c);
}

