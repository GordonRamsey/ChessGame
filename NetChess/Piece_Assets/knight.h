#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"

class Knight : public Piece
{
  private:

  public:
    Knight(int x, int y, int it);
    ~Knight();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
};
#endif
