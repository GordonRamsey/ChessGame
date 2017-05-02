#include "Nknight.h"
using namespace std;

NKnight::NKnight(int x, int y, int it) : Knight(x, y ,it)
{
  debug_name = "Nknight";
}

NKnight::~NKnight()
{}

string NKnight::Move(coord newpos)
{
  if(m_level){
    if(priv_c->board[newpos.x][newpos.y] != NULL)
    {
      soul = priv_c->board[newpos.x][newpos.y]->debug_name;
    }
  }
    
  return "DEFAULT";
}

vector<coord> NKnight::validSpots(Chess* c)
{   
  priv_c = c;
  return Knight::validSpots(c);
}

string NKnight::processClicks(vector<coord> clickedOn, Chess* c)
{
  if(clickedOn.size() != 1)
    return "ERROR";
  
  if(soul == "")
    return "ERROR";

  int x = clickedOn[0].x/64;
  int y = clickedOn[0].y/64;

  if(c->board[x][y]->getTeam() != getTeam())
    return "ERROR";

  stringstream ss;

  ss << "REMV " << c->board[x][y]->getNum() << " ~";

  if(soul.find("pawn") != string::npos)
    return "ERROR";

  if(soul.find("king") != string::npos)
    return "ERROR";

  if(soul.find("bishop") != string::npos)
    ss << "PLAC Nbishop " << x << " " << y << " " << getTeam()-1 << " ~";

  if(soul.find("rook") != string::npos)
    ss << "PLAC Nrook " << x << " " << y << " " << getTeam()-1 << " ~";

  if(soul.find("knight") != string::npos)
    ss << "PLAC Nknight " << x << " " << y << " " << getTeam()-1 << " ~";

  if(soul.find("queen") != string::npos)
    ss << "PLAC Nqueen " << x << " " << y << " " << getTeam()-1 << " ~";

  soul = "";

  return ss.str();
}

