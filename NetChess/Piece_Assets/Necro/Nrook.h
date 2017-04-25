#ifndef NROOK_H
#define NROOK_H
#include "../rook.h"

class NRook : public Rook
{
  private:
  public:
    NRook(int x, int y, int it);
    ~NRook();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c);
};
#endif
