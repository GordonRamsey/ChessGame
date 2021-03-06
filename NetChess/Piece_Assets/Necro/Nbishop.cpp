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
  if(clickedOn.size() != 3)
    return "ERROR"; 


  if(c->board[clickedOn[0].x/64][clickedOn[0].y/64] == NULL)
    return "ERROR";
  
  if(c->board[clickedOn[0].x/64][clickedOn[0].y/64]->getTeam() != getTeam())
    return "ERROR";
  
  if(c->board[clickedOn[1].x/64][clickedOn[1].y/64]->getTeam() == getTeam())
  {
    coord spotcheck;
    spotcheck.x = clickedOn[2].x/64;
    spotcheck.y = clickedOn[2].y/64;
    
    if(!checkSpawn(spotcheck, c))
      return "ERROR";
    
    ss.str(""); 
    string type = c->board[clickedOn[1].x/64][clickedOn[1].y/64]->debug_name;

    if(type.find("king") != string::npos)
      return "ERROR";
    
    if(type.find("queen") != string::npos)
      return "ERROR";
    
    
    ss << "MOVE " << getNum() << " " << getPos().x << " " << getPos().y << " ~";
    ss << "REMV " << c->board[clickedOn[0].x/64][clickedOn[0].y/64]->getNum() << " ~";
    ss << "PLAC " << type << " " << spotcheck.x << " " << spotcheck.y << " " << getTeam()-1 << " ~"; 
    return ss.str(); 
  }
  return "ERROR";
}

vector<coord> NBishop::validSpots(Chess* c)
{
  return Bishop::validSpots(c);
}

