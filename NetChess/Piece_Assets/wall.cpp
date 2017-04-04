#include "wall.h"


Wall::Wall(int x, int y, int it) : Piece(x, y, it)
{
  debug_name = "wall";
  // :)
}

Wall::~Wall()
{

}

string Wall::Move(coord newpos)
{
  return "DEFAULT MOVE"
}

vector<coord> Wall::validSpots(Chess* c)
{
  return vector<coord> dummy;
}
