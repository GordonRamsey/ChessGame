#include "Fknight.h"

FKnight::FKnight(int x, int y, int it) : Knight(x, y, it)
{
    debug_name = "Fknight";
}

FKnight::~FKnight()
{}

string FKnight::Move(coord newpos)
{
  return "DEFAULT";
}

vector<coord> FKnight::validSpots(Chess* c)
{   
  if(!m_level) //If we are still a basic piece, use the basic knight move validation
    return Knight::validSpots(c);
  //c->board
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
	  if((c->validspots[(seek.x)-1][seek.y] != 0) && (c->board[(seek.x)-1][seek.y] != NULL)) //Checks if the NEXT spot over in the attacking cardinal direction is valid and if there's a piece there
	  {
	    if(c->board[(seek.x)-1][seek.y]->getTeam() != getTeam()) //If it's an enemy piece add the REMV protocol to 'ss' which already has the CAPT protocol
	      ss << "REMV " << c->board[(seek.x)-1][seek.y]->getNum() << " ~";
	  }
	  captureMap[seek] = ss.str(); //Put the CAPT and REMV protocol into the captureMap
	}
      }
      else
      {
	spots.push_back(seek); //Empty spot, add it
	if((c->validspots[(seek.x)-1][seek.y] != 0) && (c->board[(seek.x)-1][seek.y] != NULL)) //Checks if the NEXT spot over in the moving cardinal direction is valid and if there's a piece there
	{
	  if(c->board[(seek.x)-1][seek.y]->getTeam() != getTeam()) //If it's an enemy piece, add the MOVE protocol and the REMV protocol to a stringstream
	  {
	    seek.x -= 1;
	    ss.str("");
	    ss << "MOVE " << getNum() << " " << ((seek.x)+1)*64 << " " << seek.y*64 << " ~"; //Always multiply the X and Y MOVE protocol coordinates by 64.
	    ss << "REMV " << c->board[seek.x][seek.y]->getNum() << " ~";
	    captureMap[seek] = ss.str(); //Put the MOVE and REMV protolcol into the captureMap
	  }
	}
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
	  if((c->validspots[(seek.x)+1][seek.y] != 0) && (c->board[(seek.x)+1][seek.y] != NULL))
	  {
	    if(c->board[(seek.x)+1][seek.y]->getTeam() != getTeam())
	      ss << "REMV " << c->board[(seek.x)+1][seek.y]->getNum() << " ~";
	  }
	  captureMap[seek] = ss.str();
	}
      }
      else
      {
	spots.push_back(seek);
	if((c->validspots[(seek.x)+1][seek.y] != 0) && (c->board[(seek.x)+1][seek.y] != NULL))
	{
	  if(c->board[(seek.x)+1][seek.y]->getTeam() != getTeam())
	  {
	    seek.x += 1;
	    ss.str("");
	    ss << "MOVE " << getNum() << " " << ((seek.x)-1)*64 << " " << seek.y*64 << " ~";
	    ss << "REMV " << c->board[seek.x][seek.y]->getNum() << " ~";
	    captureMap[seek] = ss.str();
	  }
	}
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
	  if((c->validspots[seek.x][seek.y-1] != 0) && (c->board[seek.x][seek.y-1] != NULL))
	  {
	    if(c->board[seek.x][seek.y-1]->getTeam() != getTeam())
	      ss << "REMV " << c->board[seek.x][seek.y-1]->getNum() << " ~";
	  }
	  captureMap[seek] = ss.str();
	}
      }
      else
      {
	spots.push_back(seek);
	if((c->validspots[seek.x][seek.y-1] != 0) && (c->board[seek.x][seek.y-1] != NULL))
	{
	  if(c->board[seek.x][seek.y-1]->getTeam() != getTeam())
	  {
	    seek.y -= 1;
	    ss.str("");
	    ss << "MOVE " << getNum() << " " << seek.x*64 << " " << (seek.y+1)*64 << " ~";
	    ss << "REMV " << c->board[seek.x][seek.y]->getNum() << " ~";
	    captureMap[seek] = ss.str();
	  }
	}
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
	  if((c->validspots[seek.x][seek.y+1] != 0) && (c->board[seek.x][seek.y+1] != NULL))
	  {
	    if(c->board[seek.x][seek.y+1]->getTeam() != getTeam())
	      ss << "REMV " << c->board[seek.x][seek.y+1]->getNum() << " ~";
	  }
	  captureMap[seek] = ss.str();
	}
      }
      else
      {
	spots.push_back(seek);
	if((c->validspots[seek.x][seek.y+1] != 0) && (c->board[seek.x][seek.y+1] != NULL))
	{
	  if(c->board[seek.x][seek.y+1]->getTeam() != getTeam())
	  {
	    seek.y += 1;
	    ss.str("");
	    ss << "MOVE " << getNum() << " " << seek.x*64 << " " << (seek.y-1)*64 << " ~";
	    ss << "REMV " << c->board[seek.x][seek.y]->getNum() << " ~";
	    captureMap[seek] = ss.str();
	  }
	}
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
	  if((c->validspots[seek.x+1][seek.y] != 0) && (c->board[seek.x+1][seek.y] != NULL))
	  {
	    if(c->board[seek.x+1][seek.y]->getTeam() != getTeam())
	      ss << "REMV " << c->board[seek.x+1][seek.y]->getNum() << " ~";
	  }
	  captureMap[seek] = ss.str();
	}
      }
      else
      {
	spots.push_back(seek);
	if((c->validspots[seek.x+1][seek.y] != 0) && (c->board[seek.x+1][seek.y] != NULL))
	{
	  if(c->board[seek.x+1][seek.y]->getTeam() != getTeam())
	  {
	    seek.x += 1;
	    ss.str("");
	    ss << "MOVE " << getNum() << " " << (seek.x-1)*64 << " " << seek.y*64 << " ~";
	    ss << "REMV " << c->board[seek.x][seek.y]->getNum() << " ~";
	    captureMap[seek] = ss.str();
	  }
	}
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
	  if((c->validspots[seek.x-1][seek.y] != 0) && (c->board[seek.x-1][seek.y] != NULL))
	  {
	    if(c->board[seek.x-1][seek.y]->getTeam() != getTeam())
	      ss << "REMV " << c->board[seek.x-1][seek.x]->getNum() << " ~";
	  }
	  captureMap[seek] = ss.str();
	}
      }
      else
      {
	spots.push_back(seek);
	if((c->validspots[seek.x-1][seek.y] != 0) && (c->board[seek.x-1][seek.y] != NULL))
	{
	  if(c->board[seek.x-1][seek.y]->getTeam() != getTeam())
	  {
	    seek.x -= 1;
	    ss.str("");
	    ss << "MOVE " << getNum() << " " << (seek.x+1)*64 << " " << seek.y*64 << " ~";
	    ss << "REMV " << c->board[seek.x][seek.y]->getNum() << " ~";
	    captureMap[seek] = ss.str();
	  }
	}
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
	  if((c->validspots[seek.x][seek.y-1] != 0) && (c->board[seek.x][seek.y-1] != NULL))
	  {
	    if(c->board[seek.x][seek.y-1]->getTeam() != getTeam())
	      ss << "REMV " << c->board[seek.x][seek.y-1]->getNum() << " ~";
	  }
	  captureMap[seek] = ss.str();
	}
      }
    }
    else
    {
      spots.push_back(seek);
      if((c->validspots[seek.x][seek.y-1] != 0) && (c->board[seek.x][seek.y-1] != NULL))
      {
	if(c->board[seek.x][seek.y] != NULL)
	{
	  if(c->board[seek.x][seek.y-1]->getTeam() != getTeam())
	  {
	    seek.y -= 1;
	    ss.str("");
	    ss << "MOVE " << getNum() << " " << seek.x*64 << " " << (seek.y+1)*64 << " ~";
	    ss << "REMV " << c->board[seek.x][seek.y]->getNum() << " ~";
	    captureMap[seek] = ss.str();
	  }
	}
      }
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
	  if((c->validspots[seek.x][seek.y+1] != 0) && (c->board[seek.x][seek.y+1] != NULL))
	  {
	    if(c->board[seek.x][seek.y+1]->getTeam() != getTeam())
	      ss << "REMV " << c->board[seek.x][seek.y+1]->getNum() << " ~";
	  }
	  captureMap[seek] = ss.str();
	}
      }
    }
    else
    {
      spots.push_back(seek);
      if((c->validspots[seek.x][seek.y+1] != 0) && (c->board[seek.x][seek.y+1] != NULL))
      {
	if(c->board[seek.x][seek.y+1]->getTeam() != getTeam())
	{
	  seek.y += 1;
	  ss.str("");
	  ss << "MOVE " << getNum() << " " << seek.x*64 << " " << (seek.y-1)*64 << " ~";
	  ss << "REMV " << c->board[seek.x][seek.y]->getNum() << " ~";
	}
      }
    }
  }
  return spots;
}
