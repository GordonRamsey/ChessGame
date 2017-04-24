#include "piece.h"
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

bool Chess::isCapturable(coord a_spot, coord d_spot, string &capicing)
{
  //A_spot = spot of attacking piece, d is defense
  Piece* attacking = board[a_spot.x][a_spot.y];
  Piece* defending = board[d_spot.x][d_spot.y];

  cerr << "[isCapturable] A:" << attacking->debug_name << " | D:" << defending->debug_name << endl; 

  if(defending->debug_name == "Gknight")
  {
    //Check if attacker is pawn
    if(attacking->debug_name.find("pawn") != string::npos)
        return false;

    if(defending->isRock())
        return false;
  }

  if(defending->debug_name == "Gpawn")
  {
    cerr << "Checking Gpawn isrock:" << defending->isRock() << endl;
    if(defending->isRock())
        return false;
  }

  if(defending->debug_name == "Gbishop")
  {
    if(defending->isRock())
        return false;

    if(defending->m_level) //If it's leveled check if attacker is diagonal to it
    {
        if(((a_spot.x < d_spot.x) and (a_spot.y < d_spot.y)) or
           ((a_spot.x < d_spot.x) and (a_spot.y > d_spot.y)) or
           ((a_spot.x > d_spot.x) and (a_spot.y > d_spot.y)) or
           ((a_spot.x > d_spot.x) and (a_spot.y < d_spot.y)))
           return false;
    }
  }

  if(defending->debug_name == "Gqueen")
  {
    if(defending->isRock())
        return false;
  }

  if(defending->debug_name == "Grook")
  {
    if(defending->isRock())
        return false;

    if(defending->m_level) //If it's leveled check if attacker is in line with it
    {
        if(((a_spot.x == d_spot.x) && ((a_spot.y > d_spot.y) or (a_spot.y < d_spot.y))) or
           ((a_spot.y == d_spot.y) && ((a_spot.x > d_spot.x) or (a_spot.x < d_spot.x))))
           return false;
    }
  }


  //Run checks o3o

  //Cannot capture walls!
  //if(defending->debug_name == "wall")
  //  return false;

  return true;
}
