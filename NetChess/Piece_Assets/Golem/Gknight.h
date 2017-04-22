#ifndef GKNIGHT_H
#define GKNIGHT_H
#include "../knight.h"

class GKnight : public Knight
{
  private:
    bool rock = false;
  public:
    GKnight(int x, int y, int it);
    ~GKnight();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c) 
      { return "DEFAULT"; }
    bool isRock() const;
    void Rock();
};
#endif