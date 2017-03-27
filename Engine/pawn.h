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
        char getTmpColor(int y, int x, vector<coord> WLocs, vector<coord>BLocs); 
        bool isEnemy(int y, int x, char myColor, vector<coord> WLocs, vector<coord>BLocs ); 
        bool isAlly(int y, int x, char myColor, vector<coord> WLocs, vector<coord>BLocs); 
        bool isEmpty(int y, int x, vector<coord> WLocs, vector<coord>BLocs); 
        void ValidMoves(int cp.y, int cp.x, char myColor, &vector<coord> captureable, &vector<coord>validPos, vector<coord> WLocs, vector<coord> BLocs);
        bool firstMove(int y, int, x, char myColor); 
};
#endif
