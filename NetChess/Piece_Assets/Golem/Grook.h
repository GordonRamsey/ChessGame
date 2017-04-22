#ifndef GROOK_H
#define GROOK_H
#include "../rook.h"

class GRook : public Rook
{
  public:
    GRook(int x, int y, int it);
    ~GRook();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c);
};
#endif
