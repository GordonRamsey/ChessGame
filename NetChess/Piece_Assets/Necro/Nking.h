#ifndef NKING_H
#define NKING_H
#include "../king.h"
class NKing : public King
{
  private:
  public:
    NKing(int x, int y, int it);
    ~NKing();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c); 
    string MakeRocks(Chess* c);
};
#endif
