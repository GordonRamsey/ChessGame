#include "Pknight.h"
using namespace std;

PKnight::PKnight(int x, int y, int it) : Knight(x, y ,it)
{
    debug_name = "Pknight";
}

PKnight::~PKnight()
{}

string PKnight::Move(coord newpos)
{
    return "DEFAULT";
}

vector<coord> PKnight::validSpots(Chess* c)
{   
        return Knight::validSpots(c);
}

string PKnight::processClicks(vector<coord> clickedOn, Chess* c)
{
    return "DEFAULT";
}

