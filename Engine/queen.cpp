#include "queen.h"
using namespace std;

Queen::Queen()
{
    m_name = "Queen";
}

Queen::~Queen()
{}

string Queen:getName() const
{
    return m_name;
}

void Queen::setName(const string name)
{
    m_name = name;
}


char Queen::getTmpColor(int y, int x, vector<coord> WLocs, vector<coord> BLocs)
{
    coord tmp;
    tmp.y = y;
    tmp.x = x;
    for(int w = 0; w < WLocs.size(); ++w)
    {
        if((tmp.y == YLocs[w].y) && (tmp.x == YLocs[w].x))
            return 'w';
    }
    for(int b = 0; b < BLocs.size(); ++b)
    {
        if((tmp.y == BLocs[b].y) && (tmp.x == BLocs[b].x)) 
            return 'b'; 
    }
    return 'e'; 
}

bool Queen::isAlly(int y, int x, char myColor, vector<coord> WLocs, vector<coord> BLocs)
{
    char TmpColor = getTmpColor(y, x, WLocs, BLocs); 

    if(TmpColor = myColor); 
        return true;
    else
        return false; 
}

bool Queen::isEnemy(int y, int x, char myColor, vector<coord> WLocs, vector<coord> BLocs)
{
    char TmpColor = getTmpColor(y, x, WLocs, BLocs); 

    if(TmpColor != myColor) 
        return true; 
    else 
        return false; 
}

bool Queen::isEmpty(int y, int x, vector<coord> WLocs, vector<coord> BLocs)
{
    char TmpColor = getTmpColor(y, x, WLocs, BLocs); 

    if(tmpColor = 'e')
        return true; 
    else 
        return false; 
}

void Queen::ValidMoves(int cp_y, int cp_x, char myColor, &vector<coord>captureable, &vector<coord>validPos, vector<coord> WLocs, vector<coord> BLocs)
{
    coord temp, cap, valid; 
    temp.y = cp_y-1; 
    temp.x = cp_x; 
    vector<coord> set; 

    //Moving vertically towards "top" of the board: 
    while((temp.y >= 0)
    {
         
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }

        temp.y -= 1; 
    }
    temp.y = cp_y+1;
	//Moving vertically towards "bottom" of board:
    while((temp.y) < 8)
    {

        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.y += 1; 
    }   
    temp.y = cp_y;
    temp.x = cp_x+1;
	//Moving horizontally towards "right" of board:
    while((temp.x) >= 0)
    {
        
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
         if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.x += 1; 
    }
    temp.x = cp_x-1;
	//Moving horizontally towards "left" of board:
    while(temp.x < 8)
    {
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.x -= 1; 
    }
    temp.y = cp_y-1;
    temp.x = cp_x+1;
	//Moving diagonally towards "top right" of board:
    while((temp.y >= 0) && (temp.x) >= 0)
    {
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.y-=1;
        temp.x+=1; 
    }
	//Moving diagonally towards "top left" of board:
    temp.y = cp_y-1;
    temp.y = cp_x-1;
    while((temp.y) >= 0 && (temp.x) < 8)
    {

        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.y -=1;
        temp.x -=1; 
    }
	//Moving diagonally towards "bottom right" of board:
    temp.y = cp_y+1;
    temp.x = cp_x+1;
    while((temp.y < 8) && (temp.x >= 0))
    {
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.y += 1;
        temp.x += 1; 
    }
	//Moving diagonally towards "bottom left" of board:
    temp.y = cp_y+1;
    temp.x = cp_x-1;
    while((temp.y < 8) && (temp.x < 8))
    {

        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.y +=1;       
        temp.x -=1; 
    }
}

/*
void Queen::ValidMoves(Piece* board[8][8])
{
    coord cur, temp;
    cur = this->getPos();
    temp = pos;
    temp.y = cur.y-1; 
    vector<coord> position; 

    //Moving up
    while(temp.y >= 0)
    {
        Piece* piece = board[temp.y][temp.x];
        if(piece == NULL) //Place on board is empty, add it and continue
        {
            position.push_back(temp);
            temp.y -= 1;
        }
        else //It's a piece
        {
            if(piece->getColor() == m_color) //It's an allied piece
                break;

            else
            {
                position.push_back(temp);
                break;
            }
        }
    }

    //Moving down
    temp.y = cur.y+1;
    while(temp.y < 8)
    {
        Piece* piece = board[temp.y][temp.x];
        if(piece == NULL)
        {
            position.push_back(temp);
            temp.y += 1;
        }
        else
        {
            if(piece->getColor() == m_color)
                break;
            else
            {
                position.push_back(temp);
                break;
            }
        }
    }
    
    //Moving left
    temp.y = cur.y;
    temp.x = cur.x-1;
    while(temp.x >= 0)
    {
        Piece* piece = board[temp.y][temp.x];
        if(piece == NULL)
        {
            position.push_back(temp);
            temp.x -= 1;
        }
        else
        {
            if(piece->getColor() == m_color)
                break;
            else
            {
                position.push_back(temp);
                break;
            }
        }
    }
    
    //Moving right
    temp.x = cur.x+1;
    while(temp.x < 8)
    {
        Piece* piece = board[temp.y][temp.x];
        if(piece == NULL)
        {
            position.push_back(temp);
            temp.x += 1;
        }
        else
        {
            if(piece->getColor() == m_color)
                break;
            else
            {
                position.push_back(temp);
                break;
            }
        }
    }

    //Moving up and left diagonally
    temp.y = cur.y-1;
    temp.x = cur.x-1;
    while(temp.y >= 0 && temp.x >= 0)
    {
        Piece piece = board[temp.y][temp.x];
        if(piece == NULL)
        {
            position.push_back(temp);
            temp.y -= 1;
            temp.x -= 1;
        }
        else
        {
            if(piece->getColor() == m_color)
                break;
            else
            {
                position.push_back(temp);
                break;
            }
        }
    }

    //Moving up and right diagonally
    temp.y = cur.y-1;
    temp.x = cur.x+1;
    while(temp.y >= 0 && temp.x < 8)
    {
        Piece* piece = board[temp.y][temp.x];
        if(piece == NULL)
        {
            position.push_back(temp)
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }

        temp.y -= 1; 
    }
    temp.y = cp_y+1;
	//Moving vertically towards "bottom" of board:
    while((temp.y) < 8)
    {

        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.y += 1; 
    }   
    temp.y = cp_y;
    temp.x = cp_x+1;
	//Moving horizontally towards "right" of board:
    while((temp.x) >= 0)
    {
        
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
         if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.x += 1; 
    }
    temp.x = cp_x-1;
	//Moving horizontally towards "left" of board:
    while(temp.x < 8)
    {
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.x -= 1; 
    }
    temp.y = cp_y-1;
    temp.x = cp_x+1;
	//Moving diagonally towards "top right" of board:
    while((temp.y >= 0) && (temp.x) >= 0)
    {
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.y-=1;
        temp.x+=1; 
    }
	//Moving diagonally towards "top left" of board:
    temp.y = cp_y-1;
    temp.y = cp_x-1;
    while((temp.y) >= 0 && (temp.x) < 8)
    {

        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.y -=1;
        temp.x -=1; 
    }
	//Moving diagonally towards "bottom right" of board:
    temp.y = cp_y+1;
    temp.x = cp_x+1;
    while((temp.y < 8) && (temp.x >= 0))
    {
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.y += 1;
        temp.x += 1; 
    }
	//Moving diagonally towards "bottom left" of board:
    temp.y = cp_y+1;
    temp.x = cp_x-1;
    while((temp.y < 8) && (temp.x < 8))
    {

        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.y +=1;       
        temp.x -=1; 
    }
}
*/
