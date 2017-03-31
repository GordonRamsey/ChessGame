#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen : public Piece
{
  private:

  public:
    Queen(int x, int y, int it);
    ~Queen();
    virtual string Move(coord newpos);
    virtual vector<coord> validSpots(Chess* c);
};
#endif
