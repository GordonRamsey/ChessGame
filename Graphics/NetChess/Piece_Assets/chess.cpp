#include "chess.h"

Chess::Chess()
{

}

Chess::~Chess()
{

}

bool Chess::isValid(int x, int y)
{
  if(y < 0 || y > 13)
    return false;
  if(x < 0 || x > 13)
    return false;
  if(validspots[x][y] == 0)
    return false;

  return true;
}


