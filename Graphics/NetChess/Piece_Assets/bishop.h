#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"

class Bishop : public Piece
{
  private:

  public:
    Bishop(int x, int y, int it);
    ~Bishop();
    vector<coord> validSpots(Chess c);

};
#endif
