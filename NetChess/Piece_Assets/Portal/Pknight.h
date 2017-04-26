#ifndef PKNIGHT_H
#define PKNIGHT_H
#include "../knight.h"

class PKnight : public Knight
{
  private:
  public:
    PKnight(int x, int y, int it);
    ~PKnight();
    string Move(coord newpos);
    vector<coord> validSpots(Chess* c);
    string processClicks(vector<coord> clickedOn, Chess* c); 
};
#endif
