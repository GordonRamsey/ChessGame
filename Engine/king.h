#ifndef KING_H
#define KING_H
#include "piece.h"
class King : public Piece 
{
  private:
    string m_name;
  public:
    //Look up inheritance constructor and deconstructor
    bool isValid();
    void Move(const string position); //Use piece m_position and compare
    King();//Constructor
    ~King();//Destructor
    string getName() const;
    void setName(const string name);
};
#endif



