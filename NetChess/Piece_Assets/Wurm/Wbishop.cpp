#include "Wbishop.h"

WBishop::WBishop(int x, int y, int it) : Bishop(x, y, it)
{
  debug_name = "Wbishop";
}

WBishop::~WBishop()
{}

string WBishop::Move(coord newpos)
{
  if(m_level)
  {
    stringstream ss;
    ss << "PLAC Tunnel " << newpos.x << " " << newpos.y << " " << getTeam() << " ~";
    ss << "PLAC Tunnel " << getSpot().x << " " << getSpot().y << " " << getTeam() << " ~";
    return ss.str();  
  }
  else
    return Bishop::Move(newpos);

}

void WBishop::wurmSpots(vector<coord> &spots, Chess* c)
{
  for(int i=0;i<14;i++)
    for(int j=0;j<14;j++){
      if(c->terrain[i][j] == 1)
      {
	Piece* dummy = new Bishop(i*64,j*64,getNum());
	dummy->setTeam(getTeam()-1);
	cerr << "My team:" << getTeam();
	cerr << "Dummy team:" << dummy->getTeam()-1;
	vector<coord> newstuff = dummy->validSpots(c);
	captureMap.insert(dummy->captureMap.begin(), dummy->captureMap.end());
	spots.insert(spots.end(), newstuff.begin(), newstuff.end());
	delete dummy;
      }
    }

}

vector<coord> WBishop:: validSpots(Chess* c)
{
 //c->board
  stringstream ss;
  coord seek;
  vector<coord> spots;

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
    if(c->terrain[seek.x][seek.y] == 1)
      wurmSpots(spots, c);
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
	captureMap[seek] = ss.str();
        break;
      }
      else
	break;
    }
    if(c->terrain[seek.x][seek.y] == 1)
      wurmSpots(spots, c);
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
    if(c->terrain[seek.x][seek.y] == 1)
      wurmSpots(spots, c);
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
    if(c->terrain[seek.x][seek.y] == 1)
      wurmSpots(spots, c);
    spots.push_back(seek);
  }
  return spots;

}
