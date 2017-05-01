#include "Wbishop.h"

WBishop::WBishop(int x, int y, int it) : Bishop(x, y, it)
{
	debug_name = "Wbishop";
}

WBishop::~WBishop()
{}

string WBishop::Move(coord newpost)
{
	if(m_level)
	{
		//Place a tunnel where you've moved
		//Does it decay over time?
	}
	else
		return Bishop::Move(newpos);
	
}

vector<coord> WBishop:: validSpots(Chess* c)
{
	if(!m_level)
		return Bishop::validSpots(c);
}
