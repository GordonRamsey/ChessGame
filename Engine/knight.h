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
    char getTmpColor(int y, int x, &vector<coord> captureable, &vector<coord> isValid);    
    void ValidMoves(cp.y, cp.x, vector<coord> WLocs, vector<coord> BLocs); 
    bool isAlly(int y, int x, char myColor); 
    bool isEnemy(int y, int x, char myColor); 
    bool isEmpty(int y, int x);
};
#endif

