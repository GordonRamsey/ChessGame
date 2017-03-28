#include "rook.h"
using namespace std;

Rook::Rook()
{
    m_name = "Rook"; 
}

Rook::~Rook()
{}

/*char Rook::getTmpcolor(int y, int x, vector<coord> WLocs, vector<coord> BLocs)
{
    coord tmp; 
    char b, w, e; 
    for(int b = 0; b < BLocs.size(); ++b)
    {
        if((tmp.y == BLocs[b].y) && (tmp.x == BLocs[b].x))
            return 'b'; 
    }
    for(int w = 0; w < WLocs.size(); ++w)
    {
        if((tmp.y == WLocs[w].y) && (tmp.x == BLocs[w].y))
                return 'w'; 
    }
    return 'e'; 
    
}

bool Rook::isAlly(int y, int x, char myColor, vector<coord> WLocs, vector<coord> BLocs)
{
    char TmpColor = getTmpColor(int y, int x, WLocs, BLocs);

    if(myColor == TmpColor)
        return true;
    else
        return false;
}

bool Rook::isEnemy(int y, int x, char myColor, vector<coord> WLocs, vector<coord> BLocs)
{
    char TmpColor = getTmpColor(int y, int x, WLocs, BLocs);

    if(TmpColor != myColor)
        return true; 
    else 
        return false; 
}

bool Rook::isEmpty(int y, int x, vector<coord> WLocs, vector<coord> BLocs)
{
    char TmpColor = getTmpcolor(int y, int x, WLocs, BLocs);
    
    if(tmpColor == 'e')
        return true; 
    else
        return false; 
}

void Rook::ValidMoves(int cp.y, int cp.x, char myColor, &vector<coord> captureable, &vector<coord> validPos, vector<coord>WLocs, vector<coord> BLocs)
{
    coord temp, cap, valid; 
    temp.y = cp_y-1; 
    temp.x = cp_x; 
    //move up(w) down(b)
    while(temp.y >= 0)
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
            valid.push_back(cap); 
            break; 
        }

        temp.y -= 1;
    }
    temp.y = cp_y+1;
    //move down(w) up(b)
    while(temp.y < 8)
    {

        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if((isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            valid.push_back(cap); 
            break; 
        }

        temp.y += 1; 
    }
    temp.y = cp_y;
    temp.x=cp_x-1;
    //move right(w) left(b)
    while(temp.x >= 0)
    {

        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEmpty(temp.y, temp.x, myColor, WLocs, BLocs))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            valid.push_back(cap); 
            break; 
        }

        temp.x-=1;
    }
    temp.x = cp_x+1;
    //move left(w) right(w)
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
        if(isEmpty(temp.y, temp.x, myColor, WLocs, BLocs))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            valid.push_back(cap); 
            break; 
        }

        temp.x+=1; 
}
*/
vector<coord> Rook::ValidMoves(Piece* board[8][8])
{
    coord temp, cur;
    vector<coord> positions;
    cur = this->getPos();


    //move up
    temp.y = cur.y-1;
    temp.x = cur.x;
    while(temp.y >= 0)
    {
        Piece* piece = board[temp.y][temp.x];
        if(piece == NULL) //Space is empty, add it and continue
        {
            positions.push_back(temp);
            temp.y -= 1;
        }

        else
        {
            if(piece->getColor() == m_color) //Found Ally, so stop looping
                break;
            else //Found enemy, so add it and stop looping
            {
                positions.push_back(temp);
                break;
            }
        }
    }

    temp.y = cur.y+1;
    //move down
    while(temp.y < 8)
    {
        Piece* piece = board[temp.y][temp.x];
        if(piece == NULL)
        {
            positions.push_back(temp);
            temp.y +=1;
        }

        else
        {
            if(piece->getColor() == m_color)
                break;
            else
            {
                positions.push_back(temp);
                break;
            }
        }
    }
    temp.y = cur.y;
    temp.x= cur.x-1;
    //move left
    while(temp.x >= 0)
    {
        Piece* piece = board[temp.y][temp.x];
        if(piece == NULL_
        {
            positions.push_back(temp);
            temp.x -=1;
        }
        else
        {
            if(piece->getColor() == m_color)
                break;
            else
            {
                positions.push_back(temp);
                break;
            }
        }
    }

    temp.x = cur.x+1;
    //move right
    while(temp.x < 8)
    {
        Piece* piece = board[temp.y][temp.x];
        if(piece == NULL)
        {
            positions.push_back(temp);
            temp.x +=1;
        }
        else
        {
            if(piece->getColor() == m_color)
                break;
            else
            {
                positions.push_back(temp);
                break;
            }
        }
    }
    return positions;
}

string Rook::getName() const
{
    return m_name; 
}

string Rook::setName(const string name)
{
    m_name = name; 
}
