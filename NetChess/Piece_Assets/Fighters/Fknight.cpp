#include "Fknight.h"

FKnight::FKnight(int x, int y, int it) : Knight(x, y, it)
{
    m_level = false;
    debug_name = "fknight";
}

FKnight::~FKnight()
{}

string FKnight::Move(coord newpos)
{
    stringstream ss;
    ss << "MOVE " << getNum() << " " << newpos.x*64 << " " << newpos.y*64 << " ~";
    return ss.str();
}

vector<coord> FKnight::validSpots(Chess* c)
{   
  if(!m_level)
    return Knight::validSpots(c);
  //c->board
  coord seek;
  vector<coord> spots;
  stringstream ss;

  //Check North/West
  seek = getSpot();
  seek.y-=2;
  seek.x-=1;
  if(seek.x >= 0 && seek.y >= 0)
  {
    if(c->validspots[seek.x][seek.y] != 0)//valid spot
    {
      if(c->board[seek.x][seek.y] != NULL)
      {
        if(c->board[seek.x][seek.y]->getTeam() != getTeam())
        {
          spots.push_back(seek);
	      ss.str("");
          ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
          if((c->validspots[(seek.x)-1][seek.y] != 0) && (c->board[(seek.x)-1][seek.y] != NULL))
          {
            if(c->board[(seek.x)-1][seek.y]->getTeam != getTeam())
              ss << "REMV " << c->board[(seek.x)-1][seek.y]->getNum() << " ~";
          }
	      captureMap[seek] = ss.str();
        }
      }
      else
      {
        spots.push_back(seek);
        if((c->validspots[(seek.x)-1][seek.y] != 0) && (c->board[(seek.x)-1][seek.y] != NULL))
        {
            if(c->board[(seek.x)-1][seek.y]->getTeam != getTeam())
            {
                seek.x -= 1;
                ss.str("");
                ss << "MOVE " << getNum() << " " << ((seek.x)+1)*64 << " " << seek.y*64 << " ~";
                ss << "REMV " << c->board[seek.x][seek.y]->getNum() << " ~";
                captureMap[seek] = ss.str();
            }
        }
      }
    }
  }

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

  //Check West/South
  seek = getSpot();
    seek.x-=2;
    seek.y+=1;
    if(seek.x >= 0 && seek.x <= 13)
    {
      if(c->validspots[seek.x][seek.y] != 0)
      {
       if(c->board[seek.x][seek.y]->getTeam() != getTeam())
       {
         spots.push_back(seek);
         ss.str("");
         ss << "CAPT " << getNum() << " " << c->board[seek.x][seek.y]->getNum() << " ~";
         if((c->validspots[seek.x][seek.y+1] != 0) && (c->board[seek.x][seek.y+1] != NULL))
         {
           if(c->board[seek.x][seek.y+1]->getTeam() != getTeam())
             ss << "REMV " << c->bard[seek.x][seek.y+1]->getNum() << " ~";
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
          }
        }
      }
    }
  return spots;
}
