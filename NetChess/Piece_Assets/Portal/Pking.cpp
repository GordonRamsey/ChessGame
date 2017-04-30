#include "Pking.h"
using namespace std;

PKing::PKing(int x, int y, int it) : King(x, y, it)
{
    debug_name = "Pking";
}

PKing::~PKing()
{}

string PKing::Move(coord newpos)
{
    return King::Move(newpos);
}

vector<coord> PKing::validSpots(Chess* c)
{
  return King::validSpots(c);
}

string PKing::processClicks(vector<coord> clickedOn, Chess* c)
{
  
  stringstream ss;
  if(clickedOn.size() != 2)
    return "ERROR";

  cerr << "[PKING] Spot 1:" << clickedOn[0].x/64 << "," << clickedOn[0].y/64 << " Spot 2:" << clickedOn[1].x/64 << "," << clickedOn[1].y/64 << endl;

  //spot 1 - get clip
  if(!(c->isValid(clickedOn[0].x/64, clickedOn[0].y/64)))
    return "ERROR";
  int x = clickedOn[0].x/64;
  int y = clickedOn[0].y/64;

  if(c->board[x][y] == NULL)
    return "ERROR";
  int o_clip = c->board[x][y]->getClip();
  ss << "CLIP " << getNum() << " " << o_clip << " ~";

  //spot 2 - set location
  if(!(c->isValid(clickedOn[0].x/64, clickedOn[0].y/64)))
    return "ERROR";

  x = clickedOn[1].x/64;
  y = clickedOn[1].y/64;

  if(c->board[x][y] == NULL)
    return "ERROR";

  if(c->board[x][y]->getTeam() != getTeam())
    return "ERROR";
  
  //If self click just change clip
  if(clickedOn[1] == getPos())
  {
    cerr << "Self click detected" << endl; 
    cerr << clickedOn[1].x << "," << clickedOn[1].y << " = " <<getPos().x << "," << getPos().y << endl;

    ss << "MOVE " << getNum() << " " << getPos().x << " " << getPos().y << " ~";
    return ss.str();
  }

  //If piece types do not match
  if(c->board[x][y]->getClip() != o_clip)
    return "ERROR";

  //If we swap places with out other piece
  Piece* o = c->board[x][y];
  string o_name = o->debug_name;
  coord o_spot = o->getSpot();
  ss << "MOVE " << getNum() << " " << getPos().x << " " << getPos().y << " ~";
  ss << "SHOV " << o->getNum() << " " << getSpot().x << " " << getSpot().y << " ~"; 
  ss << "SHOV " << getNum() << " " << o_spot.x << " " << o_spot.y << " ~";
  return ss.str();
  
}

