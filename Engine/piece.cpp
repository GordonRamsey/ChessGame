#include "piece.h"
using namespace std;

Piece::Piece() : color('\0'), position(""), captured(false)
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

string Piece::getPosition() const
{
    return m_position;
}

void Piece::setPosition(const string position)
{
    m_position = position;
}

bool Piece::getCaptured() const
{
    return m_captured;
}

void Piece::setCaptured(const bool captured)
{
    m_captured = captured;
}


    

