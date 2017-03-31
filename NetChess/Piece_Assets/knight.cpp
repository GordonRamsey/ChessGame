#include "knight.h"

Knight::Knight(int x, int y, int it) : Piece(x, y, it)
{
  // :)
  debug_name = "knight";
}

Knight::~Knight()
{

}
string Knight::Move(coord newpos)
{
  stringstream ss;
  ss << "[MOVE-KNIGHT]" << newpos.x << "," << newpos.y << endl;
  return ss.str();
}

vector<coord> Knight::validSpots(Chess* c)
{
  //c->board
  coord seek;
  vector<coord> spots;
  stringstream ss;

  //Check North/West
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y-=2;
    seek.x-=1;
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
    break;
  }

  //Check North/East
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y-=2;
    seek.x+=1;
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
    break;
  }

  //Check East/Norh
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.x+=2;
    seek.y-=1;
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
    break;
  }

  //Check East/South
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.x+=2;
    seek.y+=1;
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
    break;
  }

  //Check South/East
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y+=2;
    seek.x+=1;
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
    break;
  }

  //Check South/West
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y+=2;
    seek.x-=1;
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
    break;
  }

  //Check West/North
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.x-=2;
    seek.y-=1;
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
    break;
  }

  //Check West/South
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.x-=2;
    seek.y+=1;
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
    break;
  }
  return spots;
}
