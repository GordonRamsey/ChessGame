#include "Fbishop.h"

FBishop::FBishop(int x, int y, int it) : Bishop(x, y, it)
{
	m_level = false;
	degub_name = "fqueen"; //debug or degub??
}

FBishop::~FBishop()
{}

string FBishop::Move(coord newpos)
{
	stringstream ss;
	ss << "[MOVE-Bishop]" << newpos.x << "," << newpos.y << endl;
	return ss.str();
}

vector<coord> FBishop::validSpots(Chess* c)
{
	coord seek;
	if(!m_level)
		return Bishop::validSpots(c);

	vector<coord> spots(Bishop::validSpots(c));
}
