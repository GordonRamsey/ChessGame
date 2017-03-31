#include "queen.h"

Queen::Queen(int x, int y, int it) : Piece(x, y, it)
{
  // :)
  debug_name = "queen";
}

Queen::~Queen()
{

}

string Queen::Move(coord newpos)
{
  stringstream ss;
  ss << "[MOVE-Queen]" << newpos.x << "," << newpos.y << endl;
  return ss.str();
}

vector<coord> Queen::validSpots(Chess* c)
{
  //c->board
  coord seek;
  vector<coord> spots;
  stringstream ss;

  //Check North
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y--;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
        spots.push_back(seek);
	ss.str("");
        ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
  }

  //Check North/East
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y--;
    seek.x++;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
        spots.push_back(seek);
	ss.str("");
        ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
  }

  //Check East
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.x++;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
        spots.push_back(seek);
	ss.str("");
        ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
  }

  //Check South/East
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y++;
    seek.x++;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
        spots.push_back(seek);
	ss.str("");
        ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
  }

  //Check South
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y++;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
        spots.push_back(seek);
	ss.str("");
        ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
  }

  //Check South/West
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y++;
    seek.x--;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
        spots.push_back(seek);
	ss.str("");
        ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
  }

  //Check West
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.x--;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
        spots.push_back(seek);
	ss.str("");
        ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
  }

  //Check North/West
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y--;
    seek.x--;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
        spots.push_back(seek);
	ss.str("");
        ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
        break;
      }
      else
	break;
    }
    spots.push_back(seek);
  }
  return spots;
}
