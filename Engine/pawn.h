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
        void Move(const coord position); //Use piece m_position and compare
	    Pawn();//Contructor
	    ~Pawn();//Destructor
        string getName() const;
        void setName(const string name);
        char getTmpColor(int y, int x, &vector<coord> captureable, &vector<coord> isValid);    
        void ValidMoves(cp.y, cp.x, vector<coord> WLocs, vector<coord> BLocs); 
        bool isAlly(int y, int x, char myColor); 
        bool isEnemy(int y, int x, char myColor); 
        bool isEmpty(int y, int x);
        bool firstMove(int y, int x, char myColor); 
};
#endif
