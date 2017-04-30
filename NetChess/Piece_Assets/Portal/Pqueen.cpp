#include "Pqueen.h"
using namespace std;

PQueen::PQueen(int x, int y, int it) : Queen(x, y, it)
{
    debug_name = "Pqueen";
    clicks = 0;
}

PQueen::~PQueen()
{}

string PQueen::Move(coord newpos)
{
    return Queen::Move(newpos);
}

vector<coord> PQueen::validSpots(Chess* c)
{
  return Queen::validSpots(c);
}

string PQueen::processClicks(vector<coord> clickedOn, Chess* c)
{
  stringstream ss;
  cerr << "size:" << clickedOn.size() << endl;
  if(clickedOn.size() != 2)
    return "ERROR";

  int x = clickedOn[0].x/64;
  int y = clickedOn[0].y/64;

  cerr << "checking null:" << x << "," << y << endl;
  if(c->board[x][y] == NULL)
    return "ERROR";
  
  if(c->board[x][y]->getTeam() != getTeam())
    return "ERROR";

  Piece* o = c->board[x][y];

  cerr << "[PQueen] Friendly piece:" << o->debug_name << endl;

  x = clickedOn[1].x/64;
  y = clickedOn[1].y/64;

  cerr << "[Pqueen] click 2:" << x << "," << y << endl;


  //Click on an adjacent square
  bool goodspot = false;
  if(x == getSpot().x && y == getSpot().y+1)
    goodspot = true;
  else if(x == getSpot().x && y == getSpot().y-1)
    goodspot = true;
  else if(x == getSpot().x+1 && y == getSpot().y)
    goodspot = true;
  else if(x == getSpot().x+1 && y == getSpot().y+1)
    goodspot = true;
  else if(x == getSpot().x+1 && y == getSpot().y-1)
    goodspot = true;
  else if(x == getSpot().x-1 && y == getSpot().y)
    goodspot = true;
  else if(x == getSpot().x-1 && y == getSpot().y+1)
    goodspot = true;
  else if(x == getSpot().x-1 && y == getSpot().y-1)
    goodspot = true;

  if(!goodspot)
    return "ERROR";

  if(c->board[x][y] != NULL)
    return "ERROR";

  ss << "MOVE " << getNum() << " " << getPos().x << " " << getPos().y << " ~";
  ss << "SHOV " << o->getNum() << " " << x << " " << y << " ~";

  
  
  return ss.str();
}

