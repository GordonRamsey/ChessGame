#include "piece.h"
using namespace std;

Piece::Piece() : color('\0'), position(0,0), captured(false)
{}

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


    

