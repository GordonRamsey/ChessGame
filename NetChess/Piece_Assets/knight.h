#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"

class Knight : public Piece
{
  private:

  public:
    Knight(int x, int y, int it);
    ~Knight();
    virtual string Move(coord newpos);
    virtual vector<coord> validSpots(Chess* c);
    virtual string processClicks(vector<coord> clickedOn, Chess* c) 
      { return "DEFAULT"; }
};
#endif
