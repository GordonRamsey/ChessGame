#ifndef FKNIGHT_H
#define FKNIGHT_H
#include "../knight.h"

class FKnight : public Knight 
{
  private:
    bool m_level;

  public:
    FKnight(int x, int y, int it);
    ~FKnight();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
};
#endif