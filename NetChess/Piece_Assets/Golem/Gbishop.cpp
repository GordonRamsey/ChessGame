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
    return Bishop::Move(newpos);
}

string GBishop::processClicks(vector<coord> clickedOn, Chess* c)
{
    if(clickedOn.size() != 1)
        return "ERROR";

    if(clickedOn[0] == getPos())
    {
        if(isRock())
        {
            stringstream ss;
            ss.str("");
            ss << "MOVE " << getNum() << " " << getPos().x << " " << getPos().y << " ~";
	    ss << "ROCK " << getNum() << " ~";
	    clicks = 0;
            return ss.str();
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

