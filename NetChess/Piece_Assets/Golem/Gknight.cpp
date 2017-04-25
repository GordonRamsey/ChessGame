#include "Gknight.h"
using namespace std;

GKnight::GKnight(int x, int y, int it) : Knight(x, y ,it)
{
    debug_name = "Gknight";
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

