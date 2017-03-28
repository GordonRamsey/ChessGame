#include "king.h"
using namespace std;

King::King()
{
    m_name = "King";
    m_castle = false;
}

King::~King()
{}

void King::Move(const string posiiton)
{
  //Check if valid, then:
  setPosition(position);
}

string King::getName() const
{
    return m_name; 
}

void King::setName(const string name)
{
    m_name = name; 
}

char King::getTmpColor(int y, int x, vector<coord> WLocs, vector<coord> BLocs)
{
    char b, w, e; 
    int temp_y = y;
    int temp_x = x; 
    for(int b = 0, b < BLocs.size(); ++b)
    {
        if((temp.y == BLocs[b].y) && (temp.x == BLocs[b].x))
            return 'b';
        else
            continue; 
    }
    for(int w = 0; WLocs.size(); ++w)
    {
        if((temp.y == WLocs[b].y) && (temp.x == WLocs[b].x))
            return 'w'; 
        else
            continue; 
    }
    return 'e'; 
}

char King::isAlly(int y, int x, char myColor, vector<coord> WLocs, vector<coord> BLocs)

{
    char TmpColor = getTmpColor(y,x, WLocs, BLocs); 
    if(myColor == TmpColor)
        return true;
    else
        return false; 
}

bool King::isEnemy(int y, int x, char myColor, vector<coord> WLocs, vector<coord> BLocs)
{
    char TmpColor = getTmpColor(y,x, WLocs, BLocs); 
    if(TmpColor != myColor) 
        return true; 
    else 
        return false; 
}

    coord cap, valid; 
    int temp.y = cp_y; 
    int temp.x = cp_x; 
    //move forward (w) back (b)  
    
    temp.y = cp_y-1; 
    if(temp.y >= 0 && temp.y < 8 && temp.x >= 0 && temp.y < 8)
    {
        if(isAlly(temp.y, temp.x))
        if(isEmpty(temp.y, temp.x))
=======
bool King::isEmpty(int y, int x, vector<coord> WLocs, vector<coord> BLocs)
{
    char TmpColor = getTmpColor(y, x, WLocs, BLocs); 
    if(TmpColor == 'e')
        return true; 
    else 
        return false; 
}

void King::ValidMoves(cp.y, cp.x, char myColor, vector<coord> captureable, vector<coord> validPos, vector<coord> WLocs, vector<coord> BLocs)
{
    coord cap, valid; 
    int temp.y = cp_y; 
    int temp.x = cp_x; 
    //move forward (w) back (b)  
    
    temp.y = cp_y-1; 
    if(temp.y >= 0 && temp.y < 8 && temp.x >= 0 && temp.y < 8)
    {
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs)) //Remove this???
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
        }
    }
    
    //move back(w) forward (b)
    temp.y = cp_y+1; 
    if(temp.y >= 0 && temp.y < 8 && temp.x >= 0 && temp.y < 8)
    {
<<<<<<< HEAD
        if(isAlly(temp.y, temp.x))
        if(isEmpty(temp.y, temp.x)) 
=======
        temp.y += 1; 
        temp.x = cp.x; 
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
            break; 
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
>>>>>>> 6f9292968d28b35d4d1019d0adc1f323919505fa
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
        }
    }
    //move right (w) left (b)

    temp.y = cp_y; 
    temp.x = cp_x-1; 

    if(temp.y >= 0 && temp.y < 8 && temp.x >= 0 && temp.y < 8)
    {
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
        }
    }
    
    //move left (w) right(b) 
    temp.x = cp_x+1; 

    if(temp.y >= 0 && temp.y < 8 && temp.x >= 0 && temp.y < 8)
    {
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
        }
    }
    //D up, left 
    temp.y = cp_y-1; 
    temp.x = cp_x-1; 

    if(temp.y >= 0 && temp.y < 8 && temp.x >= 0 && temp.y < 8)
    {
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
        }

    }
    //D up, right 
    temp.y = cp_y-1; 
    temp.x = cp_x+1; 
    if(temp.y >= 0 && temp.y < 8 && temp.x >= 0 && temp.y < 8)
    {
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
        }
    }
    //D down, left
    temp.y = cp_y+1; 
    temp.x = cp_x-1; 
    if(temp.y >= 0 && temp.y < 8 && temp.x >= 0 && temp.y < 8)
    {
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
        }
        if(isEnemy(temp.y, temp.x, myColor, WLocs, BLocs))
        {
            cap.y = temp.y; 
            cap.x = temp.x; 
            captureable.push_back(cap); 
            validPos.push_back(cap); 
        }
    }
    //D down, right
    temp.y = cp_y+1; 
    temp.x = cp_x+1; 
    if(temp.y >= 0 && temp.y < 8 && temp.x >= 0 && temp.y < 8)
    {
        if(isAlly(temp.y, temp.x, myColor, WLocs, BLocs))
        if(isEmpty(temp.y, temp.x, WLocs, BLocs)) 
        {
            valid.y = temp.y; 
            valid.x = temp.x; 
            valid.push_back(valid); 
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
void King::ValidMoves(Piece* board[8][8]) //Checks all 8 positions, and checks for castling
{
    coord cur, temp;
    vector<coord> positions;
    cur = this->getPos();
    temp = cur;
    
    //move up
    temp.y -=1;
    if(temp.y >= 0)
    {
        Piece* piece = board[temp.y][temp.x];
        if(piece == NULL)
            positions.push_back(temp);
        else
        {
            if(piece->getColor() != m_color)
                positions.push_back(temp);
        }
    }

    //move down 
    temp.y = cur.y+1; 
    if(temp.y < 8)
    {
        Piece* piece = board[temp.y][temp.x];
        if(piece == NULL)
            positions.push_back(temp);
        else
        {
            if(piece->getColor() != m_color)
                positions.push_back(temp);
        }
    }
    
    //move right
    temp.y = cur.y; 
    temp.x = cur.x+1; 

    if(temp.y < 8)
    {
        Piece* piece = board[temp.y][temp.x];
        if(piece == NULL)
            positions.push_back(temp);
        else
        {
            if(piece->getColor() != m_color)
                positions.push_back(temp);
        }
    }
    
    //move left
    temp.x = cur.x-1; 
    if(temp.x >= 0)
    {
        Piece* piece = board[temp.y][temp.x];
        if(piece == NULL)
            positions.push_back(temp);
        else
        {
            if(piece->getColor() != m_color)
                positions.push_back(temp);
        }
    }
    
    //D up, left 
    temp.y = cur.y-1; 
    temp.x = cur.x-1; 
    if(temp.y >= 0 && temp.x >= 0)
    {
        Piece* piece = board[temp.y][temp.x];
        if(piece == NULL)
            positions.push_back(temp);
        else
        {
            if(piece->getColor() != m_color)
                positions.push_back(temp);
        }
    }
    
    //D up, right 
    temp.y = cur.y-1; 
    temp.x = cur.x+1; 
    if(temp.y >= 0 && temp.x < 8)
    {
        Piece* piece = board[temp.y][temp.x];
        if(piece == NULL)
            positions.push_back(temp);
        else
        {
            if(piece->getColor() != m_color)
                positions.push_back(temp);
        }
    }
    
    //D down, left
    temp.y = cur.y+1; 
    temp.x = cur.x-1; 
    if(temp.y < 8 && temp.x >= 0)
    {
        Piece* piece = board[temp.y][temp.x];
        if(piece == NULL)
            positions.push_back(temp);
        else
        {
            if(piece->getColor() != m_color)
                positions.push_back(temp);
        }
    }
    
    //D down, right
    temp.y = cur.y+1; 
    temp.x = cur.x+1; 
    if(temp.y < 8 && temp.x < 8)
    {
        Piece* piece = board[temp.y][temp.x];
        if(piece == NULL)
            positions.push_back(temp);
        else
        {
            if(piece->getColor() != m_color)
                positions.push_back(temp);
        }
    }

    //CHECK FOR CASTLING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

}

