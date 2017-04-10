#ifndef CHESS_H
#define CHESS_H
#include <vector>
#include <iostream>

using namespace std;

struct coord {
  int x;
  int y;
  bool operator>(const coord& other) const{
    if(x > other.x)
      return true;
    else 
      return false;
  }
  bool operator<(const coord& other) const{
    if(x < other.x)
      return true;
    else 
      return false;
  }

  coord& operator=(const coord& a){
    x = a.x;
    y = a.y;
    return *this;
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
    bool isCapturable(coord a_spot, coord d_spot);


};
#endif
