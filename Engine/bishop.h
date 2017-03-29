#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
class Bishop : public Piece 
{
  private:
    string m_name;
  public:
    Bishop();//Construtor
    ~Bishop();//Destructor
    string getName() const
    void setName(const string name);
    char getTmpColor(int y, int x, vector<coord> WLocs, vector<coord>BLocs); 
    bool isEnemy(int y, int x, char myColor, vector<coord> WLocs, vector<coord>BLocs ); 
    bool isAlly(int y, int x, char myColor, vector<coord> WLocs, vector<coord>BLocs); 
    bool isEmpty(int y, int x, vector<coord> WLocs, vector<coord>BLocs); 
    void ValidMoves(int cp.y, int cp.x, char myColor, &vector<coord> captureable, &vector<coord>validPos, vector<coord> WLocs, vector<coord> BLocs); 
};
#endif
