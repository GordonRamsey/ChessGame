#include "king.h"

King::King(int x, int y, int it) : Piece(x, y, it)
{
  // :)
  debug_name = "king";
}

King::~King()
{

}
string King::Move(coord newpos)
{
  return "DEFAULT";
}

vector<coord> King::validSpots(Chess* c)
{
  //c->board
  vector<coord> spots;
  stringstream ss;
  //North
  coord seek = getSpot();
  if(c->isValid(seek.x,seek.y-1))
  {
    seek.y--;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){	
	spots.push_back(seek);
	ss.str("");
        ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
      }
    }
    else	
      spots.push_back(seek); 
  }

  //North/East
  seek = getSpot();
  if(c->isValid(seek.x+1,seek.y-1))
  {
    seek.y--;
    seek.x++;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam())      {
	spots.push_back(seek);
	ss.str("");
        ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
      }
    }
    else
      spots.push_back(seek); 

  }

  //East
  seek = getSpot();
  if(c->isValid(seek.x+1,seek.y))
  {
    seek.x++;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
	spots.push_back(seek); 
	ss.str("");
        ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
      }
    }
    else
      spots.push_back(seek); 
  }

  //South/East
  seek = getSpot();
  if(c->isValid(seek.x+1,seek.y+1))
  {
    seek.x++;
    seek.y++;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
	spots.push_back(seek);
	ss.str("");
        ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
      }
    }
    else
      spots.push_back(seek); 
  }

  //South
  seek = getSpot();
  if(c->isValid(seek.x,seek.y+1))
  {
    seek.y++;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
	spots.push_back(seek); 
	ss.str("");
        ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
      }
    }
    else
      spots.push_back(seek); 
  }

  //South/West
  seek = getSpot();
  if(c->isValid(seek.x-1,seek.y+1))
  {
    seek.y++;
    seek.x--;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
	spots.push_back(seek); 
	ss.str("");
        ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
      }
    }
    else
      spots.push_back(seek); 
  }

  //West
  seek = getSpot();
  if(c->isValid(seek.x-1,seek.y))
  {
    seek.x--;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
	spots.push_back(seek);
	ss.str("");
        ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
      }
    }
    else
      spots.push_back(seek); 
  }

  //North/West
  seek = getSpot();
  if(c->isValid(seek.x-1,seek.y-1))
  {
    seek.x--;
    seek.y--;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
	spots.push_back(seek);
	ss.str("");
        ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
      }
    }
    else
      spots.push_back(seek); 
  }
  return spots;
}
