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
    return Knight::validSpots(c);
}

