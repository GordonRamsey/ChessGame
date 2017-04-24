#ifndef GKING_H
#define GKING_H
#include "../king.h"
class GKing : public King
{
  private:
  public:
    GKing(int x, int y, int it);
    ~GKing();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c); 
    string MakeRocks(Chess* c);
};
#endif
