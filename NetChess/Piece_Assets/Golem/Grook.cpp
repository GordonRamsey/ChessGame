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
    return "DEFAULT";
}

string GRook::processClicks(vector<coord> clickedOn, Chess* c)
{
    return "DEFAULT";
}

vector<coord> GRook::validSpots(Chess* c)
{
    return Rook::validSpots(c);
}


