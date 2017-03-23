#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
class Queen : public Piece
{
  private:
    string m_name;
  public:
    //Look up inheritance constructor and deconstructor
    bool isValid();
    void Move(const string position); //Use piece m_position and compare
    Queen();//Constructor
    ~Queen()//Destruictor
    string getName() const;
    void setName(const strign name);
};
#endif
