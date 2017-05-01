#include "Wqueen.h"

WQueen::WQueen(int x, int y, int it) : Queen(x, y, it)
{
	debug_name = "WQueen";
}

WQueen::~WQueen()
{}

string WQueen::Move(coord newpos)
{
	return Queen::Move(newpos);
}

vector<coord> WQueen::validSpots(Chess* c)
{
	return Queen::validSpots(c);

	//When leveled up, can move through tunnels as if
	//they were connected
	//How do you even do that
}
