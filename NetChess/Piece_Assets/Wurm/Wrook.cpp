#include "Wrook.h"

WRook::WRook(int x, int y, int it) : Rook(x, y, it)
{
  debug_name = "Wrook";
}

WRook::~WRook()
{}

string WRook::Move(coord newpos)
{
	if(m_level)
	{
	  stringstream ss;
	  ss << "PLAC Tunnel " << newpos.x << " " << newpos.y << " -1 ~";
	  ss << "PLAC Tunnel " << getSpot().x << " " << getSpot().y << " -1 ~";
	  return ss.str();
	}
	else
	  return Rook::Move(newpos);
}

void WRook::wurmSpots(vector<coord> &spots, Chess* c)
{
  for(int i=0;i<14;i++)
    for(int j=0;j<14;j++){
      if(c->terrain[i][j] == 1)
      {
	vector<coord> newstuff = Rook::validSpots(c);
	spots.insert(spots.end(), newstuff.begin(), newstuff.end());
      }
    }

}

vector<coord> WRook::validSpots(Chess* c)
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
    if(c->terrain[seek.x][seek.y] == 1)
      wurmSpots(spots,c);
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
    if(c->terrain[seek.x][seek.y] == 1)
      wurmSpots(spots,c);
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
    if(c->terrain[seek.x][seek.y] == 1)
      wurmSpots(spots,c);
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
    if(c->terrain[seek.x][seek.y] == 1)
      wurmSpots(spots,c);
    spots.push_back(seek);
  }
  return spots;

}
