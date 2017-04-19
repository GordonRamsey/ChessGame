#include "Fpawn.h"

FPawn::FPawn(int x, int y, int it, char state) : Pawn(x, y, it, state)
{
  debug_name = "Fpawn";
  m_level = true;
}

FPawn::~FPawn()
{}

string FPawn::Move(coord newpos)
{
  return Pawn::Move(newpos);
}

vector<coord> FPawn::validSpots(Chess* c)
{
  //TODO: Use original pawn movement function
  
  stringstream ss;
  coord seek;
  seek = getSpot();
  
  vector<coord> spots(Pawn::validSpots(c));
  
  if(dir == 'N') //Starting Cardinal direction is North... SO PLAYER 2 PAWNS
  {
    //Check forward 1
    if(c->isValid(seek.x, seek.y-1))
    {
      seek.y--;
      if(c->board[seek.x][seek.y] == NULL)
	spots.push_back(seek);
    }
    //Check forward 2 if first_move
    if(first_move)
    {
      seek.y--;
      if(c->board[seek.x][seek.y] == NULL)
	spots.push_back(seek);
    }
    seek = getSpot();
    //Check NW for capture
    if(c->isValid(seek.x-1, seek.y-1))
    {
      seek.x--;
      seek.y--;
      if(c->board[seek.x][seek.y] != NULL)
      {
	if(getTeam() != c->board[seek.x][seek.y]->getTeam())
	{
	  spots.push_back(seek);
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	  captureMap[seek] = ss.str();

	  //Check NW again for capture
	  if(c->isValid(seek.x-1, seek.y-1))
	  {
	    if(c->board[seek.x-1][seek.y-1] != NULL)
	    {
	      if(getTeam() != c->board[seek.x-1][seek.y-1]->getTeam())
	      {
		seek.x--;
		seek.y--;
		spots.push_back(seek);
		ss.str("");
		ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
		ss << "REMV " << c->board[seek.x+1][seek.y+1]->getNum() << " ~";
		seek.x++;
		seek.y++;
	      }
	    }
	  }
	  //Check NE again for capture
	  if(c->isValid(seek.x+1, seek.y-1))
	  {
	    if(c->board[seek.x+1][seek.y-1] != NULL)
	    {
	      if(getTeam() != c->board[seek.x+1][seek.y-1]->getTeam())
	      {
		seek.x++;
		seek.y--;
		spots.push_back(seek);
		ss.str("");
		ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
		ss << "REMV " << c->board[seek.x-1][seek.y+1]->getNum() << " ~";
		seek.x--;
		seek.y++;
	      }
	    }
	  }
	}
      } 
    }
    seek = getSpot();
    //Checking NE for capture
    if(c->isValid(seek.x+1, seek.y-1))
    {
      seek.x++;
      seek.y--;
      if(c->board[seek.x][seek.y] != NULL)
      {
	if(getTeam() != c->board[seek.x][seek.y]->getTeam())
	{
	  spots.push_back(seek);
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	  captureMap[seek] = ss.str();

	  //Check NW again for capture
	  if(c->isValid(seek.x-1, seek.y-1))
	  {
	    if(c->board[seek.x-1][seek.y-1] != NULL)
	    {
	      if(getTeam() != c->board[seek.x-1][seek.y-1]->getTeam())
	      {
		seek.x--;
		seek.y--;
		spots.push_back(seek);
		ss.str("");
		ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
		ss << "REMV " << c->board[seek.x+1][seek.y+1]->getNum() << " ~";
		seek.x++;
		seek.y++;
	      }
	    }
	  }
	  //Check NE again for capture
	  if(c->isValid(seek.x+1, seek.y-1))
	  {
	    if(c->board[seek.x+1][seek.y-1] != NULL)
	    {
	      if(getTeam() != c->board[seek.x+1][seek.y-1]->getTeam())
	      {
		seek.x++;
		seek.y--;
		spots.push_back(seek);
		ss.str("");
		ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
		ss << "REMV " << c->board[seek.x-1][seek.y+1]->getNum() << " ~";
		seek.x--;
		seek.y++;
	      }
	    }
	  }
	}
      }
    }
  }
  if(dir == 'S') //Starting Cardinal direction is South... SO PLAYER 1 PAWNS
  {
    //Check forward 1
    if(c->isValid(seek.x, seek.y+1))
    {
      seek.y++;
      if(c->board[seek.x][seek.y] == NULL)
	spots.push_back(seek);
    }
    //Check forward 2 if first_move
    if(first_move)
    {
      seek.y++;
      if(c->board[seek.x][seek.y] == NULL)
	spots.push_back(seek);
    }
    seek = getSpot();
    //Check SW for capture
    if(c->isValid(seek.x-1, seek.y+1))
    {
      seek.x--;
      seek.y++;
      if(c->board[seek.x][seek.y] != NULL)
      {
	if(getTeam() != c->board[seek.x][seek.y]->getTeam())
	{
	  spots.push_back(seek);
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	  captureMap[seek] = ss.str();

	  //Check SW again for capture
	  if(c->isValid(seek.x-1, seek.y+1))
	  {
	    if(c->board[seek.x-1][seek.y+1] != NULL)
	    {
	      if(getTeam() != c->board[seek.x-1][seek.y+1]->getTeam())
	      {
		seek.x--;
		seek.y++;
		spots.push_back(seek);
		ss.str("");
		ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
		ss << "REMV " << c->board[seek.x+1][seek.y-1]->getNum() << " ~";
		seek.x++;
		seek.y--;
	      }
	    }
	  }
	  //Check SE again for capture
	  if(c->isValid(seek.x+1, seek.y+1))
	  {
	    if(c->board[seek.x+1][seek.y+1] != NULL)
	    {
	      if(getTeam() != c->board[seek.x+1][seek.y+1]->getTeam())
	      {
		seek.x++;
		seek.y++;
		spots.push_back(seek);
		ss.str("");
		ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
		ss << "REMV " << c->board[seek.x+1][seek.y+1]->getNum() << " ~";
		seek.x++;
		seek.y++;
	      }
	    }
	  }
	}
      } 
    }
    seek = getSpot();
    //Check SE for capture
    if(c->isValid(seek.x+1, seek.y+1))
    {
      seek.x++;
      seek.y++;
      if(c->board[seek.x][seek.y] != NULL)
      {
	if(getTeam() != c->board[seek.x][seek.y]->getTeam())
	{
	  spots.push_back(seek);
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	  captureMap[seek] = ss.str();

	  //Check SW again for capture
	  if(c->isValid(seek.x-1, seek.y+1))
	  {
	    if(c->board[seek.x-1][seek.y+1] != NULL)
	    {
	      if(getTeam() != c->board[seek.x-1][seek.y+1]->getTeam())
	      {
		seek.x--;
		seek.y++;
		spots.push_back(seek);
		ss.str("");
		ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
		ss << "REMV " << c->board[seek.x+1][seek.y-1]->getNum() << " ~";
		seek.x++;
		seek.y--;
	      }
	    }
	  }
	  //Check SE again for capture
	  if(c->isValid(seek.x+1, seek.y+1))
	  {
	    if(c->board[seek.x+1][seek.y+1] != NULL)
	    {
	      if(getTeam() != c->board[seek.x+1][seek.y+1]->getTeam())
	      {
		seek.x++;
		seek.y++;
		spots.push_back(seek);
		ss.str("");
		ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
		ss << "REMV " << c->board[seek.x+1][seek.y+1]->getNum() << " ~";
		seek.x++;
		seek.y++;
	      }
	    }
	  }
	}
      } 
    }
  } 

  if(dir == 'W') //Starting Cardinal direction is West... SO PLAYER 3 PAWNS
  {
    //Check forward 1
    if(c->isValid(seek.x-1, seek.y))
    {
      seek.x--;
      if(c->board[seek.x][seek.y] == NULL)
	spots.push_back(seek);
    }
    //Check forward 2 if first_move
    if(first_move)
    {
      seek.x--;
      if(c->board[seek.x][seek.y] == NULL)
	spots.push_back(seek);
    }
    seek = getSpot();
    //Check NW for capture
    if(c->isValid(seek.x-1, seek.y-1))
    {
      seek.x--;
      seek.y--;
      if(c->board[seek.x][seek.y] != NULL)
      {
	if(getTeam() != c->board[seek.x][seek.y]->getTeam())
	{
	  spots.push_back(seek);
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	  captureMap[seek] = ss.str();

	  //Check NW again for capture
	  if(c->isValid(seek.x-1, seek.y-1))
	  {
	    if(c->board[seek.x-1][seek.y-1] != NULL)
	    {
	      if(getTeam() != c->board[seek.x-1][seek.y-1]->getTeam())
	      {
		seek.x--;
		seek.y--;
		spots.push_back(seek);
		ss.str("");
		ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
		ss << "REMV " << c->board[seek.x+1][seek.y+1]->getNum() << " ~";
		seek.x++;
		seek.y++;
	      }
	    }
	  }
	  //Check SW again for capture
	  if(c->isValid(seek.x-1, seek.y+1))
	  {
	    if(c->board[seek.x-1][seek.y+1] != NULL)
	    {
	      if(getTeam() != c->board[seek.x-1][seek.y+1]->getTeam())
	      {
		seek.x--;
		seek.y++;
		spots.push_back(seek);
		ss.str("");
		ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
		ss << "REMV " << c->board[seek.x+1][seek.y-1]->getNum() << " ~";
		seek.x++;
		seek.y--;
	      }
	    }
	  } 
	}
      }
    }
    seek = getSpot();
    //Check SW for capture
    if(c->isValid(seek.x-1, seek.y+1))
    {
      seek.x--;
      seek.y++;
      if(c->board[seek.x][seek.y] != NULL)
      {
	if(getTeam() != c->board[seek.x][seek.y]->getTeam())
	{
	  spots.push_back(seek);
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	  captureMap[seek] = ss.str();

	  //Check NW again for capture
	  if(c->isValid(seek.x-1, seek.y-1))
	  {
	    if(c->board[seek.x-1][seek.y-1] != NULL)
	    {
	      if(getTeam() != c->board[seek.x-1][seek.y-1]->getTeam())
	      {
		seek.x--;
		seek.y--;
		spots.push_back(seek);
		ss.str("");
		ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
		ss << "REMV " << c->board[seek.x+1][seek.y+1]->getNum() << " ~";
		seek.x++;
		seek.y++;
	      }
	    }
	  }
	  //Check SW again for capture
	  if(c->isValid(seek.x-1, seek.y+1))
	  {
	    if(c->board[seek.x-1][seek.y+1] != NULL)
	    {
	      if(getTeam() != c->board[seek.x-1][seek.y+1]->getTeam())
	      {
		seek.x--;
		seek.y++;
		spots.push_back(seek);
		ss.str("");
		ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
		ss << "REMV " << c->board[seek.x+1][seek.y-1]->getNum() << " ~";
		seek.x++;
		seek.y--;
	      }
	    }
	  } 
	}
      }
    }
  }

  if(dir == 'E') //Starting Cardinal direction is Eest... SO PLAYER 4 PAWNS
  {
    //Check forward 1
    if(c->isValid(seek.x+1, seek.y))
    {
      seek.x++;
      if(c->board[seek.x][seek.y] == NULL)
	spots.push_back(seek);
    }
    //Check forward 2 if first_move
    if(first_move)
    {
      seek.x++;
      if(c->board[seek.x][seek.y] == NULL)
	spots.push_back(seek);
    }
    seek = getSpot();
    //Checking NE for capture
    if(c->isValid(seek.x+1, seek.y-1))
    {
      seek.x++;
      seek.y--;
      if(c->board[seek.x][seek.y] != NULL)
      {
	if(getTeam() != c->board[seek.x][seek.y]->getTeam())
	{
	  spots.push_back(seek);
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	  captureMap[seek] = ss.str();

	  //Check NE again for capture
	  if(c->isValid(seek.x+1, seek.y-1))
	  {
	    if(c->board[seek.x+1][seek.y-1] != NULL)
	    {
	      if(getTeam() != c->board[seek.x+1][seek.y-1]->getTeam())
	      {
		seek.x++;
		seek.y--;
		spots.push_back(seek);
		ss.str("");
		ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
		ss << "REMV " << c->board[seek.x-1][seek.y+1]->getNum() << " ~";
		seek.x--;
		seek.y++;
	      }
	    }
	  } 
	  //Check SE again for capture
	  if(c->isValid(seek.x+1, seek.y+1))
	  {
	    if(c->board[seek.x+1][seek.y+1] != NULL)
	    {
	      if(getTeam() != c->board[seek.x+1][seek.y+1]->getTeam())
	      {
		seek.x++;
		seek.y++;
		spots.push_back(seek);
		ss.str("");
		ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
		ss << "REMV " << c->board[seek.x+1][seek.y+1]->getNum() << " ~";
		seek.x++;
		seek.y++;
	      }
	    }
	  } 
	}
      }
    }
   seek = getSpot();
   //Check SE for capture
   if(c->isValid(seek.x+1, seek.y+1))
    {
      seek.x++;
      seek.y++;
      if(c->board[seek.x][seek.y] != NULL)
      {
	if(getTeam() != c->board[seek.x][seek.y]->getTeam())
	{
	  spots.push_back(seek);
	  ss.str("");
	  ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
	  captureMap[seek] = ss.str();
	   
	  //Check NE again for capture
	  if(c->isValid(seek.x+1, seek.y-1))
	  {
	    if(c->board[seek.x+1][seek.y-1] != NULL)
	    {
	      if(getTeam() != c->board[seek.x+1][seek.y-1]->getTeam())
	      {
		seek.x++;
		seek.y--;
		spots.push_back(seek);
		ss.str("");
		ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
		ss << "REMV " << c->board[seek.x-1][seek.y+1]->getNum() << " ~";
		seek.x--;
		seek.y++;
	      }
	    }
	  } 
	  //Check SE again for capture
	  if(c->isValid(seek.x+1, seek.y+1))
	  {
	    if(c->board[seek.x+1][seek.y+1] != NULL)
	    {
	      if(getTeam() != c->board[seek.x+1][seek.y+1]->getTeam())
	      {
		seek.x++;
		seek.y++;
		spots.push_back(seek);
		ss.str("");
		ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
		ss << "REMV " << c->board[seek.x+1][seek.y+1]->getNum() << " ~";
		seek.x++;
		seek.y++;
	      }
	    }
	  } 
	}  
      }
    }
  }
  return spots;
}
