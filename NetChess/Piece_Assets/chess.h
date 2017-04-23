#ifndef CHESS_H
#define CHESS_H
#include <vector>
#include <iostream>

using namespace std;

struct coord {
  int x;
  int y;
  bool operator<(const coord& a) const{
    return ((x < a.x) || (x == a.x && y < a.y));
  }
  bool operator==(const coord& a) const{
    return (x == a.x && y == a.y);
  }
};

class Piece;

class Chess
{
  public:
    int validspots [14][14] =
    {{0,0,0,1,1,1,1,1,1,1,1,0,0,0},
     {0,0,0,1,1,1,1,1,1,1,1,0,0,0},
     {0,0,0,1,1,1,1,1,1,1,1,0,0,0},
     {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
     {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
     {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
     {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
     {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
     {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
     {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
     {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
     {0,0,0,1,1,1,1,1,1,1,1,0,0,0},
     {0,0,0,1,1,1,1,1,1,1,1,0,0,0},
     {0,0,0,1,1,1,1,1,1,1,1,0,0,0}};
    
    Piece* board [14][14];
    Piece* terrain[14][14];
    vector<Piece*> pieces;

    int it;

    Chess();
    ~Chess();
    
    //Set position of piece on board
    void setPiecePos(int num, int x, int y);
    //remove piece from board
    void removePiece(int num);
    bool isValid(int x, int y);
    bool isCapturable(coord a_spot, coord d_spot, string &capicing);


};
#endif
