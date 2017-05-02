#include "Nbishop.h"
using namespace std;

NBishop::NBishop(int x, int y, int it) : Bishop(x, y, it)
{
    debug_name = "Nbishop";
}

NBishop::~NBishop()
{}

string NBishop::Move(coord newpos)
{
  return Bishop::Move(newpos);
}

bool NBishop::checkSpawn(coord spot, Chess* c)
{
  coord tmp = spot;
  tmp.x++;
  if(c->board[tmp.x][tmp.y] != NULL)
    if(c->board[tmp.x][tmp.y]->debug_name == "Nrook")
      if(c->board[tmp.x][tmp.y]->isLevel())
	return true;

  tmp = spot;
  tmp.x--;
  if(c->board[tmp.x][tmp.y] != NULL)
    if(c->board[tmp.x][tmp.y]->debug_name == "Nrook")
      if(c->board[tmp.x][tmp.y]->isLevel())
	return true;

  tmp = spot;
  tmp.y++;
  if(c->board[tmp.x][tmp.y] != NULL)
    if(c->board[tmp.x][tmp.y]->debug_name == "Nrook")
      if(c->board[tmp.x][tmp.y]->isLevel())
	return true;
  
  tmp = spot;
  tmp.y--;
  if(c->board[tmp.x][tmp.y] != NULL)
    if(c->board[tmp.x][tmp.y]->debug_name == "Nrook")
      if(c->board[tmp.x][tmp.y]->isLevel())
	return true;
  
  tmp = spot;
  tmp.x++;
  tmp.y++;
  if(c->board[tmp.x][tmp.y] != NULL)
    if(c->board[tmp.x][tmp.y]->debug_name == "Nrook")
      if(c->board[tmp.x][tmp.y]->isLevel())
	return true;

  tmp = spot;
  tmp.x--;
  tmp.y--;
  if(c->board[tmp.x][tmp.y] != NULL)
    if(c->board[tmp.x][tmp.y]->debug_name == "Nrook")
      if(c->board[tmp.x][tmp.y]->isLevel())
	return true;

  tmp = spot;
  tmp.x++;
  tmp.y--;
  if(c->board[tmp.x][tmp.y] != NULL)
    if(c->board[tmp.x][tmp.y]->debug_name == "Nrook")
      if(c->board[tmp.x][tmp.y]->isLevel())
	return true;

  tmp = spot;
  tmp.x--;
  tmp.y++;
  if(c->board[tmp.x][tmp.y] != NULL)
    if(c->board[tmp.x][tmp.y]->debug_name == "Nrook")
      if(c->board[tmp.x][tmp.y]->isLevel())
	return true;

  return false;
}

string NBishop::processClicks(vector<coord> clickedOn, Chess* c)
{
  stringstream ss; 
  if(clickedOn.size() != 2)
    return "ERROR"; 

  if(c->board[clickedOn[0].x/64][clickedOn[0].y/64]->getTeam() == getTeam())
  {
    coord spotcheck;
    spotcheck.x = clickedOn[1].x/64;
    spotcheck.y = clickedOn[1].y/64;
    
    if(!checkSpawn(spot, c))
      return "ERROR";
    
    ss.str(""); 
    string type = c->board[clickedOn[0].x/64][clickedOn[0].y/64]->debug_name;
    ss << "PLAC " << type << " " << spotcheck.x << " " << spotcheck.y << " " << getTeam()-1 << " ~"; 
    return ss.str(); 
  }
}

vector<coord> NBishop::validSpots(Chess* c)
{
  return Bishop::validSpots(c);
}

