#include "Wking.h"

WKing::WKing(int x, int y, int it) : King(x, y, it)
{
	debug_name = "Wking";
}

WKing::~WKing()
{}

string WKing::Move(coord newpos)
{
  return King::Move(newpos);
}

string WKing::processClicks(vector<coord> clickedOn, Chess* c)
{
  stringstream ss;
  if(clickedOn.size() != 1)
    return "ERROR";

  int x = clickedOn[0].x/64;
  int y = clickedOn[0].y/64;

  if(getSpot().x != x || getSpot().y != y)
    return "ERROR";

  ss.str(createCrater(getSpot(), c));

  return ss.str();

}

string WKing::createCrater(coord spot, Chess* c)
{
  stringstream ss;

  //Check North:
  if(c->board[spot.x][spot.y+1] != NULL)
    ss << "REMV " << c->board[spot.x][spot.y+1]->getNum() << " ~";
  if(c->board[spot.x][spot.y-1] != NULL)
    ss << "REMV " << c->board[spot.x][spot.y-1]->getNum() << " ~";
  if(c->board[spot.x+1][spot.y] != NULL)
    ss << "REMV " << c->board[spot.x+1][spot.y]->getNum() << " ~";
  if(c->board[spot.x+1][spot.y+1] != NULL)
    ss << "REMV " << c->board[spot.x+1][spot.y+1]->getNum() << " ~";
  if(c->board[spot.x+1][spot.y-1] != NULL)
    ss << "REMV " << c->board[spot.x+1][spot.y-1]->getNum() << " ~";
  if(c->board[spot.x-1][spot.y] != NULL)
    ss << "REMV " << c->board[spot.x-1][spot.y]->getNum() << " ~";
  if(c->board[spot.x-1][spot.y+1] != NULL)
    ss << "REMV " << c->board[spot.x-1][spot.y+1]->getNum() << " ~";
  if(c->board[spot.x-1][spot.y-1] != NULL)
    ss << "REMV " << c->board[spot.x-1][spot.y-1]->getNum() << " ~";
  ss << "PLAC Tunnel " << getSpot().x << " " << getSpot().y+1 << " -1 ~";	
  ss << "PLAC Tunnel " << getSpot().x << " " << getSpot().y-1 << " -1 ~";	
  ss << "PLAC Tunnel " << getSpot().x+1 << " " << getSpot().y << " -1 ~";	
  ss << "PLAC Tunnel " << getSpot().x+1 << " " << getSpot().y+1 << " -1 ~";	
  ss << "PLAC Tunnel " << getSpot().x+1 << " " << getSpot().y-1 << " -1 ~";	
  ss << "PLAC Tunnel " << getSpot().x-1 << " " << getSpot().y << " -1 ~";	
  ss << "PLAC Tunnel " << getSpot().x-1 << " " << getSpot().y+1 << " -1 ~";	
  ss << "PLAC Tunnel " << getSpot().x-1 << " " << getSpot().y-1 << " -1 ~";

  return ss.str();

}

void wurmSpots(vector<coord> &spots, Chess* c)
{
  for(int i=0;i<14;i++)
    for(int j=0;j<14;j++){
      if(c->terrain[i][j] == 1)
      {
	vector<coord> newstuff = King::validSpots(c);
	spots.insert(spots.end(), newstuff.begin(), newstuff.end());
      }
    }

}

vector<coord> WKing::validSpots(Chess* c)
{
 //c->board
  vector<coord> spots;
  stringstream ss;
  //North
  coord seek = getSpot();
  if(c->isValid(seek.x,seek.y-1))
  {
    seek.y--;
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
      spots.push_back(seek); 
    }
  }

  //North/East
  seek = getSpot();
  if(c->isValid(seek.x+1,seek.y-1))
  {
    seek.y--;
    seek.x++;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam())      {
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
      spots.push_back(seek); 
    }
  }

  //East
  seek = getSpot();
  if(c->isValid(seek.x+1,seek.y))
  {
    seek.x++;
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
      spots.push_back(seek); 
    }
  }

  //South/East
  seek = getSpot();
  if(c->isValid(seek.x+1,seek.y+1))
  {
    seek.x++;
    seek.y++;
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
      spots.push_back(seek); 
    }
  }

  //South
  seek = getSpot();
  if(c->isValid(seek.x,seek.y+1))
  {
    seek.y++;
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
      spots.push_back(seek); 
    }
  }

  //South/West
  seek = getSpot();
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
    else
    {  
      if(c->terrain[seek.x][seek.y] == 1)
	wurmSpots(spots,c);
      spots.push_back(seek); 
    }
  }

  //West
  seek = getSpot();
  if(c->isValid(seek.x-1,seek.y))
  {
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
      spots.push_back(seek); 
    }
  }

  //North/West
  seek = getSpot();
  if(c->isValid(seek.x-1,seek.y-1))
  {
    seek.x--;
    seek.y--;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
	spots.push_back(seek);
	ss.str("");
        ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	captureMap[seek] = ss.str();
      }
    }
    else
      spots.push_back(seek); 
  }
  return spots;


}
