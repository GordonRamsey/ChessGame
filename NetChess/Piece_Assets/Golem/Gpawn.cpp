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

string Gpawn::processClicks(vector<coord> clickedOn, Chess* c)
{ 
    if(clickedOn.size() != 1)
        return "ERROR";
    
    if(clickedOn[0] == getSpot())
    {
        stringstream ss;
        ss.str("");
        ss << "MOVE " << getNum() <<  " " << getPos().x << " " << getPos().y <<  " ~";
        Rock();
        return ss;
    }
    return "DEFAULT";
}
