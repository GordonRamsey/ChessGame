#include "Wbishop.h"

WBishop::WBishop(int x, int y, int it) : Bishop(x, y, it)
{
	debug_name = "Wbishop";
}

WBishop::~WBishop()
{}

string WBishop::Move(coord newpos)
{
  if(m_level)
  {
    stringstream ss;
    ss << "PLAC Tunnel " << newpos.x << " " << newpos.y << " -1 ~";
    ss << "PLAC Tunnel " << getSpot().x << " " << getSpot().y << " -1 ~";
    return ss.str();  
  }
  else
    return Bishop::Move(newpos);

}

vector<coord> WBishop:: validSpots(Chess* c)
{
  return Bishop::validSpots(c);
}
