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

bool Chess::isCapturable(coord a_spot, coord d_spot)
{
  //A_spot = spot of attacking piece, d is defense
  Piece* attacking = board[a_spot.x][a_spot.y];
  Piece* defending = board[d_spot.x][d_spot.y];

  //Run checks o3o

  //Cannot capture walls!
  //if(defending->debug_name == "wall")
  //  return false;

  return true;
}
