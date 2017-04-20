#include "Gpawn.h"
using namespace std;

GPawn::GPawn(int x, int y, int it, char state) : Pawn(x,y,it,state)
{
    debug_name = "Gpawn";
}

GPawn::~GPawn()
{}

string GPawn::Move(coord newpos)
{
    return "DEFAULT";
}

vector<coord> GPawn::validSpots(Chess* c)
{
    if(!rock)
        return Pawn::validSpots(c);

    vector<coord> empty;
    return empty;
}

bool GPawn::isRock() const
{
    return rock;
}

void GPawn::Rock()
{
    if(rock)
        rock = false;
    else
        rock = true;
}
