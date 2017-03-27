#include "StringInput.h"
#include <iostream>

using namespace std;

StringInput::StringInput()
{
  str = "";

  text = NULL;

  SDL_EnableUNICODE(SDL_ENABLE);
}

StringInput::~StringInput()
{
  SDL_FreeSurface(text);

  SDL_EnableUNICODE(SDL_DISABLE);
}

void StringInput::setSurface(SDL_Surface* surf)
{
  text = surf;
}

string StringInput::getText()
{
  return str;
}

void StringInput::addChar(char c)
{
  str += c;
}

void StringInput::reset()
{
  str = "";
}

void StringInput::handle_input(SDL_Event event, TTF_Font* font, SDL_Color textColor)
{
  if(event.type == SDL_KEYDOWN)
  {
    string temp = str;
    string key = SDL_GetKeyName(event.key.keysym.sym);

    if(str.length() <= 16)
    { 
      //Uint16 key = event.key.keysym.unicode;
      cerr << (char)event.key.keysym.unicode << endl;
      cerr << SDL_GetKeyName(event.key.keysym.sym) << endl;
      if(key == "return")
      {
	//Do nothing with it
      }
      else if(key == "space")
      {
	if(str == "_")
	  str = "";
	str += ' ';
      }
      else if((key >= "a" and key <= "z") && key.length() == 1)
      {
	if(str == "_")
	  str = "";
	str += key;
      }
    }
    if((key == "backspace") && (str.length() != 0))
    {
      str.erase(str.length()-1);
    }
    if(str != temp)
    {
      SDL_FreeSurface(text);

      text = TTF_RenderText_Solid(font, str.c_str(), textColor);
    }
  }
}
