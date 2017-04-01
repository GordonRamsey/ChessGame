#include "Fknight.h"

FKnight::FKnight(int x, int y, int it) : Knight(x, y, it)
{
    m_level = false;
    debug_name = "fknight";
}

FKnight::~FKnight()
{}

string FKnight::Move(coord newpos)
{
    //return Knight::Move(newpos);

    //take newpos and curpos, determine if there's an enemy piece in the same cardinal direction and issue a remove protocol as well if the knight is leveled
}

vector<coord> FKnight::validSpots(Chess* c)
{
        return Knight::validSpots(c);
}
