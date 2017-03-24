#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"

class Bishop : public Piece
{
  private:

  public:
    vector<coord> validSpots(Chess c);

};
#endif
