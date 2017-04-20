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
    return "DEFAULT";
}

vector<coord> GBishop::validSpots(Chess* c)
{
    return Bishop::validSpots(c);
}

