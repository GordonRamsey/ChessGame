#ifndef ROOK_H
#define ROOK_H
#include "piece.h"
class Rook : public Piece
{
  private:

  public:
    //Look up inheritance constructor and deconstructor
    bool isValid();
    void Move(const string position); //Use piece m_position and compare
};
#endif
