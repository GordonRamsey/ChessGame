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
  return "DEFAULT";
}

vector<coord> NBishop::validSpots(Chess* c)
{
  return Bishop::validSpots(c);
}

