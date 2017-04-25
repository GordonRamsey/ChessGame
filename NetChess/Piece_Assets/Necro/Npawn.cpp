#include "Npawn.h"
using namespace std;

NPawn::NPawn(int x, int y, int it, char state) : Pawn(x,y,it,state)
{
    debug_name = "Npawn";
}

NPawn::~NPawn()
{}

string NPawn::Move(coord newpos)
{
    return Pawn::Move(newpos);
}

vector<coord> NPawn::validSpots(Chess* c)
{
  return Pawn::validSpots(c);
}

string NPawn::processClicks(vector<coord> clickedOn, Chess* c)
{ 
  return "DEFAULT";
}

string NPawn::turnPass()
{
  if(bitten != NULL)
  {
    stringstream ss;
    ss << "REMV " << bitten->getNum() << " ~";
    ss << "PLAC undead_pawn" << ;
  }

}
