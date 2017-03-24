#include "pawn.h"

//XXX:Need to find a way to mark first move

Pawn::Pawn(int x, int y, int it, char state) : Piece(x, y, it)
{
  dir = state;
  // :)
}

Pawn::~Pawn()
{

}

vector<coord> Pawn::validSpots(Chess* c)
{
  //c->board
  vector<coord> spots;

  //North - cant cap
  coord seek = getSpot();
  if(dir != 'D')
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
      if(c->board[seek.x][seek.y]->getTeam() != getTeam())
	spots.push_back(seek);
      else
	spots.push_back(seek); 
    }

  }
  //NE - can cap
  seek = getSpot();
  if(c->isValid(seek.x+1,seek.y-1))
  {
    seek.y--;
    seek.x++;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam())
	spots.push_back(seek); 
      else
	spots.push_back(seek); 
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
  if(c->isValid(seek.x+1,seek.y+1))
  {
    seek.y++;
    seek.x++;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam())
	spots.push_back(seek); 
      else
	spots.push_back(seek);
    }
  }
  //SW - can cap
  seek = getSpot();
  if(c->isValid(seek.x-1,seek.y+1))
  {
    seek.y++;
    seek.x--;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam())
	spots.push_back(seek); 
      else
	spots.push_back(seek); 
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
      spots.push_back(seek);
    }
    if(dir == 'S'){
      seek.y += 2;
      spots.push_back(seek);
    }
    if(dir == 'E'){
      seek.x += 2;
      spots.push_back(seek);
    }
    if(dir == 'W'){
      seek.x -= 2;
      spots.push_back(seek);
    }
  }
  return spots;
}
