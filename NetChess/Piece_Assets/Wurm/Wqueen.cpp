#include "Wqueen.h"

WQueen::WQueen(int x, int y, int it) : Queen(x, y, it)
{
	debug_name = "Wqueen";
}

WQueen::~WQueen()
{}

string WQueen::Move(coord newpos)
{
	return Queen::Move(newpos);
}

string WQueen::processClicks(vector<coord> clickedOn, Chess* c)
{
  stringstream ss;
  if(clickedOn.size() != 1)
    return "ERROR";

  int x = clickedOn[0].x/64;
  int y = clickedOn[0].y/64;

  if(c->board[x][y] != NULL)
    return "ERROR";

  ss << "PLAC Tunnel " << x << " " << y << " " << getTeam() << " ~";
  return ss.str();
}

void WQueen::wurmSpots(vector<coord> &spots, Chess* c)
{
  for(int i=0;i<14;i++)
    for(int j=0;j<14;j++){
      if(c->terrain[i][j] == 1)
      {

	Piece* dummy = new Queen(i*64,j*64,getNum());
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

vector<coord> WQueen::validSpots(Chess* c)
{

  //c->board
  coord seek;
  vector<coord> spots;
  stringstream ss;
  pair <map<coord,string>::iterator,bool> debug;

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
    if(c->terrain[seek.x][seek.y] == 1)
      wurmSpots(spots,c);
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
    if(c->terrain[seek.x][seek.y] == 1)
      wurmSpots(spots,c);
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
    if(c->terrain[seek.x][seek.y] == 1)
      wurmSpots(spots,c);
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
      wurmSpots(spots,c);
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
    if(c->terrain[seek.x][seek.y] == 1)
      wurmSpots(spots,c);
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
      wurmSpots(spots,c);
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
    if(c->terrain[seek.x][seek.y] == 1)
      wurmSpots(spots,c);
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
      wurmSpots(spots,c);
    spots.push_back(seek);
  }
  return spots;

}
