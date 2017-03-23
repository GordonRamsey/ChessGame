#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
class Bishop : public Piece 
{
  private:

  public:
    //Look up inheritance constructor and deconstructor
    bool isValid();
    void Move(const string position); //Use piece m_position and compare
    Bishop();//Construtor
    ~Bishop();//Destructor
};
#endif
