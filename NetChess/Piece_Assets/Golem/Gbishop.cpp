#include "Gbishop.h"
using namespace std;

GBishop::GBishop(int x, int y, int it) : Bishop(x, y, it)
{
    debug_name = "Gbishop";
}

GBishop::~GBishop()
{}

string GBishop::Move(coord newpos)
{
    return "DEFAULT";
}

string GBishop::processClicks(vector<coord> clickedOn, Chess* c)
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
            return ss;
        }
    }
    return "DEFAULT";
}

vector<coord> GBishop::validSpots(Chess* c)
{
    if(!rock)
        return Bishop::validSpots(c);

    vector<coord> empty;
    return empty;
}

bool GBishop::isRock() const
{
    return rock;
}

void GBishop::Rock()
{
    if(rock)
        rock = false;
    else
        rock = true;
}
