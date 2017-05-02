#include "Ppawn.h"
using namespace std;

PPawn::PPawn(int x, int y, int it, char state) : Pawn(x,y,it,state)
{
    debug_name = "Ppawn";
}

PPawn::~PPawn()
{}

string PPawn::Move(coord newpos)
{
  return Pawn::Move(newpos);
}

vector<coord> PPawn::validSpots(Chess* c)
{
  stringstream ss;
  vector<coord> spots;

  //North - cant cap
  coord seek = getSpot();
  if(c->isValid(seek.x,seek.y-1))
  {
    seek.y--;
    if(c->board[seek.x][seek.y] == NULL)
      spots.push_back(seek); 
  }
  //NW - can cap
  seek = getSpot();
  if(c->isValid(seek.x-1,seek.y-1))
  {
    seek.y--;
    seek.x--;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
	spots.push_back(seek);
	ss.str("");
	ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
      }
    }
  }
  //NE - can cap
  seek = getSpot();
  if(c->isValid(seek.x+1,seek.y-1))
  {
    seek.y--;
    seek.x++;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){	
	spots.push_back(seek);
	ss.str("");
	ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
      }
    }
  }
  //S - cant cap
  seek = getSpot();
  if(c->isValid(seek.x,seek.y+1))
  {
    seek.y++;
    if(c->board[seek.x][seek.y] == NULL)
      spots.push_back(seek); 
  }
  //SE - can cap
  seek = getSpot();
  if(c->isValid(seek.x+1,seek.y+1))
  {
    seek.y++;
    seek.x++;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){	
	spots.push_back(seek); 
	ss.str("");
	ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
      }
    }
  }
  //SW - can cap
  seek = getSpot();
  if(c->isValid(seek.x-1,seek.y+1))
  {
    seek.y++;
    seek.x--;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){	
	spots.push_back(seek); 
	ss.str("");
	ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
      }
    }
  } 
  //E - cant cap
  seek = getSpot();
  if(c->isValid(seek.x+1,seek.y))
  {
    seek.x++;
    if(c->board[seek.x][seek.y] == NULL)
      spots.push_back(seek); 
  }
  //W - cant cap
  seek = getSpot();
  if(c->isValid(seek.x-1,seek.y))
  {
    seek.x--;
    if(c->board[seek.x][seek.y] == NULL)
      spots.push_back(seek); 
  }
  //If first turn
  seek = getSpot();
  if(first_move)
  {
    if(dir == 'N'){
      seek.y -= 2;
      if(c->board[seek.x][seek.y] == NULL && c->board[seek.x][seek.y+1] == NULL)
	spots.push_back(seek);
    }
    if(dir == 'S'){
      seek.y += 2;
      if(c->board[seek.x][seek.y] == NULL && c->board[seek.x][seek.y-1] == NULL)
	spots.push_back(seek);
    }
    if(dir == 'E'){
      seek.x += 2;
      if(c->board[seek.x][seek.y] == NULL && c->board[seek.x-1][seek.y] == NULL)
	spots.push_back(seek);
    }
    if(dir == 'W'){
      seek.x -= 2;
      if(c->board[seek.x][seek.y] == NULL && c->board[seek.x+1][seek.y] == NULL)
	spots.push_back(seek);
    }
  }
  return spots;
}

string PPawn::processClicks(vector<coord> clickedOn, Chess* c)
{ 
  return "DEFAULT";
}
