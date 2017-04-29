#ifndef PROOK_H
#define PROOK_H
#include "../rook.h"

class PRook : public Rook
{
  private:
  public:
    PRook(int x, int y, int it);
    ~PRook();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c);
};
#endif
