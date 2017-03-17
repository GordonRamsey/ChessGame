#include "rook.h"
using namespace std;

vector<coords> Rook::isValid()
{
    coords temp; 
    vector<coords> set; 

    //move up(w) down(b)
    for(int i = 0; i < 8; ++i){
        temp.y = m_position.y + 1; 
        temp.x = m_position.x + 0; 
        set.push_back(temp); 
    }
    //move down(w) up(b)
    for(int i = 0; i < 8; ++i){
        temp.y = m_position.y - 1; 
        temp.x = m_position.x + 0; 
        set.push_back(temp); 
    }

    //move right(w) left(b)
    for(int i = 0; i < 8; ++i){
        temp.y = m_position.y + 0; 
        temp.x = m_position.x + 1; 
        set.push_back(temp); 
    }

    //move left(w) right(w)
    for(int i = 0; i < 8; ++i){
        temp.y = m_position.y + 0; 
        temp.x = m_position.x - 1; 
        set.push_back(temp); 
    }

}

void Rook::Move(const string posiiton)
{
  //Check if valid, then:  
  setPosition(position);
}
