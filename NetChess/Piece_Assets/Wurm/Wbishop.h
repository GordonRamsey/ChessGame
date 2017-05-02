#ifndef WBISHOP_H
#define WBISHOP_H
#include "../bishop.h"
class WBishop : public Bishop
{
  public:
    WBishop(int x, int y, int it);
    ~WBishop();
    void wurmSpots(vector<coord> &spots, Chess* c);
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
};
#endif
