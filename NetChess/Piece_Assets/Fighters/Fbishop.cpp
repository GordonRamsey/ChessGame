#include "Fbishop.h"

FBishop::FBishop(int x, int y, int it) : Bishop(x, y, it)
{
	m_level = false;
	debug_name = "fbishop";
}

FBishop::~FBishop()
{}

string FBishop::Move(coord newpos)
{
	stringstream ss;
	ss << "MOVE " << newpos.x << "," << newpos.y << endl;
	return ss.str();
}

vector<coord> FBishop::validSpots(Chess* c)
{
	stringstream ss;
	coord seek;
	if(!m_level)
		return Bishop::validSpots(c);

	vector<coord> spots(Bishop::validSpots(c));

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
  return spots;
}
  
