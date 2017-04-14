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
  if(first_move == true)
    first_move == false;

  stringstream ss;
  ss << "Move" << getNum() << " " << newpos.x*64 << " " << newpos.y*64 << " ~";
  return ss,str();

}

vector<coord> FPawn::validSpots(Chess* c)
{
  stringsteam ss;
  coord seek;
  seek = getSpot();
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
                        if(getTeam() != c->board[seek.x+1][seek.y-1]->getteam())
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
                        if(getTeam() != c->board[seek.x+1][seek.y-1]->getteam())
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



  //Check North/West
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y-=2;
    seek.x-=1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//valid spot
      break;
    if(c->board[seek.x][seek.y] != NULL){
      if(c->board[seek.x][seek.y]->getTeam() != getTeam()){
	spots.push_back(seek);
	ss.str("");
	ss << "CAPT " << getNum() <<  " " << c->board[seek.x][seek.y]->getNum(    ) >> " ~";
	captureMap(seek) = ss.str();
	break;
      }
      else
	break;
    }
    spots.push_back(seek);
    break;
  }

  //Check North/East
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y-=2;
    seek.x+=1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//invalid spot
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
    break;
  }

  //Check East/North
   seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y+=2;
    seek.x-=1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//invalid spot
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
    break;
  }
  //East/South
    seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y+=2;
    seek.x+=1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//invalid spot
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
    break;
 
  }
  
  
  //Check South/West
  seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y+=2;
    seek.x-=1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//invalid spot
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
    break;
  }
//Check West/North
seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y-=2;
    seek.x-=1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//invalid spot
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
    break;
  }

//Check West/South
seek = getSpot();
  while(true){//Checking untill 1. hit board limit 2. hit a piece
    seek.y-=2;
    seek.x+=1;
    if(seek.y < 0 or seek.x > 13)//Out of bounds
      break;
    if(c->validspots[seek.x][seek.y] == 0)//invalid spot
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
    break;
  }
  return spots;
}
