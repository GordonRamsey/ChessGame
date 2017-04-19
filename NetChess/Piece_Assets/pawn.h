#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
class Pawn : public Piece
{
  protected:
    bool first_move = true;
    char dir;

  public:
    Pawn(int x, int y, int it, char state);
    ~Pawn();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    virtual string processClicks(vector<coord> clickedOn, Chess* c) 
      { return "DEFAULT"; }
};
#endif
