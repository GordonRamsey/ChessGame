#include "knight.h"
using namespace std;

vector<coords> Knight::isValid()
{
    coords temp; 
    vector<coords> set; 

    //up 2, right 1(w) AND  down 2, left 1(b)
    temp.y = m_position.y + 2; 
    temp.x = m_position.x + 1; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)    
        set.push_back(temp); 

    //up 1, right 2 AND down 1, left 2(b)
    temp.y = m_position.y + 1; 
    temp.x = m_position.x + 2; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)    
        set.push_back(temp); 

    //down 2, right 1 AND up 2, left 1(b)
    temp.y = m_position.y - 2; 
    temp.x = m_position.x + 1; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)    
        set.push_back(temp); 
    //down 1, right 2 AND up 1, left 2(b)
    temp.y = m_position.y - 1; 
    temp.x = m_position.x + 2; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)    
        set.push_back(temp); 
    //up 2, left 1 AND down 1, right 2(b)
    temp.y = m_position.y + 2; 
    temp.x = m_position.x - 1; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)    
        set.push_back(temp); 
    //up 1, left 2 AND down 1, right 2(b)
    temp.y = m_position.y + 1; 
    temp.x = m_position.x - 2; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)    
        set.push_back(temp); 
    //down 2, left 1 AND up 2, right 1(b)
    temp.y = m_position.y - 2; 
    temp.x = m_position.x - 1; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)    
        set.push_back(temp); 

    //down 1, left 2 AND up 1, right 2(b)
    temp.y = m_position.y - 1; 
    temp.x = m_position.x - 2; ; 
    if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)    
        set.push_back(temp); 
}

void Knight::Move(const string posiiton)
{
	//Check isValid first, then:
  	setPosition(position);
}

