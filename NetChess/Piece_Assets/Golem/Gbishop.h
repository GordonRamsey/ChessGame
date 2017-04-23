#ifndef GBISHOP_H
#define GBISHOP_H
#include "../bishop.h"

class GBishop : public Bishop
{
  private:
  public:
    GBishop(int x, int y, int it);
    ~GBishop();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c) 
    bool isRock() const;
    void Rock();
};
#endif
