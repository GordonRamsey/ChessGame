#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
class Queen : public Piece
{
  private:

  public:
    //Look up inheritance constructor and deconstructor
    bool isValid();
    void Move(const string position); //Use piece m_position and compare
};
#endif
