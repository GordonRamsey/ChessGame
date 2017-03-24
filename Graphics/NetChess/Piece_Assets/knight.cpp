#include "knight.h"

vector<coord> Knight::validSpots(Chess c)
{
  //c.board
  int it = 0;
  coord seek;
  vector<coords> spots;

  //Check North/West
  seek = getspot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y-2;
    seek.x-1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.validspots[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y].getTeam() != getTeam()){
        spots.push_back(seek);
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
    break;
  }

  //Check North/East
  seek = getspot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y-2;
    seek.x+1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.validspots[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y].getTeam() != getTeam()){
        spots.push_back(seek);
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
    break;
  }

  //Check East/Norh
  seek = getspot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.x+2;
    seek.y-1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.validspots[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y].getTeam() != getTeam()){
        spots.push_back(seek);
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
    break;
  }

  //Check East/South
  seek = getspot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.x+2;
    seek.y+1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.validspots[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y].getTeam() != getTeam()){
        spots.push_back(seek);
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
    break;
  }

  //Check South/East
  seek = getspot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y+2;
    seek.x+1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.validspots[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y].getTeam() != getTeam()){
        spots.push_back(seek);
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
    break;
  }

  //Check South/West
  seek = getspot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y+2;
    seek.x-1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.validspots[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y].getTeam() != getTeam()){
        spots.push_back(seek);
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
    break;
  }

  //Check West/North
  seek = getspot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.x-2;
    seek.y-1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.validspots[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y].getTeam() != getTeam()){
        spots.push_back(seek);
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
    break;
  }

  //Check West/South
  seek = getspot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.x-2;
    seek.y+1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.validspots[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y].getTeam() != getTeam()){
        spots.push_back(seek);
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
    break;
  }
}
