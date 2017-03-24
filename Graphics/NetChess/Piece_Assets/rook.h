#ifndef ROOK_H
#define ROOK_H
#include "piece.h"

class Rook : public Piece
{
  private:

  public:
    Rook(int x, int y, int it);
    ~Rook();
    vector<coord> validSpots(Chess c);

};
#endif
