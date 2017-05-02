#ifndef NKNIGHT_H
#define NKNIGHT_H
#include "../knight.h"

class NKnight : public Knight
{
  private:
    string soul;
    Chess* priv_c;
  public:
    NKnight(int x, int y, int it);
    ~NKnight();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c); 
};
#endif
