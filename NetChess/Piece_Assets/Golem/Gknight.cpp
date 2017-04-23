#include "Gknight.h"
using namespace std;

GKnight::GKnight(int x, int y, int it) : Knight(x, y ,it)
{
    debug_name = "GKnight";
}

GKnight::~GKnight()
{}

string GKnight::Move(coord newpos)
{
    return "DEFAULT";
}

vector<coord> GKnight::validSpots(Chess* c)
{   
    if(!rock)
        return Knight::validSpots(c);

    vector<coord> empty;
    return empty;
}

string GKnight::processClicks(vector<coord> clickedOn, Chess* c)
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
            Rock();
            return ss.str();
        }
    }
    return "DEFAULT";
}

bool GKnight::isRock() const
{
    return rock;
}

void GKnight::Rock()
{
    if(rock)
        rock = false;
    else
        rock = true;
}
