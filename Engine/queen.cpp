#include "queen.h"
using namespace std;

bool Queen::isValid()
{
  //Used to be param, need to change this
  string current = getPosition();
  //Checking color first.
  if (getColor=='w')
  {
	
  }

  else if (getColor == 'b')
  {
	
  }
}

void Queen::Move(const string posiiton)
{
  //Check if valid move, then: 
  setPosition(position);
}
/*
void Queen::Attack(const string position, Piece* piece)
{
  piece->setCaptured(true);
  setPosition(position);
}
*/
