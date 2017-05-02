#include "Wknight.h"

WKnight::WKnight(int x, int y, int it) : Knight(x, y, it)
{
  debug_name = "Wknight";
}

WKnight::~WKnight()
{

}

string WKnight::checkAdjacent(coord spot, Chess* c)
{
  stringstream result;
  stringstream ss;
  
  //Check North
  coord tmp = spot; ss.str("");
  tmp.y--;
  if(c->isValid(tmp.x,tmp.y))
    if(c->board[tmp.x][tmp.y] != NULL)
    {
      //Check behind it
      tmp.y--;
      if(c->isValid(tmp.x,tmp.y))
	if(c->board[tmp.x][tmp.y] == NULL){
	  ss << "SHOV " << c->board[tmp.x][tmp.y+1]->getNum() << " " << tmp.x << " " << tmp.y << " ~";
	  result.str(result.str() + ss.str());
	}
    }

  //Check South
  tmp = spot; ss.str("");
  tmp.y++;
  if(c->isValid(tmp.x,tmp.y))
    if(c->board[tmp.x][tmp.y] != NULL)
    {
      //Check behind it
      tmp.y++;
      if(c->isValid(tmp.x,tmp.y))
	if(c->board[tmp.x][tmp.y] == NULL){
	  ss << "SHOV " << c->board[tmp.x][tmp.y-1]->getNum() << " " << tmp.x << " " << tmp.y << " ~";
	  result.str(result.str() + ss.str());
	}
    }

  //Check East
  tmp = spot; ss.str("");
  tmp.x++;
  if(c->isValid(tmp.x,tmp.y))
    if(c->board[tmp.x][tmp.y] != NULL)
    {
      //Check behind it
      tmp.x++;
      if(c->isValid(tmp.x,tmp.y))
	if(c->board[tmp.x][tmp.y] == NULL){
	  ss << "SHOV " << c->board[tmp.x-1][tmp.y]->getNum() << " " << tmp.x << " " << tmp.y << " ~";
	  result.str(result.str() + ss.str());
	}
    }
  //Check West
  tmp = spot; ss.str("");
  tmp.x--;
  if(c->isValid(tmp.x,tmp.y))
    if(c->board[tmp.x][tmp.y] != NULL)
    {
      //Check behind it
      tmp.x--;
      if(c->isValid(tmp.x,tmp.y))
	if(c->board[tmp.x][tmp.y] == NULL){
	  ss << "SHOV " << c->board[tmp.x+1][tmp.y]->getNum() << " " << tmp.x << " " << tmp.y << " ~";
	  result.str(result.str() + ss.str());
	}
    }

  return result.str();

}

void WKnight::wurmSpots(vector<coord> &spots, Chess* c)
{
  for(int i=0;i<14;i++)
    for(int j=0;j<14;j++){
      if(c->terrain[i][j] == 1)
      {
	Piece* dummy = new Knight(i*64,j*64,getNum());
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

string WKnight::Move(coord newpos)
{
  if(m_level)
  {

    string result = checkAdjacent(newpos,priv_c);
    if(result == "")
      return "DEFAULT";
    else
      return result;
  }
  else
    return "DEFAULT";
}


vector<coord> WKnight::validSpots(Chess* c)
{
  priv_c = c;

  if(!m_level)
    return Knight::validSpots(c);

  coord seek;
  vector<coord> spots;
  stringstream ss;

  //Check North/West
  seek = getSpot();
  seek.y-=2;
  seek.x-=1;
  if(seek.x >= 0 && seek.y >= 0) //Checks boundaries
  {
    if(c->validspots[seek.x][seek.y] != 0) //Checks if valid spot
    {
      if(c->board[seek.x][seek.y] != NULL) //Checks for a piece
      {
	if(c->board[seek.x][seek.y]->getTeam() != getTeam()) //Checks for enemy piece
	{
	  spots.push_back(seek); //Add as a valid spot
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~"; //Add the capture protocol to the capture map

	  captureMap[seek] = ss.str(); //Put the CAPT and REMV protocol into the captureMap
	}
      }
      else
      {
	if(c->terrain[seek.x][seek.y] == 1)
	  wurmSpots(spots,c);
	spots.push_back(seek); //Empty spot, add it
      }
    }
  } //This process is repeated 7 more times following this section, each in a unique direction

  //Check North/East
  seek = getSpot();
  seek.y-=2;
  seek.x+=1;
  if(seek.y >= 0 && seek.x <= 13)
  {
    if(c->validspots[seek.x][seek.y] != 0)
    {
      if(c->board[seek.x][seek.y] != NULL)
      {
	if(c->board[seek.x][seek.y]->getTeam() != getTeam())
	{
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
  }

  //Check East/Norh
  seek = getSpot();
  seek.x+=2;
  seek.y-=1;
  if(seek.x <= 13 && seek.y >= 0)
  {
    if(c->validspots[seek.x][seek.y] != 0)
    {
      if(c->board[seek.x][seek.y] != NULL)
      {
	if(c->board[seek.x][seek.y]->getTeam() != getTeam())
	{
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
  }

  //Check East/South
  seek = getSpot();
  seek.x+=2;
  seek.y+=1;
  if(seek.x <= 13 && seek.y <= 13)
  {
    if(c->validspots[seek.x][seek.y] != 0)
    {
      if(c->board[seek.x][seek.y] != NULL)
      {
	if(c->board[seek.x][seek.y]->getTeam() != getTeam())
	{
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
  }

  //Check South/East
  seek = getSpot();
  seek.y+=2;
  seek.x+=1;
  if(seek.x <= 13 && seek.y <= 13)
  {
    if(c->validspots[seek.x][seek.y] != 0)
    {
      if(c->board[seek.x][seek.y] != NULL)
      {
	if(c->board[seek.x][seek.y]->getTeam() != getTeam())
	{
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
  }

  //Check South/West
  seek = getSpot();
  seek.y+=2;
  seek.x-=1;
  if(seek.x >= 0 && seek.y <= 13)
  {
    if(c->validspots[seek.x][seek.y] != 0)
    {
      if(c->board[seek.x][seek.y] != NULL)
      {
	if(c->board[seek.x][seek.y]->getTeam() != getTeam())
	{
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
  }

  //Check West/North
  seek = getSpot();
  seek.x-=2;
  seek.y-=1;
  if(seek.x <= 0 && seek.y <= 0)
  {
    if(c->validspots[seek.x][seek.y] != 0)
    {
      if(c->board[seek.x][seek.y] != NULL)
      {
	if(c->board[seek.x][seek.y]->getTeam() != getTeam())
	{
	  spots.push_back(seek);
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";

	  captureMap[seek] = ss.str();
	}
      }
    }
    else
    {
      if(c->terrain[seek.x][seek.y] == 1)
	wurmSpots(spots,c);
      spots.push_back(seek);
    }
  }

  //Check West/South
  seek = getSpot();
  seek.x-=2;
  seek.y+=1;
  if(seek.x >= 0 && seek.x <= 13)
  {
    if(c->validspots[seek.x][seek.y] != 0)
    {
      if(c->board[seek.x][seek.y] != NULL)
      {
	if(c->board[seek.x][seek.y]->getTeam() != getTeam())
	{
	  spots.push_back(seek);
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";

	  captureMap[seek] = ss.str();
	}
      }
    }
    else
    {
      if(c->terrain[seek.x][seek.y] == 1)
	wurmSpots(spots,c);
      spots.push_back(seek);
    }
  }
  return spots;

}
