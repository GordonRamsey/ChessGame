#include "rook.h"

Rook::Rook(int x, int y, int it) : Piece(x, y, it)
{
  // :)
  debug_name = "rook";
}

Rook::~Rook()
{

}

string Rook::Move(coord newpos)
{
  return "DEFAULT";
}


vector<coord> Rook::validSpots(Chess* c)
{
  //c->board
  stringstream ss;
  coord seek;
  vector<coord> spots;
  //Check north
  seek = getSpot();
  while(true){//Check north until we hit a condition that stops us
    seek.y--;
    if(seek.y < 0)//If out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//If not valid spot
      break;
    if(c->board[seek.x][seek.y] != NULL)//If spot occupied
    { 
      if(c->board[seek.x][seek.y]->getTeam() != getTeam())//Check if enemy 
      {
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

  //Check south
  seek = getSpot();
  while(true){//Check south until we hit a condition that stops us
    seek.y++;
    if(seek.y > 13)//If out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//If not valid spot
      break;
    if(c->board[seek.x][seek.y] != NULL)//If spot occupied
    {  
      if(c->board[seek.x][seek.y]->getTeam() != getTeam())//Check if enemy 
      {
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

  //Check east
  seek = getSpot();
  while(true){//Check east until we hit a condition that stops us
    seek.x++;
    if(seek.x > 13)//If out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//If not valid spot
      break;
    if(c->board[seek.x][seek.y] != NULL)//If spot occupied
    {  
      if(c->board[seek.x][seek.y]->getTeam() != getTeam())//Check if enemy 
      {
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

  //Check west
  seek = getSpot();
  while(true){//Check west until we hit a condition that stops us
    seek.x--;
    if(seek.x < 0)//If out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//If not valid spot
      break;
    if(c->board[seek.x][seek.y] != NULL)//If spot occupied
    {  
      if(c->board[seek.x][seek.y]->getTeam() != getTeam())//Check if enemy 
      {
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
