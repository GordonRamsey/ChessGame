#ifndef PAWN_H
#define PAWN_H
#include "piece.h"

class Wall : public Piece
{
  private:

  public:
    Wall(int x, int y, int it, char state);
    ~Wall();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
};
#endif
