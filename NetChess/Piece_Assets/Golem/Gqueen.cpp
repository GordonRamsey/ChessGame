#include "Gqueen.h"
using namespace std;

GQueen::GQueen(int x, int y, int it) : Queen(x, y, it)
{
    debug_name = "Gqueen";
    clicks = 0;
}

GQueen::~GQueen()
{}

string GQueen::Move(coord newpos)
{
    return Queen::Move(newpos);
}

vector<coord> GQueen::validSpots(Chess* c)
{
    if(rock){   
      vector<coord> empty;
      return empty;
    }
    if(m_level)
    {
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
	  else if(c->board[seek.x][seek.y]->isRock() == true)
	    continue;
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
	  else if(c->board[seek.x][seek.y]->isRock() == true)
	    continue;
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
	  else if(c->board[seek.x][seek.y]->isRock() == true)
	    continue;
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
	    captureMap[seek] = ss.str();

	    break;
	  }
	  else if(c->board[seek.x][seek.y]->isRock() == true)
	    continue;
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
	  else if(c->board[seek.x][seek.y]->isRock() == true)
	    continue;
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
	  else if(c->board[seek.x][seek.y]->isRock() == true)
	    continue;
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
	  else if(c->board[seek.x][seek.y]->isRock() == true)
	    continue;
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
	  else if(c->board[seek.x][seek.y]->isRock() == true)
	    continue;
	  else
	    break;
	}
	spots.push_back(seek);
      }
      return spots;
    }//If- Level up
    else
      return Queen::validSpots(c);
}

string GQueen::processClicks(vector<coord> clickedOn, Chess* c)
{
  if(clickedOn.size() != 1)
    return "ERROR";

  if(clickedOn[0] == getPos())
  {
    if(isRock())
    {
      stringstream ss;
      ss.str("");
      ss << "MOVE " << getNum() << " " << getPos().x << " " << getPos().y << " ~";
      ss << "ROCK " << getNum() << " ~";
      clicks = 0;

      return ss.str();
    }
  }
  return "DEFAULT";
}

