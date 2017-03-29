#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
class Pawn : public Piece {
    private:
        bool m_first;
        string m_name;
    public:
	    Pawn(int x, int y);//Contructor
	    ~Pawn();//Destructor
        string getName() const;
        void setName(const string name);
        char getTmpColor(int y, int x, vector<coord> WLocs, vector<coord>BLocs); 
        bool isEnemy(int y, int x, char myColor, vector<coord> WLocs, vector<coord>BLocs ); 
        bool isAlly(int y, int x, char myColor, vector<coord> WLocs, vector<coord>BLocs); 
        bool isEmpty(int y, int x, vector<coord> WLocs, vector<coord>BLocs); 
        void ValidMoves(int cp_y, int cp_x, char myColor, vector<coord> &captureable, vector<coord> &validPos, vector<coord> WLocs, vector<coord> BLocs);
        bool firstMove(int y, int x, char myColor); 
};
#endif
