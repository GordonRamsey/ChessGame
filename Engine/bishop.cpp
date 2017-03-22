#include "bishop.h"
using namespace std;

vectors<coords> Bishop::AllPos()
{
    coords temp; 
    vector<coords> set; 

    //Move Diagonal up, right(w) AND down, left(b)  
    for(int i = 0; i < 8; ++i){
        temp.y = m_position.y + 1; 
        temp.x = m_position.x + 1; 

        if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
            set.push_back(temp); 
        else 
            continue; 
    }
    //Move Diagonal down, right(w) AND up, left(b)
    for(int i = 0; i < 8; ++i){
        temp.y = m_position.y + 1; 
        temp.x = m_position.x - 1; 
        
        if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
            set.push_back(temp); 
        else 
            continue;
    }
    //Move Diagonal up, left(w) AND down, right(b)
    for(int i = 0; i < 8; ++i){
        temp.y = m_position.y + 1; 
        temp.x = m_position.x - 1; 
        
        if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
            set.push_back(temp); 
        else 
            continue;
    }
    //Move Diagonal down, left(w) AND up, right(b)
    for(int i = 0; i < 8; ++i){
        temp.y = m_position.y - 1; 
        temp.x = m_position.x - 1; 
        
        if((temp.y && temp.x) < 8 && (temp.y && temp.x) >= 0)
            set.push_back(temp); 
        else 
            continue;
    }
}

void Bishop::Move(const string posiiton)
{
  //Check if valid, then:
  setPosition(position);
}
