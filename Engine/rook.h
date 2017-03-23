#ifndef ROOK_H
#define ROOK_H
#include "piece.h"
class Rook : public Piece
{
  private:
    string m_name; 
  public:
    //Look up inheritance constructor and deconstructor
    ???? isValid();
	vector<coord> AllPos();
    vector<coord> PotentialMoves(int x, int y, chess* c); 
    void Move(const string position); //Use piece m_position and compare
    string getName() const; 
    void setName(const string name); 
};
#endif
