#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
class Pawn : public Piece {
{
    private:
        bool m_first;
    public:
        //Look up inheritance constructor and deconstructor
        bool isValid();
        void Move(const coord position); //Use piece m_position and compare
        void Exchange();
	Pawn();//Contructor
	~Pawn();//Destructor
};
#endif
