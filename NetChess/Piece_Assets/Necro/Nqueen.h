#ifndef NQUEEN_H
#define NQUEEN_H
#include "../queen.h"

class NQueen : public Queen
{
  private:
  public:
    NQueen(int x, int y, int it);
    ~NQueen();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c);
};
#endif
