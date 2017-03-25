#include "knight.h"
using namespace std;

Knight::Knight()
{
    m_name = "Knight";
}

Knight::~Knight()
{}

char Knight::getTmpColor(int y, int, x, vector<coord>WLocs, vector<coord>BLocs)
{
    int temp.y = y; 
    int temp.x = x; 
    for(int b = 0; b < BLocs.size(); ++b)
    {
        if((temp.y == BLocs[b].y) && (temp.x == BLocs[b].x))
            return 'b'; 
        else
            continue; 
    }
    for(int w = 0; w < WLocs.size(); ++w)
    {
        if((temp.y == WLocs[w].y) && (temp.x == BLocs[b].x))
            return 'w';
        else 
            continue;
    }
    
    return 'e'; 
}

bool Knight::isAlly(int y, int x, char myColor)
{
    char TmpColor = getTmpColor(y,x); 
    if(TmpColor == myColor)
        return true; 
    else 
        return false
}

bool Knight::isEnemy(int y, int x, char myColor)
{
    char TmpColor = getTmpColor(y,x); 
    if(TmpColor != myColor)
        return true; 
    else
        return false; 
}

bool Knight::isEmpty(int y, int x)
{
    char TmpColor = getTmpColor(y,x); 
    if(TmpColor == 'e')
        return true; 
    else
        return false;
}

void Knight::ValidMoves(int cp.y, int cp.x, vector<coord>WLocs, vector<coord>BLocs)
{
    coord cap, valid; 
    int temp.y = cp.y; 
    int temp.x = cp.x; 
    //up 2, right 1(w) AND  down 2, left 1(b)
    while((temp.y >= 0) && (temp.x >= 0))
    {
        temp.y = temp.y-2; 
        temp.x = temp.x-1;
        if(isAlly(temp.y, temp.x))
            break;
        if(isEmpty(temp.y, temp.x)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(cap); 
        }
        if(isEnemy(temp.y, temp.x)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap);
            break; 
        }
        temp.y = temp.y-2; 
        temp.x = temp.x-1; 
    }
    //up 1, right 2 AND down 1, left 2(b)
    while((temp.y >= 0) && (temp.x >= 0))
    {
        temp.y = temp.y-1; 
        temp.x = temp.x-2;
        if(isAlly(temp.y, temp.x))
            break;
        if(isEmpty(temp.y, temp.x)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(cap); 
        }
        if(isEnemy(temp.y, temp.x)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap);
            break; 
        }
        temp.y = temp.y-1; 
        temp.x = temp.x-2; 

    }
    //down 2, right 1 AND up 2, left 1(b)
    while((temp.y < 8) && (temp.x >= 0)
    {
        temp.y = temp.y+2; 
        temp.x = temp.x-1;
        if(isAlly(temp.y, temp.x))
            break;
        if(isEmpty(temp.y, temp.x)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(cap); 
        }
        if(isEnemy(temp.y, temp.x)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap);
            break; 
        }
        temp.y = temp.y+2; 
        temp.x = temp.x-1; 
    }
    //down 1, right 2 AND up 1, left 2(b)
    while((temp.y < 8) && (temp.x >= 0))
    {
        temp.y = temp.y+1; 
        temp.x = temp.x-2;
        if(isAlly(temp.y, temp.x))
            break;
        if(isEmpty(temp.y, temp.x)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(cap); 
        }
        if(isEnemy(temp.y, temp.x)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap);
            break; 
        }
        temp.y = temp.y+1; 
        temp.x = temp.x-2; 
    }
    //up 2, left 1 AND down 1, right 2(b)
    while((temp.y >= 0) && (temp.x < 8))
    {
        temp.y = temp.y-2; 
        temp.x = temp.x+1;
        if(isAlly(temp.y, temp.x))
            break;
        if(isEmpty(temp.y, temp.x)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(cap); 
        }
        if(isEnemy(temp.y, temp.x)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap);
            break; 
        }
        temp.y = temp.y-2; 
        temp.x = temp.x+1; 

    }
    //up 1, left 2 AND down 1, right 2(b)
    while((temp.y >= 0) && (temp.x < 8))
    {
        temp.y = temp.y-1; 
        temp.x = temp.x+2;
        if(isAlly(temp.y, temp.x))
            break;
        if(isEmpty(temp.y, temp.x)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(cap); 
        }
        if(isEnemy(temp.y, temp.x)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap);
            break; 
        }
        temp.y = temp.y-1; 
        temp.x = temp.x+2; 

    }
    //down 2, left 1 AND up 2, right 1(b)
    while((temp.y < 8) && (temp.x < 8))
    {
        temp.y = temp.y+2; 
        temp.x = temp.x+1;
        if(isAlly(temp.y, temp.x))
            break;
        if(isEmpty(temp.y, temp.x)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(cap); 
        }
        if(isEnemy(temp.y, temp.x)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap);
            break; 
        }
        temp.y = temp.y+2; 
        temp.x = temp.x+1; 
    }
    //down 1, left 2 AND up 1, right 2(b)
    while((temp.y < 8) && (temp.x < 8))
    {
        temp.y = temp.y+1; 
        temp.x = temp.x+2;
        if(isAlly(temp.y, temp.x))
            break;
        if(isEmpty(temp.y, temp.x)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(cap); 
        }
        if(isEnemy(temp.y, temp.x)) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap);
            break; 
        }
        temp.y = temp.y+1; 
        temp.x = temp.x+2; 
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

void Knight::Move(const string posiiton)
{
	//Check isValid first, then:
  	setPosition(position);
}

