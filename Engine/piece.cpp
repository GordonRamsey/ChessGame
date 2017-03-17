#include "piece.h"
using namespace std;

Piece::Piece(int x, int y, int num) : color('\0'), position(0,0), captured(false)
{
  box.x = x;
  box.y = y;
  box.w = 24;
  box.h = 24;

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

coord Piece::getPosition() const
{
    return m_position;
}

void Piece::setPosition(const int x, const int y)
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

int Piece::getNum()
{
    return num;
}

void Piece::handle_events()
{
  int x = 0, y = 0;

  if(event.type == SDL_MOUSEBUTTONDOWN)
  {
    if(event.button.buton == SDL_BUTTON_LEFT)
    {
      x = event.button.x;
      y = event.button.y;

      if ((x > box.x) && (x < box.x + box.w) && (y > box.y) && (y < box.y + box.h))
      {
	if(selected == NULL){
	  clip = &clips[CLIP_SELECTED];
	  selected = this;
	}
      }
    }
  }
}

void Piece::show()
{
  //XXX Piecesheet
  apply_surface(box.x, box.y, pieceSheet, screen, clip);
}

void setClip(int x)
{
  clip = &clips[x];
}


