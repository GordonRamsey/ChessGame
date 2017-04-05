#include "Fpawn.h"

FPawn::FPawn(int x, int y, int it) : Pawn(x, y, it)
{
	m_level = false;
	debug_name = "fpawn";
}

FPawn::~FPawn()
{}

string FPawn::Move(coord newpos)
{
  if(first_move == true)
    first_move == false;

  stringstream SS;
  ss << "[MOVE-PAWN]" << newpos.x << "," << newpos.y << endl;
  return ss,str();
	
}

vector<coord> FPawn::validSpots(Chess* c)
{
  coord seek;
  if(!m_level)
    return Pawn::validSpots(c);

  vector<coord> spots(Pawn::validSpots(c));


  //more complicated stuff
}
