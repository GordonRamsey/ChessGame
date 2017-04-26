#ifndef PPAWN_H
#define PPAWN_H
#include "../pawn.h"
class PPawn : public Pawn
{
  private:
  public:
    PPawn(int x, int y, int it, char state);
    ~PPawn();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c);
};
#endif
