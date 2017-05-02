#ifndef WQUEEN_H
#define WQUEEN_H
#include "../queen.h"
class WQueen : public Queen
{
  private:
    string debug_name;
  public:
    WQueen(int x, int y, int it);
    ~WQueen();
    string Move(coord newpos);
    void wurmSpots(vector<coord> &spots, Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c);
    vector<coord> validSpots(Chess* c);
};
#endif
