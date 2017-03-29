#include "bishop.h"
using namespace std;

Bishop::Bishop()
{
    m_name = "Bishop";
}

Bishop::~Bishop()
{}

string Bishop::getName() const
{
    return m_name;
}

void Bishop::setName(const string name)
{
    m_name = name;
}

char Bishop::getTmpColor(int y, int x, vector<coord> WLocs, vector<coord> BLocs)
{
    char b, w, e; //E MEANS EMPTY
    int temp.y = y;
    int temp.x = x; 
    for(int b = 0; b < BLocs.size(); ++b)
    {
        if((temp.y == BLocs[b].y) && (temp.x == BLocs[b].x))
                return 'b';
    }
    for(int w = 0; w < WLocs.size(); ++w)
    {
        if((temp.y == WLocs[w].y) && (temp.x == BLocs[w].y))
            return 'w'
    }
    else 
        return 'e'; 
}

bool Bishop::isAlly(int y, int x, char myColor, vector<coord>WLocs, vector<coord>BLocs)
{
    char TmpColor = getTmpColor(y,x, WLocs, BLocs); 
    
    if(myColor == TmpColor) 
        return true; 
    else
        return false; 
}

/* Here is where you are going to want to (1) go into chess.cpp and take the type, (2)check to see if it is a King so that we can (3)pass it in to our object 'info' to call checkmate */
bool Bishop::isEnemy(int y, int x, char myColor, vector<coord>WLocs, vector<coord>BLocs)
{
    char TmpColor = getTmpColor(y,x, WLocs, BLocs); 

    if(TmpColor != myColor) 
        return true; 
    else
        return false; 
}

bool Bishop::isEmpty(int y, int x, vector<coord>WLocs, vector<coord>BLocs)
{
    char TmpColor = getTmpColor(y, x, WLocs, BLocs); 

    if(tmpColor == 'e') 
        return true; 
    else 
        return false; 
}

void Bishop::ValidMoves(int cp_y, int cp_x, &vector<coord> captureable, &vector<coord>validPos, vector<coord> WLocs, vector<coord> BLocs)
{
    coord cap, valid, temp;
    temp.y = cp_y-1; 
    temp.x = cp_x-1; 
    //Move Diagonal up and left
    while((temp.y && temp.x) >= 0)
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
        temp.x -= 1;

    }

    //Move Diagonal down and left
    temp.y = cp_y+1;
    temp.x = cp_x-1;
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
        if(isEnemy(temp.y, temp.x. myColor, WLocs, BLocs))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap);
            valid.push_back(cap); 
            break; 
        }

        temp.y += 1;  
        temp.x -= 1; 
       
    }   
    //Move Diagonal up and right
    temp.y = cp_y-1;
    temp.x = cp_x+1;
    while((temp.y >= 0) && (temp.x < 8))
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
        temp.x += 1; 

    }   
    //Move Diagonal down and right
    temp.y = cp_y+1;
    temp.x = cp_x+1;
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
            valid.push_back(cap); 
            break; 
        }

        temp.y += 1; 
        temp.x += 1; 

    }        
}

