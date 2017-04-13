#ifndef KING_H
#define KING_H
#include "piece.h"
class King : public Piece
{
  private:

  public:
    King(int x, int y, int it);
    ~King();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    virtual string processClicks(vector<coord> clickedOn, Chess* c) 
      { return "DEFAULT"; }
};
#endif
