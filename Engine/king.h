#ifndef KING_H
#define KING_H
#include "piece.h"
class King : public Piece 
{
  private:
    string m_name;
  public:
    //Look up inheritance constructor and deconstructor
    King(int x, int y);//Constructor
    ~King();//Destructor
    string getName() const;
    void setName(const string name);
    char getTmpColor(int y, int x, vector<coord> WLocs, vector<coord>BLocs); 
    bool isEnemy(int y, int x, char myColor, vector<coord> WLocs, vector<coord>BLocs ); 
    bool isAlly(int y, int x, char myColor, vector<coord> WLocs, vector<coord> BLocs); 
    bool isEmpty(int y, int x, vector<coord> WLocs, vector<coord>BLocs); 
    void ValidMoves(int cp_y, int cp_x, char myColor, vector<coord> &captureable, vector<coord> &validPos, vector<coord> WLocs, vector<coord> BLocs);
};
#endif



