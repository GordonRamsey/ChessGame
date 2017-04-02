#include "Fpawn.h"

FPawn::FPawn(int x, int y, int it) : Pawn(x, y, it)
{
	m_level = false;
}

FPawn::~FPawn()
{}

string FPawn::Move(coord newpos)
{
	
}

vector<coord> FPawn::validSpots(Chess* c)
{
	coord seek;
	if(!m_level)
		return Pawn::validSpots(c);

	//more complicated stuff
}
