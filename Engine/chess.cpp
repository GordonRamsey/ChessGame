#include "chess.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

Chess::Chess()
{//put update infront of things 
    coord temp; 
    cur_piece = NULL;
    
    game_board[0][0] = new Rook(0,0);
    game_board[0][0]->setColor('b');
    game_board[0][0]->setPos(0,0);
    temp.y = 0; 
    temp.x = 0; 
    BLocs.push_back(temp); 

    game_board[0][1] = new Knight(1,0);
    game_board[0][1]->setColor('b');
    game_board[0][1]->setPos(1,0);
    temp.y = 0; 
    temp.x = 1; 
    BLocs.push_back(temp);

    game_board[0][2] = new Bishop(2,0);
    game_board[0][2]->setColor('b');
    game_board[0][2]->setPos(2,0);
    temp.y = 0; 
    temp.x = 2; 
    BLocs.push_back(temp);

    game_board[0][3] = new Queen(3,0);
    game_board[0][3]->setColor('b');
    game_board[0][3]->setPos(3,0);
    temp.y = 0; 
    temp.x = 3; 
    BLocs.push_back(temp);

    game_board[0][4] = new King(4,0);
    game_board[0][4]->setColor('b');
    game_board[0][4]->setPos(4,0);
    temp.y = 0; 
    temp.x = 4; 
    BLocs.push_back(temp);

    game_board[0][5] = new Bishop(5,0);
    game_board[0][5]->setColor('b');
    game_board[0][5]->setPos(5,0);
    temp.y = 0; 
    temp.x = 5; 
    BLocs.push_back(temp);

    game_board[0][6] = new Knight(6,0);
    game_board[0][6]->setColor('b');
    game_board[0][6]->setPos(6,0);
    temp.y = 0; 
    temp.x = 6; 
    BLocs.push_back(temp);

    game_board[0][7] = new Rook(7,0);
    game_board[0][7]->setColor('b');
    game_board[0][7]->setPos(7,0);
    temp.y = 0; 
    temp.x = 7; 
    BLocs.push_back(temp);

    for(int i = 0; i < 8; ++i)
    {
        game_board[1][i] = new Pawn(1,i);
        game_board[1][i]->setColor('b');
        game_board[1][i]->setPos(1,i);
        temp.y = 1; 
        temp.x = i; 
        BLocs.push_back(temp); 
    }

    for(int i = 2; i < 6; ++i)
    {
        for(int j = 0; j < 8; ++i)
            game_board[i][j] = NULL;
    }

    game_board[7][0] = new Rook(0,7);
    game_board[7][0]->setColor('w');
    game_board[13][3]->setPos(0, 7);
    temp.x = 0;
    temp.y = 7;
    WLocs.push_back(temp);

    game_board[7][1] = new Knight(1,7);
    game_board[7][1]->setColor('w');
    game_board[7][1]->setPos(1, 7);
    temp.x = 1;
    temp.y = 7;
    WLocs.push_back(temp);

    game_board[7][2] = new Bishop(2,7);
    game_board[7][2]->setColor('w');
    game_board[7][2]->setPos(2, 7);
    temp.x = 2;
    temp.y = 7;
    WLocs.push_back(temp);

    game_board[7][3] = new Queen(3,7);
    game_board[7][3]->setColor('w');
    game_board[7][3]->setPos(3, 7);
    temp.x = 3;
    temp.y = 7;
    WLocs.push_back(temp);

    game_board[7][4] = new King(4,7);
    game_board[7][4]->setColor('w');
    game_board[7][4]->setPos(4, 7);
    temp.x = 4;
    temp.y = 7;
    WLocs.push_back(temp);

    game_board[7][5] = new Bishop(5,7);
    game_board[7][5]->setColor('w');
    game_board[7][5]->setPos(5, 7);
    temp.x = 5;
    temp.y = 7;
    WLocs.push_back(temp);

    game_board[7][6] = new Knight(6,7);
    game_board[7][6]->setColor('w');
    game_board[7][6]->setPos(6, 7);
    temp.x = 6;
    temp.y = 7;
    WLocs.push_back(temp);

    game_board[7][7] = new Rook(7,7);
    game_board[7][7]->setColor('w');
    game_board[7][7]->setPos(7, 7);
    temp.x = 7;
    temp.y = 7;
    WLocs.push_back(temp);
    
    for(int i = 0; i < 8; ++i)
    {
        game_board[6][i] = new Pawn(i,6);
        game_board[6][i]->setColor('w');
        game_board[6][i]->setPos(i, 6);
        temp.x = i;
        temp.y = 6;
        WLocs.push_back(temp);
    }

}

Chess::~Chess()
{
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
            delete game_board[i][j];
    }
}

vector<coord> Chess::PotentialMoves(const coord position) 
{
    cur_piece = game_board[position.y][position.x];
    if(cur_piece == NULL)
    {
        vector<coord> error;
        cerr << "Piece selected is not a piece" << endl;
        return error;
    }
    cur_piece->ValidMoves(position.y, position.x, cur_piece->getColor(), captureable, validPos, WLocs, BLocs);
    
    return validPos;
}

vector<coord> Chess::CaptureableMoves() const //SHOULD ONLY BE CALLED AFTER PotentialMoves()
{
    return captureable;
}
    
bool Chess::Move(const coord place) //SHOULD ONLY BE CALLED AFTER PotentialMoves()
{
    for(int i=0; i < validPos.size(); ++i)
    {
        if(validPos[i].x == place.x && validPos[i].y == place.y)//Found place we want to move
        {
            Piece* piece = game_board[place.y][place.x];
            if(piece== NULL)
            {
                if(cur_piece->getColor() == 'b') //Update BLocs
                {
                    coord temp = cur_piece->getPos();
                    for(int i = 0; i < BLocs.size(); ++i)
                    {
                        if((temp.x == BLocs[i].x) && (temp.y == BLocs[i].y))
                        {
                            BLocs[i].x = temp.x;
                            BLocs[i].y = temp.y;
                        }
                    }
                }
                else //Update WLocs
                {
                    coord temp = cur_piece->getPos();
                    for(int i = 0; i < WLocs.size(); ++i)
                    {
                        if((temp.x == WLocs[i].x) && (temp.y == WLocs[i].y))
                        {
                            WLocs[i].x = temp.x;
                            WLocs[i].y = temp.y;
                        }
                    }
                }

                piece = cur_piece;
                coord pos = piece->getPos();
                game_board[pos.y][pos.x] = NULL;
                game_board[place.y][place.x] = piece;
                cur_piece = NULL;

                return true;
            }

            else //Piece is enemy
            {
                if(piece->getColor() == 'b') //Update BLocs
                {
                    coord temp = piece->getPos();
                    for(int i = 0; i < BLocs.size(); ++i)
                    {
                        if((temp.x == BLocs[i].x) && (temp.y == BLocs[i].y))
                        {
                            BLocs[i].x = temp.x;
                            BLocs[i].y = temp.y;
                        }
                    }
                }
                else //Update WLocs
                {
                    coord temp = piece->getPos();
                    for(int i = 0; i < WLocs.size(); ++i)
                    {
                        if((temp.x == WLocs[i].x) && (temp.y == WLocs[i].y))
                        {
                            WLocs[i].x = temp.x;
                            WLocs[i].y = temp.y;
                        }
                    }
                }
                
                //Check cur_piece
                if(cur_piece->getColor() == 'b') //Update BLocs
                {
                    coord temp = cur_piece->getPos();
                    for(int i = 0; i < BLocs.size(); ++i)
                    {
                        if((temp.x == BLocs[i].x) && (temp.y == BLocs[i].y))
                        {
                            BLocs[i].x = temp.x;
                            BLocs[i].y = temp.y;
                        }
                    }
                }
                else //Update WLocs
                {
                    coord temp = cur_piece->getPos();
                    for(int i = 0; i < WLocs.size(); ++i)
                    {
                        if((temp.x == WLocs[i].x) && (temp.y == WLocs[i].y))
                        {
                            WLocs[i].x = temp.x;
                            WLocs[i].y = temp.y;
                        }
                    }
                }


                delete piece;
                piece = cur_piece;
                coord pos = piece->getPos();
                game_board[pos.y][pos.x] = NULL;
                game_board[place.y][place.x] = piece;
                cur_piece = NULL;
                return true;
            }
        }
    }
    return false;
}
    
    
    
    /*
    if(color == 'w')
    {
        for(int i = 0; i < validPos.size(); ++i)
        {
            for(int j = 0; j < WLocs.size(); ++j)
            {
                if(validPos.at(i) == WLocs.at(j)) //Did you find an Ally location thats still considered validPos? 
                {
                    int tmp_x = validPos.at(i).x; 
                    int tmp_y = validPos.at(i).y; //fix this 
                    Piece* tmp_Type = board[y][x];  
                    if(type == "Pawn")              
                    {                        
                        checkPawn(color, tmp_y, tmp_x); 
                    }
                    if(type == "Rook")
                    {
                        checkRook(color, tmp_y, tmp_x); 
                    }
                    if(type == "Knight")
                    {
                        checkKnight(color, tmp_y, tmp_x); 
                    }
                    if(type == "Bishop")
                    {
                        checkBishop(color, tmp_y, tmp_x); 
                    }
                    if(type == "King" || type == "Queen")
                    {
                        checkKing(color, tmp_y, tmp_x); 
                    }
                    
                    SeekandRemove(color, tmp_y, tmp_x); 
                }
        }
            for(k = 0; k < validPos.size(); ++k)
            {
                for(int g = 0; g < BLocs.size(); ++g)
                {
                    if(validPos.at(k) == BLocs.at(g))
                    {
                        int tmp_y = validPos.at(k).y; 
                        int tmp_x = validPos.at(k).x; 
                        OpponentExists(color, tmp_y, tmp_x, x, y);  
                    }
                    else
                        continue; 
                }    
            }
    }
}                                

bool isAlly(char color, int y, int x)
{
    Piece* tempPiece = board[y][x]; 
    
    if(tempPiece == NULL)
        return true; 
    if(
    string tempColor = tempPiece->GetColor(); 
    
    if(tempColor != color)
        return false;// 
    else
        return true; //check curr
}
                
void checkRook(char color, int y, int x)
{
    
    int tmp_y, tmp_x; 
        //move up
        for(int i=(y-1); i >= 0; --i)
        {
            tmp_y = i; 
            tmp_x = x;
            if(isAlly(color, tmp_y, tmp_x))
                SeekandRemove(color, tmp_y, tmp_x);
            else
                continue; 
        }
        //move down
        for(int i=(y+1); i < 8; ++i)
        { 
            tmp_y = i; 
            tmp_x = x;
            if(isAlly(color, tmp_y, tmp_x))
                SeekandRemove(color, tmp_y, tmp_x);
            else
                continue;
        }
        //down right
        for(int i = (x-1); i > 0; --i)
        {
            tmp_y = y; 
            tmp_x = i; 
            if(isAlly(color, tmp_y, tmp_x))
                SeekandRemove(color, tmp_y, tmp_x);
            else
                continue;
        }
        //move left
        for(int i=(x+1); i < 8; ++i)
        {
            tmp_y = y; 
            tmp_x = i; 
            if(isAlly(color, tmp_y, tmp_x))
                SeekandRemove(color, tmp_y, tmp_x);
            else
                enemyExists(tmp_y, tmp_x); 
        }
    }//end of isAlly

}

coord checkBishop(char color, int y, int x)
{
    int tmp_y = 1;
    int tmp_x = 1;  
    int checkY, checkX; 
    //diagonal up right 
    while((y-tmp_y) >= 0 && (x-tmp_x) >= 0)
    {
        checkY = y-tmp_y; 
        checkX = x-tmp_x; 
        if(isAlly(color, checkY, checkX))
            SeekandRemove(color, checkY, checkX); 

        ++tmp_y; 
        ++tmp_x; 
    }
    
    //diagonal up left
    while((y-tmp_y) >= 0 && (x+tmp_x) < 8)
    {
        checkY = y-tmp_y; 
        checkX = x+tmp_x; 
        if(isAlly(color, checkY, checkX))
            SeekandRemove(color, checkY, checkX); 

        ++tmp_y; 
        ++tmp_x; 
    }
    
    //diagonal down right
    while((y+tmp_y) < 8 && (x-tmp_x) >= 0)
    {
        checkY = y+tmp_y; 
        checkX = x-tmp_x; 
        if(isAlly(color, checkY, checkX))
            SeekandRemove(color, checkY, checkX); 

        ++tmp_y; 
        ++tmp_x; 
    }

    //diagonal down left
    while((y+tmp_y) >= 0 && (x+tmp_x) >= 0)
    {
        checkY = y-tmp_y; 
        checkX = x+tmp_x; 
        if(isAlly(color, checkY, checkX))
            SeekandRemove(color, checkY, checkX); 

        ++tmp_y; 
        ++tmp_x; 
    }
}

coord checkKing(char color, int y, int x)
{
    bool halfDone = false; 
    int tmp_y, tmp_x; 
    while(halfDone == false)
    {
        for(int i=(y-1); i >= 0; --i)
        {
            tmp_y = i; 
            tmp_x = x;
            if(isAlly(color, tmp_y, tmp_x))
                SeekandRemove(color, tmp_y, tmp_x);
            else
                continue; 
        }
        //move down
        for(int i=(y+1); i < 8; ++i)
        { 
            tmp_y = i; 
            tmp_x = x;
            if(isAlly(color, tmp_y, tmp_x))
                SeekandRemove(color, tmp_y, tmp_x);
            else
                continue;
        }
        //down left
        for(int i=(x+1); i < 8; ++i)
        {
            tmp_y = y; 
            tmp_x = i; 
            if(isAlly(color, tmp_y, tmp_x))
                SeekandRemove(color, tmp_y, tmp_x);
            else
                continue;
        }
        //move right
        for(int i =(x-1); i >= 0; --i)
        {
            tmp_y = y; 
            tmp_x = i; 
            if(isAlly(color, tmp_y, tmp_x))
                SeekandRemove(color, tmp_y, tmp_x);
            else
                continue;
        }

        halfDone == true; 
    }


    tmp_y, tmp_x = 1;
    int checkY, checkX; 
    //diagonal up right 
    while((y-tmp_y) >= 0 && (x-tmp_x) >= 0)
    {
        checkY = y-tmp_y; 
        checkX = x-tmp_x; 
        if(isAlly(color, checkY, checkX))
            SeekandRemove(color, checkY, checkX); 

        ++tmp_y; 
        ++tmp_x; 
    }
    
    //diagonal up left
    while((y-tmp_y) >= 0 && (x+tmp_x) < 8)
    {
        checkY = y-tmp_y; 
        checkX = x+tmp_x; 
        if(isAlly(color, checkY, checkX))
            SeekandRemove(color, checkY, checkX); 

        ++tmp_y; 
        ++tmp_x; 
    }
    
    //diagonal down right
    while((y+tmp_y) < 8 && (x-tmp_x) >= 0)
    {
        checkY = y+tmp_y; 
        checkX = x-tmp_x; 
        if(isAlly(color, checkY, checkX))
            SeekandRemove(color, checkY, checkX); 

        ++tmp_y; 
        ++tmp_x; 
    }

    //diagonal down left
    while((y+tmp_y) < 8 && (x+tmp_x) < 8)
    {
        checkY = y-tmp_y; 
        checkX = x+tmp_x; 
        if(isAlly(color, checkY, checkX))
            SeekandRemove(color, checkY, checkX); 

        ++tmp_y; 
        ++tmp_x; 
    }

}


coord checkKnight(char color, int y, int x)
{
    int y2, x2 = 2; 
    int y1, x1 = 1; 
    int checkX, checkY; 
    //up 2, right 1
    while((y-y2) >= 0 && (x-x1) >= 0)
    {
        checkY = y-y2; 
        checkX = x-x1; 

        if(isAlly(color, checkY, checkX))
            SeekandRemove(color, checkY, checkX); 

        y2 = y2+2; 
        x1 = x1+1; 
    }
    //up 1, right 2
    while((y-y1) >= 0 && (x-x2) >= 0)
    {
        checkY = y-y1; 
        checkX = x-x2; 

        if(isAlly(color, checkY, checkX))
            SeekandRemove(color, checkY, checkX); 

        y1 = y1+1; 
        x2 = x2+2; 
    }

    //up 2, left 1
    while((y-y2) >= 0 && (x+x1) < 8)
    {
        checkY = y-y2; 
        checkX = x+x1; 

        if(isAlly(color, checkY, checkX))
            SeekandRemove(color, checkY, checkX); 

        y2 = y2+2; 
        x1 = x1+1; 
    }
    //up 1, left 2
    while((y-y1) >= 0 && (x+x2) < 8)
    {
        checkY = y-y1; 
        checkX = x+x2; 

        if(isAlly(color, checkY, checkX))
            SeekandRemove(color, checkY, checkX); 

        y1 = y1-1; 
        x2 = x2+2; 
    }
    //down 2, left 1
    while((y+y2) < 8 && (x+x1) < 8)
    {
        checkY = y+y2; 
        checkX = x+x1; 

        if(isAlly(color, checkY, checkX))
            SeekandRemove(color, checkY, checkX); 

        y2 = y2+2; 
        x1 = x1+1; 
    }

    //down 1, left 2
    while((y+y1) < 8 && (x+x2) < 8)
    {
        checkY = y+y1;
        checkX = x+x2; 

        if(isAlly(color, checkY, checkX))
            SeekandRemove(color, checkY, checkX); 

        y1 = y1+1; 
        x2 = x2+2; 
    }

    //down 2, right 1
    while((y+y2) < 8 && (x-x1) >= 0)
    {
        checkY = y+y2; 
        checkX = x-x1; 

        if(isAlly(color, checkY, checkX))
            SeekandRemove(color, checkY, checkX); 

        y2 = y2+2; 
        x1 = x1-1; 
    }

    //down 1, right 2
    while((y+y1) < 8 && (x-x2) >= 0)
    {
        checkY = y-y1; 
        checkX = x-x2; 

        if(isAlly(color, checkY, checkX))
            SeekandRemove(color, checkY, checkX); 

        y1 = y1+1; 
        x2 = x2+2; 
    }

}



coord checkQueen(char color, int y, int x)
{
}
coord checkPawn(char color, int y, int x)
{
    //only moving up
    if(color == 'w')
    {
        for(int i=(y-1); i >= 0; --i)
        {
            tmp_y = i; 
            tmp_x = x;
            if(isAlly(color, tmp_y, tmp_x))
                SeekandRemove(color, tmp_y, tmp_x);
            else
                continue; 
        }
    }
    else
    {
        for(int i = (y+1); i < 8; ++i)
        {
            tmp_y = i; 
            tmp_x = x;
            if(isAlly(color, tmp_y, tmp_x))
                SeekandRemove(color, tmp_y, tmp_x);
            else
                continue; 
        }
        
    }
}
*/
