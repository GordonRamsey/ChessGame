#include "Wpawn.h"

WPawn::WPawn(int x, int y, int it) : Pawn(x, y, it)
{
	debug_name = "WPawn";
}

WPawn::~WPawn()
{}

string WPawn::Move(coord newpos)
{
	return Pawn::Move(newpos);
	//Needs to place walls after move:
}

vector<coord> WPawn::validSpots(Chess* c)
{
	return Pawn::validSpots(c);
}
