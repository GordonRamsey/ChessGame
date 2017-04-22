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
    return Queen::validSpots(c);
}

string GQueen::processClicks(vector<coord> clickedOn, Chess* c)
{
    return "DEFAULT";
}
