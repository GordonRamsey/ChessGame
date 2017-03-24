#include "bishop.h"
using namespace std;

char Bishop::getTmpcolor(int y, int x, vector<coord> WLocs, vector<coord> BLocs)
{
    coord tmp;
    char b, w, e; //E MEANS EMPTY
    for(int b = 0; b < BLocs.size(); ++b)
    {
        for(int w = 0; w < WLocs.size(); ++w)
        {
            if((tmp.y == BLocs[b].y) && (tmp.x == BLocs[b].x))
                return 'b';
            if((tmp.y == WLocs[w].y) && (tmp.x == BLocs[w].y))
                return 'w'
            else 
                return 'e'; 
        }
    }

}

bool Bishop::isAlly(int y, int x)
{
    char TmpColor = getTmpColor(int y, int x); 
    
    if(myColor == TmpColor) 
        return true; 
    else
        return false; 
}

/* Here is where you are going to want to (1) go into chess.cpp and take the type, (2)check to see if it is a King so that we can (3)pass it in to our object 'info' to call checkmate */
bool Bishop::isEnemy(int y, int x)
{
    char TmpColor = getTmpColor(int y, int x); 

    if(TmpColor != myColor) 
        return true; 
    else
        return false; 
}

bool Bishop::isEmpty(int y, int x)
{
    char TmpColor = getTmpcolor(int y, int x); 

    if(tmpColor == 'e') 
        return true; 
    else 
        return false; 
}

void Bishop::validMoves(int cp.y, int cp.x, &vector<coord> captureable, &vector<coord>validPos)
{
    coord temp, cap, valid;
    temp.y = cp.y;
    temp.x = cp.x; 

    //Move Diagonal up, right(w) AND down, left(b)  
    while((temp.y && temp.x) >= 0)
    {
        temp.y -= 1; 
        temp.x -= 1; 
            
        (isAlly(temp.y, temp.x))
            break; 
        if(isEmpty(temp.y, temp.x))
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            validPos.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap);
            valid.push_back(cap); 
            break; 
        }

        temp.y = temp.y - 1; 
        temp.x = temp.x - 1; 
    }

    //Move Diagonal down, right(w) AND up, left(b)
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
        if(isEnemy(temp.y, temp.x))
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
    //Move Diagonal up, left(w) AND down, right(b)
    while((temp.y <= 0) && (temp.x < 8))
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
        if(isEnemy(temp.y, temp.x))
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
    //Move Diagonal down, left(w) AND up, right(b)
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
        if(isEnemy(temp.y, temp.x))
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

void Bishop::Move(const string posiiton)
{
  //Check if valid, then:
  setPosition(position);
}
