#include "Npawn.h"
using namespace std;

NPawn::NPawn(int x, int y, int it, char state) : Pawn(x,y,it,state)
{
    debug_name = "Npawn";
}

NPawn::~NPawn()
{}

string NPawn::Move(coord newpos)
{
    return Pawn::Move(newpos);
}

vector<coord> NPawn::validSpots(Chess* c)
{
  stringstream ss;
  vector<coord> spots;

  //North - cant cap
  coord seek = getSpot();
  if(dir != 'S')
    if(c->isValid(seek.x,seek.y-1))
    {
      seek.y--;
      if(c->board[seek.x][seek.y] == NULL)
	spots.push_back(seek); 
    }
  //NW - can cap
  seek = getSpot();
  if(dir != 'S' && dir != 'E')
    if(c->isValid(seek.x-1,seek.y-1))
    {
      seek.y--;
      seek.x--;
      if(c->board[seek.x][seek.y] != NULL){
	if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
	  spots.push_back(seek);
	  ss.str("");
	  ss << "BITE " << c->board[seek.x][seek.y]->getNum() << " ~";
	  ss << "MOVE " << getNum() << " " << getPos().x << " " << getPos().y << " ~";
	  captureMap[seek] = ss.str();
	}
      }
    }
  //NE - can cap
  seek = getSpot();
  if(dir != 'S' && dir != 'W')
    if(c->isValid(seek.x+1,seek.y-1))
    {
      seek.y--;
      seek.x++;
      if(c->board[seek.x][seek.y] != NULL){
	if(c->board[seek.x][seek.y]->getTeam() != getTeam()){	
	  spots.push_back(seek);
	  ss.str("");
	  ss << "BITE " << c->board[seek.x][seek.y]->getNum() << " ~";
	  ss << "MOVE " << getNum() << " " << getPos().x << " " << getPos().y << " ~";
	  captureMap[seek] = ss.str();
	}
      }
    }
  //S - cant cap
  seek = getSpot();
  if(dir != 'N')
    if(c->isValid(seek.x,seek.y+1))
    {
      seek.y++;
      if(c->board[seek.x][seek.y] == NULL)
	spots.push_back(seek); 
    }
  //SE - can cap
  seek = getSpot();
  if(dir != 'N' && dir != 'W')
    if(c->isValid(seek.x+1,seek.y+1))
    {
      seek.y++;
      seek.x++;
      if(c->board[seek.x][seek.y] != NULL){
	if(c->board[seek.x][seek.y]->getTeam() != getTeam()){	
	  spots.push_back(seek); 
	  ss.str("");
	  ss << "BITE " << c->board[seek.x][seek.y]->getNum() << " ~";
	  ss << "MOVE " << getNum() << " " << getPos().x << " " << getPos().y << " ~";
	  captureMap[seek] = ss.str();
	}
      }
    }
  //SW - can cap
  seek = getSpot();
  if(dir != 'N' && dir != 'E')
    if(c->isValid(seek.x-1,seek.y+1))
    {
      seek.y++;
      seek.x--;
      if(c->board[seek.x][seek.y] != NULL){
	if(c->board[seek.x][seek.y]->getTeam() != getTeam()){	
	  spots.push_back(seek); 
	  ss.str("");
	  ss << "BITE " << c->board[seek.x][seek.y]->getNum() << " ~";
	  ss << "MOVE " << getNum() << " " << getPos().x << " " << getPos().y << " ~";
	  captureMap[seek] = ss.str();
	}
      }
    } 
  //E - cant cap
  seek = getSpot();
  if(dir != 'W')
    if(c->isValid(seek.x+1,seek.y))
    {
      seek.x++;
      if(c->board[seek.x][seek.y] == NULL)
	spots.push_back(seek); 
    }
  //W - cant cap
  seek = getSpot();
  if(dir != 'E')
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
      if(c->board[seek.x][seek.y] == NULL && c->board[seek.x][seek.y-1] == NULL)
	spots.push_back(seek);
    }
    if(dir == 'S'){
      seek.y += 2;
      if(c->board[seek.x][seek.y] == NULL && c->board[seek.x][seek.y+1] == NULL)
	spots.push_back(seek);
    }
    if(dir == 'E'){
      seek.x += 2;
      if(c->board[seek.x][seek.y] == NULL && c->board[seek.x+1][seek.y] == NULL)
	spots.push_back(seek);
    }
    if(dir == 'W'){
      seek.x -= 2;
      if(c->board[seek.x][seek.y] == NULL && c->board[seek.x-1][seek.y] == NULL)
	spots.push_back(seek);
    }
  }
  return spots;

}

string NPawn::processClicks(vector<coord> clickedOn, Chess* c)
{ 
  return "DEFAULT";
}

