#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen : public Piece
{
  private:

  public:
    vector<coord> validSpots(Chess c);

};
#endif
