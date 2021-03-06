#ifndef GPAWN_H
#define GPAWN_H
#include "../pawn.h"
class GPawn : public Pawn
{
  private:
  public:
    GPawn(int x, int y, int it, char state);
    ~GPawn();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c);
};
#endif
