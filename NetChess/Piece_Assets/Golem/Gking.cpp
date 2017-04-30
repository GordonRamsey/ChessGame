#include "Gking.h"
using namespace std;

GKing::GKing(int x, int y, int it) : King(x, y, it)
{
    debug_name = "Gking";
}

GKing::~GKing()
{}

string GKing::Move(coord newpos)
{
    return King::Move(newpos);
}

vector<coord> GKing::validSpots(Chess* c)
{
    if(!rock)
        return King::validSpots(c);

    vector<coord> empty;
    return empty;
}

string GKing::processClicks(vector<coord> clickedOn, Chess* c)
{
    //Should check if leveled up. If so checks spaces around it for allied pieces and turns them to sentinels. Each golem piece should get their own isRock function and Rock function
    if(m_level)
    {
        stringstream ss;
	if(clickedOn.size() != 1)
	  return "ERROR";

	if(clickedOn[0] == getPos())
	{
	  ss.str(MakeRocks(c));
	  return ss.str();
	}
	else
	  return "DEFAULT";
    }
    else
      return "DEFAULT";
}

string GKing::MakeRocks(Chess* c)
{ 
  stringstream ss;
  if(m_level)
  {
    ss << "MOVE " << getNum() << " " << getPos().x << " " << getPos().y << " ~";
    coord cur_pos = getSpot();
    if(c->validspots[cur_pos.x-1][cur_pos.y-1] != 0 && c->board[cur_pos.x-1][cur_pos.y-1] != NULL)
    {
      if(c->board[cur_pos.x-1][cur_pos.y-1]->getTeam() == getTeam())
      {
	ss <<"ROCK " << c->board[cur_pos.x-1][cur_pos.y-1]->getNum() << " ~";
	c->board[cur_pos.x-1][cur_pos.y-1]->clicks = 1;
      }
    }

    if(c->validspots[cur_pos.x][cur_pos.y-1] != 0 && c->board[cur_pos.x][cur_pos.y-1] != NULL)
    {
      if(c->board[cur_pos.x][cur_pos.y-1]->getTeam() == getTeam())
      {
	ss <<"ROCK " << c->board[cur_pos.x][cur_pos.y-1]->getNum() << " ~";
	c->board[cur_pos.x][cur_pos.y-1]->clicks = 1;
      }
    }

    if(c->validspots[cur_pos.x+1][cur_pos.y-1] != 0 && c->board[cur_pos.x+1][cur_pos.y-1] != NULL)
    {
      if(c->board[cur_pos.x+1][cur_pos.y-1]->getTeam() == getTeam())
      {
	ss <<"ROCK " << c->board[cur_pos.x+1][cur_pos.y-1]->getNum() << " ~";
	c->board[cur_pos.x+1][cur_pos.y-1]->clicks = 1;
      }
    }

    if(c->validspots[cur_pos.x+1][cur_pos.y] != 0 && c->board[cur_pos.x+1][cur_pos.y] != NULL)
    {
      if(c->board[cur_pos.x+1][cur_pos.y]->getTeam() == getTeam())
      {	
	ss <<"ROCK " << c->board[cur_pos.x+1][cur_pos.y]->getNum() << " ~";
	c->board[cur_pos.x+1][cur_pos.y]->clicks = 1;
      }
    }

    if(c->validspots[cur_pos.x+1][cur_pos.y+1] != 0 && c->board[cur_pos.x+1][cur_pos.y+1] != NULL)
    {
      if(c->board[cur_pos.x+1][cur_pos.y+1]->getTeam() == getTeam())
      {
	ss <<"ROCK " << c->board[cur_pos.x+1][cur_pos.y+1]->getNum() << " ~";
	c->board[cur_pos.x+1][cur_pos.y+1]->clicks = 1;
      }
    }

    if(c->validspots[cur_pos.x][cur_pos.y+1] != 0 && c->board[cur_pos.x][cur_pos.y+1] != NULL)
    {
      if(c->board[cur_pos.x][cur_pos.y+1]->getTeam() == getTeam())
      {	
	ss <<"ROCK " << c->board[cur_pos.x][cur_pos.y+1]->getNum() << " ~";
	c->board[cur_pos.x][cur_pos.y+1]->clicks = 1;
      }
    }

    if(c->validspots[cur_pos.x-1][cur_pos.y+1] != 0 && c->board[cur_pos.x-1][cur_pos.y+1] != NULL)
    {
      if(c->board[cur_pos.x-1][cur_pos.y+1]->getTeam() == getTeam())
      {	
	ss <<"ROCK " << c->board[cur_pos.x-1][cur_pos.y+1]->getNum() << " ~";
	c->board[cur_pos.x-1][cur_pos.y+1]->clicks = 1;
      }
    }

    if(c->validspots[cur_pos.x-1][cur_pos.y] != 0 && c->board[cur_pos.x-1][cur_pos.y] != NULL)
    {
      if(c->board[cur_pos.x-1][cur_pos.y]->getTeam() == getTeam())
      {	
	ss <<"ROCK " << c->board[cur_pos.x-1][cur_pos.y]->getNum() << " ~";
	c->board[cur_pos.x-1][cur_pos.y]->clicks = 1;
      }
    }
  }
  return ss.str();
}

