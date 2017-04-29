#include "piece.h"
#include <sstream>
using namespace std;

Piece::Piece(int x, int y, int it)
{
  box.x = x;
  box.y = y;
  box.w = 64;
  box.h = 64;

  num = it;
  debug_name = "DEFAULT PIECE";
}

Piece::~Piece()
{
}

Piece& Piece::operator=(const Piece& other)
{
  box = other.box;
  clip = other.clip;
  clip_num = other.clip_num;
  num = other.num;
  sheet = other.sheet;
  owner = other.owner;

  return *this;
}

coord Piece::getPos() const
{
    coord newcord;
    newcord.x = box.x;
    newcord.y = box.y;
    return newcord;
}

void Piece::setPos(const int x, const int y)
{
    box.x = x;
    box.y = y;
}

int Piece::getNum()
{
    return num;
}

//void Piece::handle_events();
  //Defined in game code

//void Piece::show()
  //Defined in game code


//void Piece::setClip(int x)
  //Defined in game code


//void Piece::setTeam(int x)
  //Defined in game code

int Piece::getTeam()
{
  return owner;
}

coord Piece::getSpot()
{
  coord newcord;
  newcord.y = (box.y) / 64;//row
  newcord.x = (box.x) / 64;
  return newcord;
}

string Piece::toString()
{
  stringstream ss;
  ss << "ID:" << num << " Owner:" << owner << " Pos:" << box.x << "," << box.y << " Clip:" << clip_num << " Sheet:" << sheet;
  return ss.str();
}

int Piece::getClip()
{
  return clip_num;
}

void Piece::setAlpha(int x)
{
  SDL_SetAlpha(sheet, SDL_SRCALPHA, x); 
}

string Piece::getCaptCmd(coord spot)
{
  return captureMap[spot];
}

void Piece::levelUp() 
{ 
  if(m_level)
    return;
  
  m_level = true;
  
  if(debug_name.find("pawn") == string::npos)
    setClip(getClip()+12);
  
  cerr << "Level up piece name:" << debug_name << endl;
  if(debug_name == "Fking")
  { 
    cerr << "OOH WEE UPGRADED FKING" << endl; 
    clicks = 1;
  }
  else if(debug_name == "Nking")
  {
    clicks = 3;
  }
  else if(debug_name == "Nknight")
  {
    clicks = 1;
  }
  else if(debug_name == "Nqueen")
  {
    clicks = 2;
  }
  else if(debug_name == "Nbishop")
  {
    clicks = 2;
  }
  else if(debug_name == "Gking")
  {
    clicks = 1;
  }
}
void Piece::Rock()
{
  if (rock){  
    rock = false;
    setClip(getClip()-24);
  }
  else{
    rock = true;
    setClip(getClip()+24);
  }
  cerr << "[ROCK] Piece num:" << getNum() << " Rock:" << isRock() << " Clip:" << getClip() << endl;
}
