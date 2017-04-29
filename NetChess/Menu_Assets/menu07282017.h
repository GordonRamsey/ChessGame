#ifndef MENU_H
#define MENU_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Menu {
  private:

  public:
    SDL_Surface *menuScreen;
    Menu(SDL_Surface *passedScreen);
    void run_menu(SDL_Surface *screen);
    void set_button_clips();
    vector<SDL_Rect> menuClips;
};

#endif
