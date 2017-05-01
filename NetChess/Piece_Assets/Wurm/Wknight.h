#ifndef WKNIGHT_H
#define WKNIGHT_H
#include "../knight.h"
class WKnight : public Knight
{
  private:
    string debug_name;
  public:
    WKnight(int x, int y, int it);
    ~WKnight();
	string checkAdjacent(coord spot, Chess* c);
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
};
#endif
