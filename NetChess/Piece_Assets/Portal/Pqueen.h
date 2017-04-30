#ifndef PQUEEN_H
#define PQUEEN_H
#include "../queen.h"

class PQueen : public Queen
{
  private:
  public:
    PQueen(int x, int y, int it);
    ~PQueen();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c);
};
#endif
