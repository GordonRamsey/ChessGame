#include "Nrook.h"
using namespace std;

NRook::NRook(int x, int y, int it) : Rook(x, y, it)
{
    debug_name = "Nrook";
}

NRook::~NRook()
{}

string NRook::Move(coord newpos)
{
    return Rook::Move(newpos);
}

string NRook::processClicks(vector<coord> clickedOn, Chess* c)
{
    return "DEFAULT";
}

vector<coord> NRook::validSpots(Chess* c)
{
    return Rook::validSpots(c);
}

