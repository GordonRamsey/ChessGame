#include "knight.h"
using namespace std;

Knight::Knight(int x, int y) : Piece(x, y)
{
    m_name = "Knight";
}

Knight::~Knight()
{}

char Knight::getTmpColor(int y, int x, vector<coord>WLocs, vector<coord>BLocs)
{
    coord temp;
    temp.y = y; 
    temp.x = x; 
    for(int b = 0; b < BLocs.size(); ++b)
    {
        if((temp.y == BLocs[b].y) && (temp.x == BLocs[b].x))
            return 'b'; 
        else
            continue; 
    }
    for(int w = 0; w < WLocs.size(); ++w)
    {
        if((temp.y == WLocs[w].y) && (temp.x == WLocs[w].x))
            return 'w';
        else 
            continue;
    }
    
    return 'e'; 
}

bool Knight::isAlly(int y, int x, char myColor, vector<coord> WLocs, vector<coord> BLocs)
{
    char TmpColor = getTmpColor(y,x, WLocs, BLocs); 
    if(TmpColor == myColor)
        return true; 
    else 
        return false;
}

bool Knight::isEnemy(int y, int x, char myColor, vector<coord> WLocs, vector<coord> BLocs)
{
    char TmpColor = getTmpColor(y,x, WLocs, BLocs); 
    if(TmpColor != myColor)
        return true; 
    else
        return false; 
}

bool Knight::isEmpty(int y, int x, vector<coord> WLocs, vector<coord> BLocs)
{
    char TmpColor = getTmpColor(y,x, WLocs, BLocs); 
    if(TmpColor == 'e')
        return true; 
    else
        return false;
}

void Knight::ValidMoves(int cp_y, int cp_x, char myColor, vector<coord> &captureable, vector<coord> &validPos, vector<coord>WLocs, vector<coord>BLocs)
{
    coord cap, valid, temp; 
    //up 2, right 1
    temp.y = cp_y-2; 
    temp.x = cp_x+1;
    if((temp.y >= 0) && (temp.x >= 0) && (temp.y < 8) && (temp.x < 8))
    {
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(cap); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap);
        }
    }
    //up 1, right 2
    temp.y = cp_y-1;
    temp.x = cp_x+2;
    if((temp.y >= 0) && (temp.x >= 0) && (temp.y < 8) && (temp.x <8))
    {
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(cap); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap);
        }
    }
    //down 2, right 1
    temp.y = cp_y+2;
    temp.x = cp_x+1;
    if((temp.y < 8) && (temp.x >= 0) && (temp.y < 8) && (temp.x < 8))
    {
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(cap); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap);
        }
    }
    //down 1, right 2
    temp.y = cp_y+1;
    temp.x = cp_x+2;
    if((temp.y < 8) && (temp.x >= 0) && (temp.y >= 0) && (temp.x < 8))
    {
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(cap); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap);
        }
    }
    //up 2, left 1
    temp.y = cp_y-2;
    temp.x = cp_x-1;
    if((temp.y >= 0) && (temp.x < 8) && (temp.y < 8) && (temp.x >= 0))
    {
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(cap); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap);
        }
    }
    //up 1, left 2
    temp.y = cp_y-1;
    temp.x = cp_x-2;
    if((temp.y >= 0) && (temp.x < 8) && (temp.y < 8) && (temp.x >= 0))
    {
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(cap); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap);
        }
    }
    //down 2, left 1 
    temp.y = cp_y+2;
    temp.x = cp_x-1;
    if((temp.y < 8) && (temp.x < 8) && (temp.y >= 0) && (temp.x >= 0))
    {
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(cap); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap);
        }
    }
    //down 1, left 2
    temp.y = cp_y+1;
    temp.x = cp_x-2;
    if((temp.y < 8) && (temp.x < 8) && (temp.y >= 0) && (temp.x >= 0))
    {
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(cap); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap);
        }
    }
}

string Knight::getName() const
{
    return m_name;
}

void Knight::setName(const string name)
{
    m_name = name;
}


