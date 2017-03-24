#include "knight.h"

Knight::Knight(int x, int y, int it) : Piece(x, y, it)
{
  // :)
}

Knight::~Knight()
{

}

vector<coord> Knight::validSpots(Chess c)
{
  //c.board
  coord seek;
  vector<coord> spots;

  //Check North/West
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y-=2;
    seek.x-=1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.board[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam()){
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
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y-=2;
    seek.x+=1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.board[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam()){
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
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.x+=2;
    seek.y-=1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.board[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam()){
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
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.x+=2;
    seek.y+=1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.board[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam()){
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
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y+=2;
    seek.x+=1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.board[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam()){
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
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y+=2;
    seek.x-=1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.board[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam()){
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
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.x-=2;
    seek.y-=1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.board[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam()){
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
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.x-=2;
    seek.y+=1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c.validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c.board[seek.x][seek.y] != NULL){
      if(c.board[seek.x][seek.y]->getTeam() != getTeam()){
        spots.push_back(seek);
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
    break;
  }
  return spots;
}
