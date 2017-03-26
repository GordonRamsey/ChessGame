#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"
class Knight : public Piece
{
  private:
    string m_name;
  public:
    //Look up inheritance constructor and deconstructor
    void Move(const string position); //Use piece m_position and compare
    Knight();//Constructor
    ~Knight();//Destructor
    string getName() const;
    void setName(const string name);
    char getTmpColor(int y, int x, vector<coord> WLocs, vector<coord>BLocs); 
    bool isEnemy(int y, int x, char myColor, vector<coord> WLocs, vector<coord>BLocs ); 
    bool isAlly(int y, int x, char myColor, vector<coord> WLocs, vector<coord>BLocs); 
    bool isEmpty(int y, int x, vector<coord> WLocs, vector<coord>BLocs); 
    void ValidMoves(int cp.y, int cp.x, char myColor, &vector<coord> captureable, &vector<coord>validPos, vector<coord> WLocs, vector<coord> BLocs);
};
#endif

