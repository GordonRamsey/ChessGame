#include "Pknight.h"
using namespace std;

PKnight::PKnight(int x, int y, int it) : Knight(x, y ,it)
{
    debug_name = "Pknight";
}

PKnight::~PKnight()
{}

string PKnight::Move(coord newpos)
{
    return "DEFAULT";
}

vector<coord> PKnight::validSpots(Chess* c)
{   
  return Knight::validSpots(c);
}

string PKnight::processClicks(vector<coord> clickedOn, Chess* c)
{
  stringstream ss;
  if(clickedOn.size() != 2)
    return "ERROR";

  //Validate first spot is a capture
  vector<coord> potential = Knight::validSpots(c);
  int x = clickedOn[0].x/64;
  int y = clickedOn[0].y/64;
  
  if(c->board[x][y] == NULL)
    return "ERROR";

  bool valid = false;
  for(unsigned int i=0;i<potential.size();i++)
    if(potential[i].x == x && potential[i].y == y){
      if(c->board[x][y] == NULL)
	return "ERROR";
      valid = true;
      break;
    }
  
  if(!valid)
    return "ERROR";

  //XXX Perform capture checks
  ss << "REMV " << c->board[x][y]->getNum() << " ~";

  //Check if second spot is a capt or a move
  coord oldpos = getPos();
  coord oldspot = getSpot();
  setPos(x*64,y*64);
  
  potential = Knight::validSpots(c);
  x = clickedOn[1].x/64;
  y = clickedOn[1].y/64;
  valid = false;
  for(unsigned int i=0;i<potential.size();i++)
  {
    cerr << "[]" << potential[i].x << "," << potential[i].y << endl;
    if(potential[i].x == x && potential[i].y == y){
      if(c->board[x][y] == NULL)
	ss << "MOVE " << getNum() << " " << x*64 << " " << y*64 << " ~";
      else
	ss << "CAPT " << getNum() << " " << c->board[x][y]->getNum() << " ~";
      valid = true;
      break;
    }
  }
  if(oldspot.x == x && oldspot.y == y){
    ss << "MOVE " << getNum() << " " << oldpos.x << " " << oldpos.y << " ~";
    valid = true;
  }
  if(!valid)
   { 
     setPos(oldpos.x,oldpos.y);
     return "ERROR";
   }
  
  return ss.str();
}

