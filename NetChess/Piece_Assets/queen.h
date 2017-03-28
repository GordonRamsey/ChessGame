#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen : public Piece
{
  private:

  public:
    Queen(int x, int y, int it);
    ~Queen();
    vector<coord> validSpots(Chess* c);
};
#endif
