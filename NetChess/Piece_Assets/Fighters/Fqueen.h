#ifndef FQUEEN_H
#define FQUEEN_H
#include "../queen.h"

class FQueen : public Queen 
{
  public:
    FQueen(int x, int y, int it);
    ~FQueen();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c)
      { return "DEFAULT"; }
};
#endif
