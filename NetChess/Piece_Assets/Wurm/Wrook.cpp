#include "Wrook.h"

WRook::WRook(int x, int y, int it) : Rook(x, y, it)
{
	debug_name = "WRook";
}

WRook::~WRook()
{}

string WRook::Move(coord newpos)
{
	if(m_level)
	{
		//Place a tunnel after you move
	}
	else
		return Rook::Move(newpos);
}

vector<coord> WRook::validSpots(Chess* c)
{
	//Can move through tunnels too, don't know how
	return Rook::validSpots(c);

}
