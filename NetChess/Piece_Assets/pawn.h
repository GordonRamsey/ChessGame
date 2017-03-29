#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
class Pawn : public Piece
{
  private:
    bool first_move = true;
    char dir;

  public:
    Pawn(int x, int y, int it, char state);
    ~Pawn();
    vector<coord> validSpots(Chess* c);
};
#endif
