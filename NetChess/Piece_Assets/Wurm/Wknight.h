#ifndef WKNIGHT_H
#define WKNIGHT_H
#include "../knight.h"
class WKnight : public Knight
{
  private:
    Chess* priv_c;
  public:
    WKnight(int x, int y, int it);
    ~WKnight();
    string checkAdjacent(coord spot, Chess* c);
    void wurmSpots(vector<coord> &spots, Chess* c);
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
};
#endif
