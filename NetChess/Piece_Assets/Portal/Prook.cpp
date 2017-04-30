#include "Prook.h"
using namespace std;

PRook::PRook(int x, int y, int it) : Rook(x, y, it)
{
    debug_name = "Prook";
}

PRook::~PRook()
{}

string PRook::Move(coord newpos)
{
    return Rook::Move(newpos);
}

string PRook::processClicks(vector<coord> clickedOn, Chess* c)
{
  return "DEFAULT";
}

vector<coord> PRook::validSpots(Chess* c)
{
  if(!m_level)
    return Rook::validSpots(c);

  stringstream ss;
  coord seek;
  vector<coord> spots;
  //Check north
  seek = getSpot();
  while(true){//Check north until we hit a condition that stops us
    seek.y--;
    if(seek.y < 0)//If out of bounds
      seek.y = 13;
    if(c->validspots[seek.x][seek.y] == 0)//If not valid spot
      continue;
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
      seek.y = 0;
    if(c->validspots[seek.x][seek.y] == 0)//If not valid spot
      continue;
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
      seek.x = 0;
    if(c->validspots[seek.x][seek.y] == 0)//If not valid spot
      continue;
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
      seek.x = 13;
    if(c->validspots[seek.x][seek.y] == 0)//If not valid spot
      continue;
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

