#include "Frook.h"

FRook::FRook(int x, int y, int it) : Rook(x, y, it)
{
    debug_name = "Frook";
}

FRook::~FRook()
{}

string FRook::Move(coord newpos)
{
	stringstream ss;
	ss << "[MOVE-Rook]" << newpos.x << "," << newpos.y << endl;
	return ss.str()
}

vector<coord> FRook::validSpots(Chess* c)
{
	coord seek;
	if(!m_level)
		return Rook::validSpots(c);

	vector<coord> spots(Rook::validSpots(c));

	
}
