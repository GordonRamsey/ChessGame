#include "Wbishop.h"

WBishop::WBishop(int x, int y, int it) : Bishop(x, y, it)
{
	debug_name = "Wbishop";
}

WBishop::~WBishop()
{}

string WBishop::Move(coord newpost)
{
	return Bishop::Move(newpos);
	
	//Once WBishop levels up,
	//Leaves a tunnel after they move.
	//I assume that decays over time.
}

vector<coord> WBishop:: validSpots(Chess* c)
{
	return Bishop::validSpots(c);
}
