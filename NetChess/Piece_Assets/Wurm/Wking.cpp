#include "Wking.h"

WKing::WKing(int x, int y, int it) : King(x, y, it)
{
	debug_name = "WKing";
}

WKing::~WKing()
{}

string WKing::Move(coord newpos)
{
	return King::Move(newpos);
}

string WKing::createCrater(coord spot, Chess* c)
{
	stringstream ss;

	//Check North:
	
}

vector<coord> WKing::validSpots(Chess* c)
{
	return King::validSpots(c); //according to whoever wrote Fking, this returns normal king movements.
}
