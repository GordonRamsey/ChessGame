#include "Pbishop.h"
using namespace std;

PBishop::PBishop(int x, int y, int it) : Bishop(x, y, it)
{
    debug_name = "Pbishop";
}

PBishop::~PBishop()
{}

string PBishop::Move(coord newpos)
{
    return Bishop::Move(newpos);
}

string PBishop::processClicks(vector<coord> clickedOn, Chess* c)
{
    return "DEFAULT";
}

vector<coord> PBishop::validSpots(Chess* c)
{
        return Bishop::validSpots(c);
}

