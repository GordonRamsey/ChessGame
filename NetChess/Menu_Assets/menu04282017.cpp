#include "menu.h"
#include "../bridge.h"

using namespace std;

Menu::Menu(SDL_Surface *passedScreen)
{
  menuScreen = passedScreen;
  set_button_clips();
}

class Button
{
  private:
    int faction = -1;
    SDL_Rect box;
    SDL_Rect* menuClip;
    int menuClipNum;

  public:
    SDL_Surface *screen;

    SDL_Surface *buttonMenu;
    SDL_Surface *buttonScreen;

    Button(int x, int y, int w, int h, int passedClip, vector<SDL_Rect> passed, SDL_Surface *passedMenu, SDL_Surface *passedScreen)
    vector<SDL_Rect> menuClips;
    void set_faction(int x);
    void set_button_clip(int x);
    void show_button();
    int get_button_clip();
    void handle_button_events();
};

const int MENU_CLIP_WIDTH = 350;
const int MENU_CLIP_HEIGHT = 150;

int STD_SUBMIT = 0;
int STD_NECRO = 1;
int STD_WURM = 2;
int STD_PORTAL = 3;
int STD_FIGHTER = 4;
int STD_GOLEM = 5;

int HL_SUBMIT = 6;
int HL_NECRO = 7;
int HL_WURM = 8;
int HL_PORTAL = 9;
int HL_FIGHTER = 10;
int HL_GOLEM = 11;

int LOCK_SUBMIT = 12;
int LOCK_NECRO = 13;
int LOCK_WURM = 14;
int LOCK_PORTAL = 15;
int LOCK_FIGHTER = 16;
int LOCK_GOLEM = 17;

SDL_Surface *menu = NULL;
SDL_Event menuEvent;


void Menu::set_button_clips()
{
  SDL_Rect STD_SUBMIT;
  STD_SUBMIT.x = 0;
  STD_SUBMIT.y = 0;
  STD_SUBMIT.w = MENU_CLIP_WIDTH;
  STD_SUBMIT.h = MENU_CLIP_HEIGHT;
  menuClips.push_back(STD_SUBMIT);

  SDL_Rect HL_SUBMIT;
  HL_SUBMIT.x = 0;
  HL_SUBMIT.y = MENU_CLIP_HEIGHT;
  HL_SUBMIT.w = MENU_CLIP_WIDTH;
  HL_SUBMIT.h = MENU_CLIP_HEIGHT;
  menuClips.push_back(HL_SUBMIT);

  SDL_Rect LOCK_SUBMIT;
  LOCK_SUBMIT.x = 0;
  LOCK_SUBMIT.y = MENU_CLIP_HEIGHT*2;
  LOCK_SUBMIT.w = MENU_CLIP_WIDTH;
  LOCK_SUBMIT.h = MENU_CLIP_HEIGHT;
  menuClips.push_back(LOCK_SUBMIT);

  SDL_Rect STD_NECRO; 
  STD_NECRO.x = MENU_CLIP_WIDTH;
  STD_NECRO.y = 0;
  STD_NECRO.w = MENU_CLIP_WIDTH;
  STD_NECRO.h = MENU_CLIP_HEIGHT;
  menuClips.push_back(STD_NECRO);

  SDL_Rect HL_NECRO;
  HL_NECRO.x = MENU_CLIP_WIDTH;
  HL_NECRO.y = MENU_CLIP_HEIGHT;
  HL_NECRO.w = MENU_CLIP_WIDTH;
  HL_NECRO.h = MENU_CLIP_HEIGHT;
  menuClips.push_back(HL_NECRO);

  SDL_Rect LOCK_NECRO;
  LOCK_NECRO.x = MENU_CLIP_WIDTH;
  LOCK_NECRO.y = MENU_CLIP_HEIGHT*2;
  LOCK_NECRO.w = MENU_CLIP_WIDTH;
  LOCK_NECRO.h = MENU_CLIP_HEIGHT;
  menuClips.push_back(LOCK_NECRO);

  SDL_Rect STD_WURM;
  STD_WURM.x = MENU_CLIP_WIDTH*2;
  STD_WURM.y = 0;
  STD_WURM.w = MENU_CLIP_WIDTH;
  STD_WURM.h = MENU_CLIP_HEIGHT;
  menuClips.push_back(STD_WURM);

  SDL_Rect HL_WURM;
  HL_WURM.x = MENU_CLIP_WIDTH*2;
  HL_WURM.y = MENU_CLIP_HEIGHT;
  HL_WURM.w = MENU_CLIP_WIDTH;
  HL_WURM.h = MENU_CLIP_HEIGHT;
  menuClips.push_back(HL_WURM);

  SDL_Rect LOCK_WURM;
  LOCK_WURM.x = MENU_CLIP_WIDTH*2;
  LOCK_WURM.y = MENU_CLIP_HEIGHT*2;
  LOCK_WURM.w = MENU_CLIP_WIDTH;
  LOCK_WURM.h = MENU_CLIP_HEIGHT;
  menuClips.push_back(LOCK_WURM);

  SDL_Rect STD_PORTAL;
  STD_PORTAL.x = MENU_CLIP_WIDTH*3;
  STD_PORTAL.y = 0;
  STD_PORTAL.w = MENU_CLIP_WIDTH;
  STD_PORTAL.h = MENU_CLIP_HEIGHT;
  menuClips.push_back(STD_PORTAL);

  SDL_Rect HL_PORTAL;
  HL_PORTAL.x = MENU_CLIP_WIDTH*3;
  HL_PORTAL.y = MENU_CLIP_HEIGHT;
  HL_PORTAL.w = MENU_CLIP_WIDTH;
  HL_PORTAL.h = MENU_CLIP_HEIGHT;
  menuClips.push_back(HL_PORTAL);

  SDL_Rect LOCK_PORTAL;
  LOCK_PORTAL.x = MENU_CLIP_WIDTH*3;
  LOCK_PORTAL.y = MENU_CLIP_HEIGHT*2;
  LOCK_PORTAL.w = MENU_CLIP_WIDTH;
  LOCK_PORTAL.h = MENU_CLIP_HEIGHT;
  menuClips.push_back(LOCK_PORTAL);

  SDL_Rect STD_FIGHTER;
  STD_FIGHTER.x = MENU_CLIP_WIDTH*4;
  STD_FIGHTER.y = 0;
  STD_FIGHTER.w = MENU_CLIP_WIDTH;
  STD_FIGHTER.h = MENU_CLIP_HEIGHT;
  menuClips.push_back(STD_FIGHTER);

  SDL_Rect HL_FIGHTER;
  HL_FIGHTER.x = MENU_CLIP_WIDTH*4;
  HL_FIGHTER.y = MENU_CLIP_HEIGHT;
  HL_FIGHTER.w = MENU_CLIP_WIDTH;
  HL_FIGHTER.h = MENU_CLIP_HEIGHT;
  menuClips.push_back(HL_FIGHTER);

  SDL_Rect LOCK_FIGHTER;
  LOCK_FIGHTER.x = MENU_CLIP_WIDTH*4;
  LOCK_FIGHTER.y = MENU_CLIP_HEIGHT*2;
  LOCK_FIGHTER.w = MENU_CLIP_WIDTH;
  LOCK_FIGHTER.h = MENU_CLIP_HEIGHT;
  menuClips.push_back(LOCK_FIGHTER);

  SDL_Rect STD_GOLEM;
  STD_GOLEM.x = MENU_CLIP_WIDTH*5;
  STD_GOLEM.y = 0;
  STD_GOLEM.w = MENU_CLIP_WIDTH;
  STD_GOLEM.h = MENU_CLIP_HEIGHT;
  menuClips.push_back(STD_GOLEM);

  SDL_Rect HL_GOLEM;
  HL_GOLEM.x = MENU_CLIP_WIDTH*5;
  HL_GOLEM.y = MENU_CLIP_HEIGHT;
  HL_GOLEM.w = MENU_CLIP_WIDTH;
  HL_GOLEM.h = MENU_CLIP_HEIGHT;
  menuClips.push_back(HL_GOLEM);

  SDL_Rect LOCK_GOLEM;
  LOCK_GOLEM.x = MENU_CLIP_WIDTH*5;
  LOCK_GOLEM.y = MENU_CLIP_HEIGHT*2;
  LOCK_GOLEM.w = MENU_CLIP_WIDTH;
  LOCK_GOLEM.h = MENU_CLIP_HEIGHT;
  menuClips.push_back(LOCK_GOLEM);
}

//SDL told me to do this...
void apply_menu_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL)
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(source, clip, destination, &offset);
}

//Fancy SDL optimization they told me to do :P
SDL_Surface *load_menu_image(std::string filename)
{
  SDL_Surface* loadedImage = NULL;
  SDL_Surface* optimizedImage = NULL;
  loadedImage = IMG_Load(filename.c_str());
  cerr << filename.c_str() <<endl;
  cerr << loadedImage <<endl;
  if(loadedImage != NULL){
    cerr << "Loaded Image is not NULL" <<endl;
    optimizedImage = SDL_DisplayFormat(loadedImage);
    if(optimizedImage != NULL){
      cerr << "Opt Image is not NULL" <<endl;
      Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0xFF, 0xFF, 0xFF);
      SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
    }
    SDL_FreeSurface(loadedImage);
  }
  if(optimizedImage == NULL)
    cerr << "Returning NULL Image" << endl;
  return optimizedImage;
}

//Load files for menu check if it is there.
bool load_menu_files()
{
  menu = load_menu_image("Graphic_Assets/Menu.png");
  if(menu == NULL){
    cerr << "No Menu Loaded" <<endl;
    return false;
  }
  cerr << "Menu Loaded" <<endl;
  return true;
}

//Free up memory once we dont need it anymore.
void clean_up_menu()
{
  SDL_FreeSurface(menu);
}
/**** Start of Button class functions  *****/

Button::Button(int x, int y, int w, int h, int passedClip, vector<SDL_Rect> passed, SDL_Surface *passedMenu, SDL_Surface *passedScreen)
{
  box.x = x;
  box.y = y;
  box.w = w;
  box.h = h;

  menuClips = passed;
  set_button_clip(passedClip);

  buttonMenu = passedMenu; 
  buttonScreen = passedScreen;
}

void Button::set_faction(int x)
{
  faction = x;
}

void Button::set_button_clip(int x)
{
  menuClip = &menuClips[x];
  menuClipNum = x;
}

void Button::show_button()
{
  apply_menu_surface(box.x, box.y, buttonMenu, buttonScreen, menuClip);
}

int Button::get_button_clip()
{
  return menuClipNum;
}

void Button::handle_button_events()
{
  int x = 0, y = 0;
  if(menuEvent.type == SDL_MOUSEMOTION){
    x = menuEvent.motion.x;
    y = menuEvent.motion.y;

    if((x > box.x) and (x < box.x + box.w) and (y > box.y) and (y < box.y +box.h)){
      this->set_button_clip(this->get_button_clip()+6);
    }
  }
  if(menuEvent.type == SDL_MOUSEBUTTONDOWN){
    if(menuEvent.button.button == SDL_BUTTON_LEFT){
      x = menuEvent.button.x;
      y = menuEvent.button.y;

      if((x > box.x) and (x < box.x + box.w) and (y > box.y) and (y < box.y +box.h)){
	this->set_button_clip(this->get_button_clip()+12);
      }
    }
  }
}

//Make the magic happen
void Menu::run_menu(SDL_Surface *screen)
{
  menuScreen = screen;

  load_menu_files();

  Button submitButton(MENU_CLIP_WIDTH, MENU_CLIP_HEIGHT*2, MENU_CLIP_WIDTH, MENU_CLIP_HEIGHT, STD_SUBMIT, menuClips, menu,);
  Button necroButton(0, 0, MENU_CLIP_WIDTH, MENU_CLIP_HEIGHT, STD_NECRO, menuClips, menu,);
  Button wurmButton(MENU_CLIP_WIDTH, 0, MENU_CLIP_WIDTH, MENU_CLIP_HEIGHT, STD_WURM, menuClips, menu,);
  Button portalButton(0, MENU_CLIP_HEIGHT, MENU_CLIP_WIDTH, MENU_CLIP_HEIGHT, STD_PORTAL, menuClips, menu,);
  Button fighterButton(MENU_CLIP_WIDTH, MENU_CLIP_HEIGHT, MENU_CLIP_WIDTH, MENU_CLIP_HEIGHT, STD_FIGHTER, menuClips, menu,);
  Button golemButton(0, MENU_CLIP_HEIGHT*2, MENU_CLIP_WIDTH, MENU_CLIP_HEIGHT, STD_GOLEM, menuClips, menu,);

  bool runMenu = true;
  SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00));
  while(runMenu == true){

    //submitButton.show_button();
    necroButton.show_button();
    //wurmButton.show_button();
    //portalButton.show_button();
    //fighterButton.show_button();
    //golemButton.show_button();

    //apply_menu_surface(0,0, menu, screen);
    
    if(SDL_PollEvent(&menuEvent)){

      if(menuEvent.type == SDL_QUIT){
	runMenu = false;
      }
    }
    SDL_Flip(screen);
  }
  clean_up_menu();
}
/***************************************************
  void Menu::set_button_clips()
  {
  menuClips[STD_SUBMIT].x = 0;
  menuClips[STD_SUBMIT].y = 0;
  menuClips[STD_SUBMIT].w = MENU_CLIP_WIDTH;
  menuClips[STD_SUBMIT].h = MENU_CLIP_HEIGHT;

  menuClips[HL_SUBMIT].x = 0;
  menuClips[HL_SUBMIT].y = MENU_CLIP_HEIGHT;
  menuClips[HL_SUBMIT].w = MENU_CLIP_WIDTH;
  menuClips[HL_SUBMIT].h = MENU_CLIP_HEIGHT;

  menuClips[LOCK_SUBMIT].x = 0;
  menuClips[LOCK_SUBMIT].y = MENU_CLIP_HEIGHT*2;
  menuClips[LOCK_SUBMIT].w = MENU_CLIP_WIDTH;
  menuClips[LOCK_SUBMIT].h = MENU_CLIP_HEIGHT;

  menuClips[STD_NECRO].x = MENU_CLIP_WIDTH;
  menuClips[STD_NECRO].y = 0;
  menuClips[STD_NECRO].w = MENU_CLIP_WIDTH;
  menuClips[STD_NECRO].h = MENU_CLIP_HEIGHT;

  menuClips[HL_NECRO].x = MENU_CLIP_WIDTH;
  menuClips[HL_NECRO].y = MENU_CLIP_HEIGHT;
  menuClips[HL_NECRO].w = MENU_CLIP_WIDTH;
  menuClips[HL_NECRO].h = MENU_CLIP_HEIGHT;

  menuClips[LOCK_NECRO].x = MENU_CLIP_WIDTH;
  menuClips[LOCK_NECRO].y = MENU_CLIP_HEIGHT*2;
  menuClips[LOCK_NECRO].w = MENU_CLIP_WIDTH;
  menuClips[LOCK_NECRO].h = MENU_CLIP_HEIGHT;

  menuClips[STD_WURM].x = MENU_CLIP_WIDTH*2;
  menuClips[STD_WURM].y = 0;
  menuClips[STD_WURM].w = MENU_CLIP_WIDTH;
  menuClips[STD_WURM].h = MENU_CLIP_HEIGHT;

  menuClips[HL_WURM].x = MENU_CLIP_WIDTH*2;
  menuClips[HL_WURM].y = MENU_CLIP_HEIGHT;
  menuClips[HL_WURM].w = MENU_CLIP_WIDTH;
  menuClips[HL_WURM].h = MENU_CLIP_HEIGHT;

  menuClips[LOCK_WURM].x = MENU_CLIP_WIDTH*2;
  menuClips[LOCK_WURM].y = MENU_CLIP_HEIGHT*2;
  menuClips[LOCK_WURM].w = MENU_CLIP_WIDTH;
  menuClips[LOCK_WURM].h = MENU_CLIP_HEIGHT;

  menuClips[STD_PORTAL].x = MENU_CLIP_WIDTH*3;
  menuClips[STD_PORTAL].y = 0;
  menuClips[STD_PORTAL].w = MENU_CLIP_WIDTH;
  menuClips[STD_PORTAL].h = MENU_CLIP_HEIGHT;

  menuClips[HL_PORTAL].x = MENU_CLIP_WIDTH*3;
  menuClips[HL_PORTAL].y = MENU_CLIP_HEIGHT;
  menuClips[HL_PORTAL].w = MENU_CLIP_WIDTH;
  menuClips[HL_PORTAL].h = MENU_CLIP_HEIGHT;

  menuClips[LOCK_PORTAL].x = MENU_CLIP_WIDTH*3;
  menuClips[LOCK_PORTAL].y = MENU_CLIP_HEIGHT*2;
  menuClips[LOCK_PORTAL].w = MENU_CLIP_WIDTH;
  menuClips[LOCK_PORTAL].h = MENU_CLIP_HEIGHT;

  menuClips[STD_FIGHTER].x = MENU_CLIP_WIDTH*4;
  menuClips[STD_FIGHTER].y = 0;
  menuClips[STD_FIGHTER].w = MENU_CLIP_WIDTH;
  menuClips[STD_FIGHTER].h = MENU_CLIP_HEIGHT;

  menuClips[HL_FIGHTER].x = MENU_CLIP_WIDTH*4;
  menuClips[HL_FIGHTER].y = MENU_CLIP_HEIGHT;
  menuClips[HL_FIGHTER].w = MENU_CLIP_WIDTH;
  menuClips[HL_FIGHTER].h = MENU_CLIP_HEIGHT;

  menuClips[LOCK_FIGHTER].x = MENU_CLIP_WIDTH*4;
  menuClips[LOCK_FIGHTER].y = MENU_CLIP_HEIGHT*2;
  menuClips[LOCK_FIGHTER].w = MENU_CLIP_WIDTH;
  menuClips[LOCK_FIGHTER].h = MENU_CLIP_HEIGHT;

  menuClips[STD_GOLEM].x = MENU_CLIP_WIDTH*5;
  menuClips[STD_GOLEM].y = 0;
  menuClips[STD_GOLEM].w = MENU_CLIP_WIDTH;
  menuClips[STD_GOLEM].h = MENU_CLIP_HEIGHT;

  menuClips[HL_GOLEM].x = MENU_CLIP_WIDTH*5;
  menuClips[HL_GOLEM].y = MENU_CLIP_HEIGHT;
  menuClips[HL_GOLEM].w = MENU_CLIP_WIDTH;
  menuClips[HL_GOLEM].h = MENU_CLIP_HEIGHT;

  menuClips[LOCK_GOLEM].x = MENU_CLIP_WIDTH*5;
  menuClips[LOCK_GOLEM].y = MENU_CLIP_HEIGHT*2;
  menuClips[LOCK_GOLEM].w = MENU_CLIP_WIDTH;
  menuClips[LOCK_GOLEM].h = MENU_CLIP_HEIGHT;
}
****************************************************/
