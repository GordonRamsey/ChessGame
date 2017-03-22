#include "piece.h"
using namespace std;

Piece::Piece(int x, int y, int it)
{
  m_color = '\0';
  m_position.x = x / 64; //Divides the coordinates
  m_position.y = y / 64; //Gives a (x,y) for the grid
  m_captured = false;

  box.x = x;
  box.y = y;
  box.w = 64;
  box.h = 64;

  num = it;
}

Piece::~Piece()
{
}

char Piece::getColor() const
{
    return m_color;
}

void Piece::setColor(const char color)
{
    m_color = color;
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

bool Piece::getCaptured() const
{
    return m_captured;
}

void Piece::setCaptured(const bool captured)
{
    m_captured = captured;
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


coord Piece::getSpot()
{
  coord newcord;
  newcord.y = (box.y) / 64;//row
  newcord.x = (box.x) / 64;
  return newcord;
}

int Piece::getClip()
{
  return clip_num;
}

//Movement - Should pass a "board" parameter so the piece can know where everything is
//Movement should return a list of spots the piece can move to

//Attacking should be separate from moving?
