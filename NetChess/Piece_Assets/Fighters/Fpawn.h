#ifndef FPAWN_H
#define FPAWN_H
#include "../pawn.h"
class FPawn : public Pawn
{
  public:
    FPawn(int x, int y, int it, char state);
    ~FPawn();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c)
      { return "DEFAULT"; }
};
#endif
