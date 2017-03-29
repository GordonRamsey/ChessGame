#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
class Queen : public Piece
{
  private:
    string m_name;
  public:
    Queen(int x, int y);//Constructor
    ~Queen();//Destruictor
    string getName() const;
    void setName(const string name);
    char getTmpColor(int y, int x, vector<coord> WLocs, vector<coord>BLocs); 
    bool isEnemy(int y, int x, char myColor, vector<coord> WLocs, vector<coord>BLocs ); 
    bool isAlly(int y, int x, char myColor, vector<coord> WLocs, vector<coord>BLocs); 
    bool isEmpty(int y, int x, vector<coord> WLocs, vector<coord>BLocs); 
    void ValidMoves(int cp_y, int cp_x, char myColor, vector<coord> &captureable, vector<coord> &validPos, vector<coord> WLocs, vector<coord> BLocs);
};
#endif
