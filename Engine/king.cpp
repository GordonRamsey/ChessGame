#include "king.h"
using namespace std;

vector<coords> King::isValid()
{
    coords temp; 
    vector<coords> set; 
    //move forward (w) back (b)  
    temp.y = m_position.y + 1; 
    temp.x = m_position.x + 0; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
        set.push_back(temp);
    //move back(w) forward (b)
    temp.y = m_position.y - 1; 
    temp.x = m_position.x + 0; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
            set.push_back(temp);    
    //move right (w) left (b)
    temp.y = m_position.y + 0; 
    temp.x = m_position.x + 1; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
        set.push_back(temp);
    //move left (w) right(b) 
    temp.y = m_position.y + 0; 
    temp.x = m_position.x - 1; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
        set.push_back(temp);
}

void King::Move(const string posiiton)
{
  //Check if valid, then:
  setPosition(position);
}
