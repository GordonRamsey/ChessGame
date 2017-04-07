#ifndef ROOK_H
#define ROOK_H
#include "piece.h"

class Rook : public Piece
{
  private:

  public:
    Rook(int x, int y, int it);
    ~Rook();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    virtual string processClicks(vector<coord> clickedOn, Chess* c) 
      { return "DEFAULT"; }
};
#endif
