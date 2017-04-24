#include "Grook.h"
using namespace std;

GRook::GRook(int x, int y, int it) : Rook(x, y, it)
{
    debug_name = "Grook";
}

GRook::~GRook()
{}

string GRook::Move(coord newpos)
{
    return Rook::Move(newpos);
}

string GRook::processClicks(vector<coord> clickedOn, Chess* c)
{
    if(clickedOn.size() != 1)
        return "ERROR";
    
    if(clickedOn[0] == getSpot())
    {
        if(isRock())
        {
            stringstream ss;
            ss.str("");
            ss << "MOVE " << getNum() << " " << getPos().x << " " << getPos().y << " ~";
            return ss.str();
        }
    }
    return "DEFAULT";
}

vector<coord> GRook::validSpots(Chess* c)
{
    if(!rock)
        return Rook::validSpots(c);
    
    vector<coord> empty;
    return empty;
}

