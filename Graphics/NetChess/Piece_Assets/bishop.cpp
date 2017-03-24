#include "bishop.h"

vector<coord> Bishop::validSpots(Chess c)
{
  //c.board
  int it = 0;
  coord seek;
  vector<coords> spots;

  //Check North/East
  seek = getspot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y--;
    seek.x++;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.validspots[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam()){
        spots.push_back(seek);
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
  }

  //Check South/East
  seek = getspot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y++;
    seek.x++;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.validspots[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam()){
        spots.push_back(seek);
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
  }

  //Check North/West
  seek = getspot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y--;
    seek.x--;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.validspots[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam()){
        spots.push_back(seek);
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
  }

  //Check South/West
  seek = getspot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y++;
    seek.x--;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.validspots[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam()){
        spots.push_back(seek);
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
  }
}
