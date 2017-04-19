#ifndef FBISHOP_H
#define FBISHOP_H
#include "../bishop.h"
class FBishop : public Bishop
{
  private:
    string debug_name;
  public:
    FBishop(int x, int y, int it);
    ~FBishop();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c)
      { return "DEFAULT"; }
};
#endif
