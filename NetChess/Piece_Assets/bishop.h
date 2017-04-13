#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"

class Bishop : public Piece
{
  private:

  public:
    Bishop(int x, int y, int it);
    ~Bishop();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    virtual string processClicks(vector<coord> clickedOn, Chess* c) 
      { return "DEFAULT"; }
};
#endif
