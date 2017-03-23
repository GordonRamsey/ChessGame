#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
class Pawn : public Piece {
{
    private:
        bool m_first;
        string m_name
    public:
        //Look up inheritance constructor and deconstructor
        bool isValid();
        void Move(const coord position); //Use piece m_position and compare
        void Exchange();
	    Pawn();//Contructor
	    ~Pawn();//Destructor
        string getName() const;
        void setName(const string name);

};
#endif
