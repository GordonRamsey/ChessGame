#include "bishop.h"

Bishop::Bishop(int x, int y, int it) : Piece(x, y, it)
{
  debug_name = "bishop";
}

Bishop::~Bishop()
{

}

string Bishop::Move(coord newpos)
{
  return "DEFAULT";
}

/*string Bishop::processClicks(vector<coord> clickedOn, Chess* c)
{
    stringstream ss;
    ss.str("");
    
    if(clickedOn.size() != 1)
        return "ERROR";

    //Need to validate spots before acting on them
    if(c->board[clickedOn[0].x/64][clickedOn[0].y/64]->getNum();
        return "ERROR";

    int num = c->board[clickedOn[0].x/64][clickedOn[0].y/64]->getNum();

    //Are we clicking on ourself?
    if(num == getNum())
        return "ERROR";

    //Everything checks out, fashion a command to make the move
    ss << "MOVE " << c->board[getSpot().x][getSpot.y]->getNum() << " " << clickedOn[0].x << " " << clickedOn[0].y << " ~";
    ss << "REMV " << num << " ~";

    return ss.str();
}
*/

vector<coord> Bishop::validSpots(Chess* c)
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
