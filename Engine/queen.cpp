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
void Queen::Move(const coord posiiton)
{
  //Check if valid move, then: 
  m_position = position;
}

char Queen::getTmpColor(int y, int x, vector<coord> WLocs, vector<coord> BLocs)
{
    coord tmp; 
    char b, w, e; 
    for(int b = 0; b < BLocs.size(); ++b)
    {
        if((tmp.y == BLocs[b].y) && (tmp.x == BLocs[b].x)) 
            return 'b'; 
        else
            continue; 
    }
    for(int w = 0; w < WLocs.size(); ++w)
    {
        if((tmp.y == WLocs[w].y) && (tmp.x == WLocs[w].x))
            return 'w'; 
        else
            continue; 
    }
    return 'e'; 
}

bool Queen::isAlly(int y, int x, char myColor)
{
    char TmpColor = getTmpColor(y,x); 

    if(TmpColor = myColor); 
        return true;
    else
        return false; 
}

bool Queen::isEnemy(int y, int x, char myColor)
{
    char TmpColor = getTmpColor(y, x); 

    if(TmpColor != myColor) 
        return true; 
    else 
        return false; 
}

bool Bishop::isEmpty(int y, int x)
{
    char TmpColor = getTmpColor(y, x); 

    if(tmpColor = 'e')
        return true; 
    else 
        return false; 
}

void Queen::ValidMoves(int cp.y, int cp.x, &vector<coord>captureable, &vector<coord>validPos)
{
    coord car, valid; 
    int temp.y = cp.y; 
    int temp.x = cp.x; 
    vector<coord> set; 
    //Moving vertically towards "top" of the board: 
    while((temp.y) >= 0)
    {
        temp.y -= 1; 
         
        if(isAlly(temp.y, temp.x))
            break; 
        if(isEmpty(temp.y, temp.x))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }

        temp.y-=1; 
    }
	//Moving vertically towards "bottom" of board:
    while((temp.y) < 8)
    {
        temp.y += 1; 
        temp.x = cp.x; 

        if(isAlly(temp.y, temp.x))
            break; 
        if(isEmpty(temp.y, temp.x))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.y+=1;
    }   
	//Moving horizontally towards "right" of board:
    while((temp.x) >= 0)
    {
        temp.y = cp.y; 
        temp.x -= 1; 
        
        if(isAlly(temp.y, temp.x))
            break; 
        if(isEmpty(temp.y, temp.x))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
         if(isEnemy(temp.y, temp.x) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.y-=1;
    }
	//Moving horizontally towards "left" of board:
    while(temp.x < 8)
    {
        temp.y = cp.y; 
        temp.x += cp.x; 
        if(isAlly(temp.y, temp.x))
            break; 
        if(isEmpty(temp.y, temp.x))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.y-=1;
    }
	//Moving diagonally towards "top right" of board:
    while((temp.y >= 0) && (temp.x) >= 0)
    {
        temp.y -= 1; 
        temp.x -= 1; 
        if(isAlly(temp.y, temp.x))
            break; 
        if(isEmpty(temp.y, temp.x))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.y-=1;
        temp.x-=1; 
    }
	//Moving diagonally towards "top left" of board:
    while((temp.y) >= 0 && (temp.x) < 8)
    {
        temp.y -= 1;
        temp.x += 1; 

        if(isAlly(temp.y, temp.x))
            break; 
        if(isEmpty(temp.y, temp.x))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.y -=1;
        temp.x +=1; 
    }
	//Moving diagonally towards "bottom right" of board:
    while((temp.y < 8) && (temp.x >= 0))
    {
        temp.y += 1; 
        temp.x -= 1; 
        if(isAlly(temp.y, temp.x))
            break; 
        if(isEmpty(temp.y, temp.x))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.y += 1;
        temp.x -= 1; 
    }
	//Moving diagonally towards "bottom left" of board:
    while((temp.y < 8) && (temp.x < 8))
    {
        temp.y += 1; 
        temp.x += 1; 

        if(isAlly(temp.y, temp.x))
            break; 
        if(isEmpty(temp.y, temp.x))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x) 
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
            break; 
        }
        temp.y +=1;       
        temp.x +=1; 
    }
}
