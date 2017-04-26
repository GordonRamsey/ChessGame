#ifndef PKING_H
#define PKING_H
#include "../king.h"
class PKing : public King
{
  private:
  public:
    PKing(int x, int y, int it);
    ~PKing();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c); 
};
#endif
