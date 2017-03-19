#include "piece.h"
using namespace std;

Piece::Piece(int x, int y, int it)
{
  m_color = '\0';
  m_position.x = 0;
  m_position.y = 0;
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
  newcord.x = (box.y-128) / 32;//row
  newcord.y = (box.x-128) / 32;
  return newcord;
}

int Piece::getClip()
{
  return clip_num;
}
