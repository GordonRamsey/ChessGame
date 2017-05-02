#include "Wrook.h"

WRook::WRook(int x, int y, int it) : Rook(x, y, it)
{
	debug_name = "Wrook";
}

WRook::~WRook()
{}

string WRook::Move(coord newpos)
{
	if(m_level)
	{
	  stringstream ss;
	  ss << "PLAC Tunnel " << newpos.x << " " << newpos.y << " -1 ~";
	  ss << "PLAC Tunnel " << getSpot().x << " " << getSpot().y << " -1 ~";
	  return ss.str();
	}
	else
	  return Rook::Move(newpos);
}

vector<coord> WRook::validSpots(Chess* c)
{

}
