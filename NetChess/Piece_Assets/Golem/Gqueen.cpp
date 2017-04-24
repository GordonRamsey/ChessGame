#include "Gqueen.h"
using namespace std;

GQueen::GQueen(int x, int y, int it) : Queen(x, y, it)
{
    debug_name = "Gqueen";
}

GQueen::~GQueen()
{}

string GQueen::Move(coord newpos)
{
    return "DEFAULT";
}

vector<coord> GQueen::validSpots(Chess* c)
{
    if(!rock)
        return Queen::validSpots(c);

    vector<coord> empty;
    return empty;
}

string GQueen::processClicks(vector<coord> clickedOn, Chess* c)
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

