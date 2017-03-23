#include "king.h"
using namespace std;

King::King()
{
    m_name = name;
}

King::~King()
{}

vector<coords> King::AllPos()
{
    coord temp; 
    vector<coord> set; 
    //move forward (w) back (b)  
    temp.y = m_position.y - 1; 
    temp.x = m_position.x + 0; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
        set.push_back(temp);
    //move back(w) forward (b)
    temp.y = m_position.y + 1; 
    temp.x = m_position.x + 0; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
            set.push_back(temp);    
    //move right (w) left (b)
    temp.y = m_position.y + 0; 
    temp.x = m_position.x - 1; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
        set.push_back(temp);
    //move left (w) right(b) 
    temp.y = m_position.y + 0; 
    temp.x = m_position.x + 1; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
        set.push_back(temp);
    //D up, right
    temp.y = m_position.y - 1; 
    temp.x = m_position.x - 1; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
        set.push_back(temp);

    //D up, left
    temp.y = m_position.y - 1; 
    temp.x = m_position.x + 1; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
        set.push_back(temp);
    //D down, right
    temp.y = m_position.y + 1; 
    temp.x = m_position.x - 1; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
        set.push_back(temp);
    //D down, left
    temp.y = m_position.y + 1; 
    temp.x = m_position.x + 1; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
        set.push_back(temp);

}

void King::Move(const string posiiton)
{
  //Check if valid, then:
  setPosition(position);
}
