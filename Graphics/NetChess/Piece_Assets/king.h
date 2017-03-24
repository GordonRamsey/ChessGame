#ifndef KING_H
#define KING_H
#include "piece.h"
class King : public Piece
{
  private:

  public:
    King(int x, int y, int it);
    ~King();
    vector<coord> validSpots(Chess c);

};
#endif
