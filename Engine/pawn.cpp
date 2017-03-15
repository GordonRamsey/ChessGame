#include "pawn.h"
using namespace std;

bool Pawn::isValidMove(const string position)
{
    string current = getPosition();
    if(getColor=='w')
    {
        if(m_first == false)
            if(((int)current.substring(1,1))
            
}

void Pawn::Move(const string position)
{
    if(m_first == false)    
    {
        m_first == true;
    }
    setPosition(position);
}

void Pawn::Attack(const string position, Piece* piece)
{
    piece->setCaptured(true);   
    setPosition(position);
}

