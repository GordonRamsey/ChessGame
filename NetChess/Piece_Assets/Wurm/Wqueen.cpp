#include "Wqueen.h"

WQueen::WQueen(int x, int y, int it) : Queen(x, y, it)
{
	debug_name = "Wqueen";
}

WQueen::~WQueen()
{}

string WQueen::Move(coord newpos)
{
	return Queen::Move(newpos);
}

string WQueen::processClicks(vector<coord> clickedOn, Chess* c)
{
  stringstream ss;
  if(clickedOn.size() != 1)
    return "ERROR";

  int x = clickedOn[0].x/64;
  int y = clickedOn[0].y/64;

  if(c->board[x][y] != NULL)
    return "ERROR";

  ss << "PLAC Tunnel " << x << " " << y << " -1 ~";
  return ss.str();
}

vector<coord> WQueen::validSpots(Chess* c)
{
	return Queen::validSpots(c);

	//When leveled up, can move through tunnels as if
	//they were connected
	//How do you even do that
}
