#include "Gking.h"
using namespace std;

GKing::GKing(int x, int y, int it) : King(x, y, it)
{
    debug_name = "Gking";
}

GKing::~GKing()
{}

string GKing::Move(coord newpos)
{
    return "DEFAULT";
}

vector<coord> GKing::validSpots(Chess* c)
{
    if(!rock)
        return King::validSpots(c);

    vector<coord> empty;
    return empty;
}

string GKing::processClicks(vector<coord> clickedOn, Chess* c)
{
    //Should check if leveled up. If so checks spaces around it for allied pieces and turns them to sentinels. Each golem piece should get their own isRock function and Rock function
    return "DEFAULT";
}

bool GKing::isRock() const
{
    return rock;
}

void GKing::Rock()
{
    if(rock)
        rock = false;
    else
        rock = true;
}
