#include "queen.h"
using namespace std;

bool Queen::isValidMove(const string position)
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

void Queen::Move(const string posiiton)
{
  if(m_first == false)
  {
    m_first == true;
  }
  setPosition(position);
}

void Queen::Attack(const string position, Piece* piece)
{
  piece->setCaptured(true);
  setPosition(position);
}

