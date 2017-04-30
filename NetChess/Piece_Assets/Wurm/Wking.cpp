#include "Wking.h"

WKing::WKing(int x, int y, int it) : King(x, y, it)
{
	debug_name = "WKing";
}

WKing::~WKing()
{}

string WKing::Move(coord newpos)
{
	stringstream ss;
	ss << "MOVE " << getNum() << " " << newpos.x*64 << newpos.y*64 << " ~";
	return ss.str();
}

vector<coord> WKing::validSpots(Chess* c)
{
	return King::validSpots(c); //according to whoever wrote Fking, this returns normal king movements.
}
