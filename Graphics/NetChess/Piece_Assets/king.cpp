#include "king.h"

King::King(int x, int y, int it) : Piece(x, y, it)
{
  // :)
}

vector<coord> King::validSpots(Chess c)
{
  //c.board
  vector<coord> spots;

  //North - cant cap
  coord seek = getSpot();
  if(c.isValid(seek.x,seek.y-1))
  {
    seek.y--;
    if(c.board[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam())
	spots.push_back(seek);
      else	
	spots.push_back(seek); 
    }
  }
  //NW - can cap
  seek = getSpot();
  if(c.isValid(seek.x-1,seek.y-1))
  {
    seek.y--;
    seek.x--;
    if(c.board[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam())
	spots.push_back(seek);
      else
	spots.push_back(seek); 
    }

  }
  //NE - can cap
  seek = getSpot();
  if(c.isValid(seek.x+1,seek.y-1))
  {
    seek.y--;
    seek.x++;
    if(c.board[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam())
	spots.push_back(seek); 
      else
	spots.push_back(seek); 
    }
  }
  //S - cant cap
  seek = getSpot();
  if(c.isValid(seek.x,seek.y+1))
  {
    seek.y++;
    if(c.board[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam())
	spots.push_back(seek);
      else
	spots.push_back(seek); 
    }
  }
  //SE - can cap
  seek = getSpot();
  if(c.isValid(seek.x+1,seek.y+1))
  {
    seek.y++;
    seek.x++;
    if(c.board[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam())
	spots.push_back(seek); 
      else
	spots.push_back(seek); 
    }
  }
  //SW - can cap
  seek = getSpot();
  if(c.isValid(seek.x-1,seek.y+1))
  {
    seek.y++;
    seek.x--;
    if(c.board[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam())
	spots.push_back(seek); 
      else
	spots.push_back(seek); 
    }
  } 
  //E - cant cap
  seek = getSpot();
  if(c.isValid(seek.x+1,seek.y))
  {
    seek.x++;
    if(c.board[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam())
	spots.push_back(seek);
      else
	spots.push_back(seek); 
    }
  }
  //W - cant cap
  seek = getSpot();
  if(c.isValid(seek.x-1,seek.y))
  {
    seek.x--;
    if(c.board[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam())
	spots.push_back(seek);
      else
	spots.push_back(seek); 
    }
  }
  return spots;
}
