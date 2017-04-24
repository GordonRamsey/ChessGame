#include "Gpawn.h"
using namespace std;

GPawn::GPawn(int x, int y, int it, char state) : Pawn(x,y,it,state)
{
    debug_name = "Gpawn";
    clicks = 1;
}

GPawn::~GPawn()
{}

string GPawn::Move(coord newpos)
{
    return Pawn::Move(newpos);
}

vector<coord> GPawn::validSpots(Chess* c)
{
    if(!rock)
        return Pawn::validSpots(c);

    vector<coord> empty;
    return empty;
}

string GPawn::processClicks(vector<coord> clickedOn, Chess* c)
{ 
    if(clickedOn.size() != 1)
        return "ERROR";
    
    if(clickedOn[0] == getPos())
    {
        stringstream ss;
        ss.str("");
        ss << "MOVE " << getNum() <<  " " << getPos().x << " " << getPos().y <<  " ~";
        ss << "ROCK " << getNum() << " ~";
        return ss.str();
    }
    return "DEFAULT";
}
