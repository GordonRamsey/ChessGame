#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
class Queen : public Piece
{
  private:
    string m_name;
  public:
    //Look up inheritance constructor and deconstructor
    void Move(const string position); //Use piece m_position and compare
    Queen();//Constructor
    ~Queen()//Destruictor
    string getName() const;
    void setName(const strign name);
    char getTmpColor(int y, int x, vector<coord> WLocs, vector<coord>BLocs); 
    bool isEnemy(int y, int x, char myColor, vector<coord> WLocs, vector<coord>BLocs ); 
    bool isAlly(int y, int x, char myColor, vector<coord> WLocs, vector<coord>BLocs); 
    bool isEmpty(int y, int x, vector<coord> WLocs, vector<coord>BLocs); 
    void ValidMoves(int cp.y, int cp.x, char myColor, &vector<coord> captureable, &vector<coord>validPos, vector<coord> WLocs, vector<coord> BLocs);
};
#endif
