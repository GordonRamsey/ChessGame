#ifndef KING_H
#define KING_H
#include "piece.h"
class King : public Piece 
{
  private:
    bool m_first;
  public:
    //Look up inheritance constructor and deconstructor
    bool isValid(const string position);
    void Move(const string position); //Use piece m_position and compare
    void Attack(const string position, Piece* piece); //Use piece m_positi    on and compare, then capture
    void Exchange();
};
#endif



