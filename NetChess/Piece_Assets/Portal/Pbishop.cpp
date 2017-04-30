#include "Pbishop.h"
using namespace std;

PBishop::PBishop(int x, int y, int it) : Bishop(x, y, it)
{
    debug_name = "Pbishop";
}

PBishop::~PBishop()
{}

string PBishop::Move(coord newpos)
{
    return Bishop::Move(newpos);
}

string PBishop::processClicks(vector<coord> clickedOn, Chess* c)
{
    return "DEFAULT";
}

vector<coord> PBishop::validSpots(Chess* c)
{
  if(!m_level)
    return Bishop::validSpots(c);

  stringstream ss;
  coord seek;
  vector<coord> spots;

  //Check North/East
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y--;
    seek.x++;
    if(seek.y < 0)
      seek.y = 13;
    if(seek.x > 13)//Out of bounds
      seek.x = 0;
    if(c->validspots[seek.x][seek.y] == 0)//valid spot
      continue;
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
    if(seek.y > 13)
      seek.y = 0;
    if(seek.x > 13)//Out of bounds
      seek.x = 0;
    if(c->validspots[seek.x][seek.y] == 0)//valid spot
      continue;
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
    if(seek.y < 0)
      seek.y = 13;
    if(seek.x < 0)//Out of bounds
      seek.x = 13;
    if(c->validspots[seek.x][seek.y] == 0)//valid spot
      continue;
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
    if(seek.y > 13)
     seek.y = 0;
    if(seek.x < 0)//Out of bounds
      seek.x = 13;
    if(c->validspots[seek.x][seek.y] == 0)//valid spot
      continue;
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

