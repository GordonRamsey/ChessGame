#include "Wpawn.h"

WPawn::WPawn(int x, int y, int it, char dir) : Pawn(x, y, it, dir)
{
  debug_name = "Wpawn";
}

WPawn::~WPawn()
{}

void WPawn::wurmSpots(vector<coord> &spots, Chess* c)
{
  for(int i=0;i<14;i++)
    for(int j=0;j<14;j++){
      if(c->terrain[i][j] == 1)
      {
	Piece* dummy = new Pawn(i*64,j*64,getNum(),getdir());
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

string WPawn::Move(coord newpos)
{
  return Pawn::Move(newpos);
}

vector<coord> WPawn::validSpots(Chess* c)
{

  stringstream ss;

  //c->board
  vector<coord> spots;

  //North - cant cap
  coord seek = getSpot();
  if(dir != 'S')
    if(c->isValid(seek.x,seek.y-1))
    {
      seek.y--;
      if(c->board[seek.x][seek.y] == NULL)
      {
	if(c->terrain[seek.x][seek.y] == 1)
	  wurmSpots(spots,c);
	spots.push_back(seek); 
      }
    }
  //NW - can cap
  seek = getSpot();
  if(dir != 'S' && dir != 'E')
    if(c->isValid(seek.x-1,seek.y-1))
    {
      seek.y--;
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
      {
	if(c->terrain[seek.x][seek.y] == 1)
	  wurmSpots(spots,c);
      }
    }
  //NE - can cap
  seek = getSpot();
  if(dir != 'S' && dir != 'W')
    if(c->isValid(seek.x+1,seek.y-1))
    {
      seek.y--;
      seek.x++;
      if(c->board[seek.x][seek.y] != NULL){
	if(c->board[seek.x][seek.y]->getTeam() != getTeam()){	
	  spots.push_back(seek);
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	  captureMap[seek] = ss.str();
	}
      }
      else{
	if(c->terrain[seek.x][seek.y] == 1)
	  wurmSpots(spots,c);
      }
    }
  //S - cant cap
  seek = getSpot();
  if(dir != 'N')
    if(c->isValid(seek.x,seek.y+1))
    {
      seek.y++;
      if(c->board[seek.x][seek.y] == NULL)
      {	
	if(c->terrain[seek.x][seek.y] == 1)
	  wurmSpots(spots,c);
	spots.push_back(seek); 
      }
    }
  //SE - can cap
  seek = getSpot();
  if(dir != 'N' && dir != 'W')
    if(c->isValid(seek.x+1,seek.y+1))
    {
      seek.y++;
      seek.x++;
      if(c->board[seek.x][seek.y] != NULL){
	if(c->board[seek.x][seek.y]->getTeam() != getTeam()){	
	  spots.push_back(seek); 
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	  captureMap[seek] = ss.str();
	}
      }
      else{
	if(c->terrain[seek.x][seek.y] == 1)
	  wurmSpots(spots,c);
      }
    }
  //SW - can cap
  seek = getSpot();
  if(dir != 'N' && dir != 'E')
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
      else{
	if(c->terrain[seek.x][seek.y] == 1)
	  wurmSpots(spots,c);
      }
    } 
  //E - cant cap
  seek = getSpot();
  if(dir != 'W')
    if(c->isValid(seek.x+1,seek.y))
    {
      seek.x++;
      if(c->board[seek.x][seek.y] == NULL)
      {
	if(c->terrain[seek.x][seek.y] == 1)
	  wurmSpots(spots,c);
	spots.push_back(seek); 
      }
    }
  //W - cant cap
  seek = getSpot();
  if(dir != 'E')
    if(c->isValid(seek.x-1,seek.y))
    {
      seek.x--;
      if(c->board[seek.x][seek.y] == NULL)
      {
	if(c->terrain[seek.x][seek.y] == 1)
	  wurmSpots(spots,c);
	spots.push_back(seek); 
      }
    }
  //If first turn
  seek = getSpot();
  if(first_move)
  {
    if(dir == 'N'){
      seek.y -= 2;
      if(c->board[seek.x][seek.y] == NULL && c->board[seek.x][seek.y+1] == NULL)
      {
	if(c->terrain[seek.x][seek.y] == 1)
	  wurmSpots(spots,c);
	spots.push_back(seek);
      }
    }
    if(dir == 'S'){
      seek.y += 2;
      if(c->board[seek.x][seek.y] == NULL && c->board[seek.x][seek.y-1] == NULL)
      {
	if(c->terrain[seek.x][seek.y] == 1)
	  wurmSpots(spots,c);
	spots.push_back(seek);
      }
    }
    if(dir == 'E'){
      seek.x += 2;
      if(c->board[seek.x][seek.y] == NULL && c->board[seek.x-1][seek.y] == NULL)
      {
	if(c->terrain[seek.x][seek.y] == 1)
	  wurmSpots(spots,c);
	spots.push_back(seek);
      }
    }
    if(dir == 'W'){
      seek.x -= 2;
      if(c->board[seek.x][seek.y] == NULL && c->board[seek.x+1][seek.y] == NULL)
      {
	if(c->terrain[seek.x][seek.y] == 1)
	  wurmSpots(spots,c);
	spots.push_back(seek);
      }
    }
  }
  return spots;

}
