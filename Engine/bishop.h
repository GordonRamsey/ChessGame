#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
class Bishop : public Piece 
{
  private:
    string m_name;
  public:
    //Look up inheritance constructor and deconstructor
    void Move(const string position); //Use piece m_position and compare
    Bishop();//Construtor
    ~Bishop();//Destructor
    string getName() const
    void setName(const string name);
    char getTmpColor(int y, int x, vector<coord> WLocs, vector<coord>BLocs); 
    bool isEnemy(int y, int x, char myColor); 
    bool isEmpty(int y, int x); 
    void ValidMoves(int cp.y, int cp.x, &vector<coord> captureable, &vector<coord>validPos); 
};
#endif
