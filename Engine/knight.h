#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"
class Knight : public Piece
{
  private:

  public:
    //Look up inheritance constructor and deconstructor
    bool isValid();
    void Move(const string position); //Use piece m_position and compare
    Knight();//Constructor
    ~Knight();//Destructor
};
#endif

