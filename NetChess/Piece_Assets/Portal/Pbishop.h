#ifndef PBISHOP_H
#define PBISHOP_H
#include "../bishop.h"

class PBishop : public Bishop
{
  private:
  public:
    PBishop(int x, int y, int it);
    ~PBishop();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c); 
};
#endif
