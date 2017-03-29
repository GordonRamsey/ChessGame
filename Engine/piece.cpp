#include "piece.h"
using namespace std;

Piece::Piece(int x, int y)
{
  m_color = '\0';
  m_captured = false;
  m_position.x = x;
  m_position.y = y;
}

Piece::~Piece()
{}

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
    return m_position;
}

void Piece::setPos(const int x, const int y)
{
    m_position.x = x;
    m_position.y = y;
}

bool Piece::getCaptured() const
{
    return m_captured;
}

void Piece::setCaptured(const bool captured)
{
    m_captured = captured;
}
/*
int Piece::getNum()
{
    return num;
}
*/
//void Piece::handle_events();
  //Defined in game code

//void Piece::show()
  //Defined in game code


//void Piece::setClip(int x)
  //Defined in game code


//void Piece::setTeam(int x)
  //Defined in game code

/*
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

void Piece::setAlpha(int x)
{
  SDL_SetAlpha(sheet, SDL_SRCALPHA, x); 
}
*/
//Movement - Should pass a "board" parameter so the piece can know where everything is
//Movement should return a list of spots the piece can move to

//Attacking should be separate from moving?
