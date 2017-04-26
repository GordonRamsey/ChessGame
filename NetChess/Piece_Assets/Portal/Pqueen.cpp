#include "Pqueen.h"
using namespace std;

PQueen::PQueen(int x, int y, int it) : Queen(x, y, it)
{
    debug_name = "Pqueen";
    clicks = 0;
}

PQueen::~PQueen()
{}

string PQueen::Move(coord newpos)
{
    return Queen::Move(newpos);
}

vector<coord> PQueen::validSpots(Chess* c)
{
  return Queen::validSpots(c);
}

string PQueen::processClicks(vector<coord> clickedOn, Chess* c)
{
  return "DEFAULT";
}

