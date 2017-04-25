#include "Nking.h"
using namespace std;

NKing::NKing(int x, int y, int it) : King(x, y, it)
{
    debug_name = "Nking";
}

NKing::~NKing()
{}

string NKing::Move(coord newpos)
{
  return King::Move(newpos);
}

vector<coord> NKing::validSpots(Chess* c)
{
  return King::validSpots(c);
}

string NKing::processClicks(vector<coord> clickedOn, Chess* c)
{
  return "DEFAULT";
}
