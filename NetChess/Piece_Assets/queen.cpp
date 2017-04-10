#include "queen.h"

Queen::Queen(int x, int y, int it) : Piece(x, y, it)
{
  debug_name = "queen";
  clicks = 1;
}

Queen::~Queen()
{

}

string Queen::Move(coord newpos)
{
  return "DEFAULT";
}

string Queen::processClicks(vector<coord> clickedOn, Chess* c)
{
  stringstream ss;
  ss.str("");
  
  if(clickedOn.size() != 1)
    return "ERROR";

  //Need to validate spots before acting on them
  if(c->board[clickedOn[0].x/64][clickedOn[0].y/64] == NULL)
    return "ERROR"; 

  int num = c->board[clickedOn[0].x/64][clickedOn[0].y/64]->getNum();
  
  //Are we clicking on ourself?
  if(num == getNum())
    return "ERROR";

  //Everything checks out, fashion a command to make the move
  //setClip(1);
  ss << "MOVE " << c->board[getSpot().x][getSpot().y]->getNum() << " " << clickedOn[0].x << " " << clickedOn[0].y << " ~";
  ss << "REMV " << num << " ~";

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
    if(seek.y < 0)//Out of bounds
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
    if(seek.x > 13)//Out of bounds
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
    if(seek.y > 13 or seek.x > 13)//Out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
        spots.push_back(seek);
	ss.str("");
        ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	ss << "PLAC " << "queen " << getSpot().x << " " << getSpot().y << " " << getTeam()-1 << " ~";//Make a friendly queen!
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
    if(seek.y > 13)//Out of bounds
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
    if(seek.y > 13 or seek.x < 0)//Out of bounds
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
    if(seek.x < 0)//Out of bounds
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
    if(seek.y < 0 or seek.x < 0)//Out of bounds
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
