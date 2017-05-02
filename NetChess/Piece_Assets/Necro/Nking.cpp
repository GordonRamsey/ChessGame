#include "Nking.h"
using namespace std;

NKing::NKing(int x, int y, int it) : King(x, y, it)
{
    debug_name = "Nking";
}

NKing::~NKing()
{}

string NKing::Move(coord newpos)
{
  return King::Move(newpos);
}

vector<coord> NKing::validSpots(Chess* c)
{
  return King::validSpots(c);
}
vector<coord> NKing::validSLoc(Chess* c)
{
  coord seek; 
  coord spot; 
  vector<coord>validSpot; 
  seek = getSpot(); 
  //up
  spot.x = seek.x; 
  spot.y = seek.y-1; 
  if((spot.y >= 0) && (c->validspots[spot.x][spot.y] != 0))
    validSpot.push_back(spot); 
  //down
  spot.x = seek.x; 
  spot.y = seek.y+1; 
  if((spot.y < 14) && (c->validspots[spot.x][spot.y] != 0))
    validSpot.push_back(spot);
  //left
  spot.x = seek.x-1; 
  spot.y = seek.y; 
  if((spot.x >= 0) && (c->validspots[spot.x][spot.y] != 0))
    validSpot.push_back(spot);
  //right
  spot.x = seek.x+1; 
  spot.y = seek.y; 
  if((spot.x < 14) && (c->validspots[spot.x][spot.y] != 0))
    validSpot.push_back(spot);
  //top left
  spot.x = seek.x-1; 
  spot.y = seek.y-1; 
  if(spot.x >= 0 && spot.y >= 0 && (c->validspots[spot.x][spot.y] != 0))
    validSpot.push_back(spot);   
  //top right
  spot.x = seek.x+1; 
  spot.y = seek.y-1; 
  if(spot.x < 14 && spot.y >= 0 && (c->validspots[spot.x][spot.y] != 0))
    validSpot.push_back(spot);
  //bottom left
  spot.x = seek.x-1; 
  spot.y = seek.y+1; 
  if(spot.y < 14 && spot.x >= 0 && (c->validspots[spot.x][spot.y] != 0))
    validSpot.push_back(spot);
  //bottom right
  spot.x = seek.x+1; 
  spot.y = seek.y+1; 
  if(spot.x < 14 && spot.y < 14 && (c->validspots[spot.x][spot.y] != 0))
    validSpot.push_back(spot);

  for(int i=0;i<14;i++)
    for(int j=0;j<14;j++)
      if(c->board[i][j]->debug_name == "Nrook")
	if(c->board[i][j]->isLevel()){
	  coord dad; dad.x = i; dad.y = j;


	}

    


  return validSpot; 
}

bool NKing::isValid(vector<coord> validSLoc, coord click, Chess* c)
{

  click.x = click.x/64;
  click.y = click.y/64;
  for(unsigned int j = 0; j < validSLoc.size(); ++j){
    if(click == validSLoc[j])
      return true; 
  }

  return false; 
}

string NKing::processClicks(vector<coord> clickedOn, Chess* c)
{

  stringstream ss; 
  if(clickedOn.size() != 3)
    return "ERROR"; 

  if(c->board[clickedOn[0].x/64][clickedOn[0].y/64] != NULL)
    return "ERROR";
  if(c->board[clickedOn[1].x/64][clickedOn[1].y/64] != NULL)
    if(c->board[clickedOn[1].x/64][clickedOn[1].y/64]->getNum() != getNum())
      return "ERROR";
  if(c->board[clickedOn[2].x/64][clickedOn[2].y/64] != NULL)
    if(c->board[clickedOn[2].x/64][clickedOn[2].y/64]->getNum() != getNum())
      return "ERROR";

  vector<coord> tmp(validSLoc(c));  
  int count = 0;
  if(isValid(tmp, clickedOn[0], c))
  {
    count++;
    if(isValid(tmp, clickedOn[1], c))
    {
      count++;
      if(isValid(tmp,clickedOn[2],c))
	count++;
    }
  }
  ss.str(""); 
  ss << "MOVE " << getNum() << " " << getPos().x << " " <<  getPos().y << " ~"; 
  for(int i = 0; i < count; ++i){
    ss << "PLAC Npawn " << " " << clickedOn[i].x/64 << " " << clickedOn[i].y/64 << " " << getTeam()-1 << " ~"; 
  }
  return ss.str(); 


  return "DEFAULT"; 
}
