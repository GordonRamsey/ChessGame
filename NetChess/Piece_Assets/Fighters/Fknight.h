#ifndef FKNIGHT_H
#define FKNIGHT_H
#include "../knight.h"

class FKnight : public Knight 
{
  public:
    FKnight(int x, int y, int it);
    ~FKnight();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c)
      { return "DEFAULT"; }
};
#endif
