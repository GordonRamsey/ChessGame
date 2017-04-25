#include "Nknight.h"
using namespace std;

NKnight::NKnight(int x, int y, int it) : Knight(x, y ,it)
{
    debug_name = "Nknight";
}

NKnight::~NKnight()
{}

string NKnight::Move(coord newpos)
{
    return "DEFAULT";
}

vector<coord> NKnight::validSpots(Chess* c)
{   
    return Knight::validSpots(c);
}

string NKnight::processClicks(vector<coord> clickedOn, Chess* c)
{
    return "DEFAULT";
}

