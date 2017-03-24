#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"

class Knight : public Piece
{
  private:

  public:
    vector<coord> validSpots(Chess c);

};
#endif
