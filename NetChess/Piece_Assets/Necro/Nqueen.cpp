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
  return "DEFAULT";
}

