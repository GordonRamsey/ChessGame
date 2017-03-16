#include "bishop.h"
using namespace std;

bool Bishop::isValidMove(const string position)
{
  string current = getPosition();
  if (getColor=='w')
  {
    if (m_first == false)
    {

      if (((int) current.substring(1,1)))
      {

      }
    }
  }
}

void Bishop::Move(const string posiiton)
{
  if(m_first == false)
  {
    m_first == true;
  }
  setPosition(position);
}

void Bishop::Attack(const string position, Piece* piece)
{
  piece->setCaptured(true);
  setPosition(position);
}
