#ifndef WKING_H
#define WKING_H
#include "../king.h"
class WKing : public King
{
  public:
    WKing(int x, int y, int it);
    ~WKing();
    string createCrater(coord spot, Chess* c);//going to setup similar to checkAdjacent from WKnight
    void wurmSpots(vector<coord> &spots, Chess* c);
    string Move(coord newpos);
    string processClicks(vector<coord> clickedOn, Chess* c);
    vector<coord> validSpots(Chess* c);
};
#endif
