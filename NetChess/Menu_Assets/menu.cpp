#include "menu.h"
#include "../bridge.h"

using namespace std;

const int MENU_CLIP_WIDTH = 350;
const int MENU_CLIP_HEIGHT = 150;

const int MB = 48; // Menu Boarder
const int BB = 50; // Button Boarder
const int BG = 175; // Button Gap

const int STD_SUBMIT = 0;
const int STD_NECRO = 3;
const int STD_WURM = 6;
const int STD_PORTAL = 9;
const int STD_FIGHTER = 12;
const int STD_GOLEM = 15;

const int HL_SUBMIT = 1;
const int HL_NECRO = 4;
const int HL_WURM = 7;
const int HL_PORTAL = 9;
const int HL_FIGHTER = 13;
const int HL_GOLEM = 16;

const int LOCK_SUBMIT = 2;
const int LOCK_NECRO = 5;
const int LOCK_WURM = 8;
const int LOCK_PORTAL = 11;
const int LOCK_FIGHTER = 14;
const int LOCK_GOLEM = 17;

SDL_Surface *menu = NULL;
SDL_Surface *menuBg = NULL;
SDL_Surface *menuText = NULL;
SDL_Event menuEvent;

vector<SDL_Rect> menuClips;

int clicked = -1;

class Button
{
  private:

    int faction = -1;
    SDL_Rect box;

  public:

    int dfclip =-1;
    Button(int x, int y, int w, int h, int passedClip);
    int menuClipNum;
    SDL_Rect* menuClip;
    void set_faction(int x);
    void set_button_clip(int x);
    void show_button();
    int get_button_clip();
    bool handle_button_events();
    bool active = false;
    void set_clicked(int &clicked, int click);
    void set_button_dfclip(int x);
};

void set_button_clips()
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
  if(loadedImage != NULL){
    optimizedImage = SDL_DisplayFormat(loadedImage);
    if(optimizedImage != NULL){
      Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0xFF, 0xFF, 0xFF);
      SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
    }
    SDL_FreeSurface(loadedImage);
  }
  return optimizedImage;
}

//Load files for menu check if it is there.
bool load_menu_files()
{
  menu = load_menu_image("Graphic_Assets/Menu.png");
  if(menu == NULL)
    return false;

  menuBg = load_menu_image("Graphic_Assets/fourPlayerBoard64.png");
  if(menuBg == NULL)
    return false;

  menuText = load_menu_image("Graphic_Assets/textBackground.png");
  if(menuText == NULL)
    return false;

  return true;
}

//Free up memory once we dont need it anymore.
void clean_up_menu()
{
  SDL_FreeSurface(menu);
  SDL_FreeSurface(menuBg);
  SDL_FreeSurface(menuText);
}

/**** Start of Button class functions  *****/

Button::Button(int x, int y, int w, int h, int passedClip)
{
  box.x = x;
  box.y = y;
  box.w = w;
  box.h = h;

  set_button_clip(passedClip);
  dfclip = get_button_clip();
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

void Button::set_button_dfclip(int x)
{
  dfclip = x;
}

void Button::set_clicked(int &clicked, int click)
{
  clicked = click;
}

void Button::show_button()
{
  //  apply_menu_surface(box.x, box.y, menu, screen, menuClip);
}

int Button::get_button_clip()
{
  return menuClipNum;
}

bool Button::handle_button_events()
{
  int x = 0, y = 0;
  if(menuEvent.type == SDL_MOUSEMOTION){
    x = menuEvent.motion.x;
    y = menuEvent.motion.y;


    if((x > box.x) and (x < box.x + box.w) and (y > box.y) and (y < box.y +box.h)){
      if(this->get_button_clip() %3 == 0){
	this->set_button_clip(this->get_button_clip()+1);
      }
    }
    else
      this->set_button_clip(dfclip);
  }
  if(menuEvent.type == SDL_MOUSEBUTTONDOWN){
    if(menuEvent.button.button == SDL_BUTTON_LEFT){
      x = menuEvent.button.x;
      y = menuEvent.button.y;

      if((x > box.x) and (x < box.x + box.w) and (y > box.y) and (y < box.y +box.h)){
	if((this->get_button_clip() -1) %3 == 0){
	  this->set_button_clip(this->get_button_clip()+1);
	  this-> dfclip  = this->get_button_clip();
	  set_clicked(clicked, get_button_clip());
	}
      }
    }
  }
  return false;
}

Menu::Menu(SDL_Surface *passedScreen)
{
  menuScreen = passedScreen;
}

//Make the magic happen
int Menu::run_menu(SDL_Surface *screen)
{
  SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

  menuScreen = screen;

  load_menu_files();
  set_button_clips();

  Button *wurmButton = new Button(MB+BB, MB+BB, MENU_CLIP_WIDTH, MENU_CLIP_HEIGHT, STD_WURM);
  Button *portalButton = new Button(MB+BB*2+MENU_CLIP_WIDTH,MB+BB, MENU_CLIP_WIDTH, MENU_CLIP_HEIGHT, STD_PORTAL);
  Button *fighterButton = new Button(MB+BB,MB+BB*2+MENU_CLIP_HEIGHT, MENU_CLIP_WIDTH, MENU_CLIP_HEIGHT, STD_FIGHTER);
  Button *golemButton = new Button(MB+BB*2+MENU_CLIP_WIDTH,MB+BB*2+MENU_CLIP_HEIGHT, MENU_CLIP_WIDTH, MENU_CLIP_HEIGHT, STD_GOLEM);
  Button *necroButton = new Button(MB+BB+BG+BB/2,MB+BB*3+MENU_CLIP_HEIGHT*2, MENU_CLIP_WIDTH, MENU_CLIP_HEIGHT, STD_NECRO);
  Button *submitButton = new  Button(MB+BB+BG+BB/2,MB+BB*4+MENU_CLIP_HEIGHT*3, MENU_CLIP_WIDTH, MENU_CLIP_HEIGHT, STD_SUBMIT);

  bool runMenu = true;
  int return_var = -1;
  int wc = -1, pc = -1, fc = -1, gc = -1, nc = -1;

  Button *buttons [] = { submitButton, necroButton, wurmButton, portalButton, fighterButton, golemButton };

  apply_menu_surface(0, 0, menuBg, screen);
  apply_menu_surface(896, 0, menuText, screen);

  while(runMenu == true){

    apply_menu_surface(MB+BB, MB+BB, menu, screen, wurmButton->menuClip);
    apply_menu_surface(MB+BB*2+MENU_CLIP_WIDTH,MB+BB, menu, screen, portalButton->menuClip);
    apply_menu_surface(MB+BB,MB+BB*2+MENU_CLIP_HEIGHT, menu, screen, fighterButton->menuClip);
    apply_menu_surface(MB+BB*2+MENU_CLIP_WIDTH,MB+BB*2+MENU_CLIP_HEIGHT, menu, screen, golemButton->menuClip);
    apply_menu_surface(MB+BB+BG+BB/2,MB+BB*3+MENU_CLIP_HEIGHT*2, menu, screen, necroButton->menuClip);
    apply_menu_surface(MB+BB+BG+BB/2,MB+BB*4+MENU_CLIP_HEIGHT*3, menu, screen, submitButton->menuClip);

    if(SDL_PollEvent(&menuEvent)){
      for(int i=0;i<6;i++){
	if(buttons[i]->handle_button_events()){
	  break;
	}

	for(int j=0;j<6;j++){
	  if(buttons[j]->get_button_clip() == 2)
	    break;
	  if((buttons[j]->get_button_clip() != clicked) and ((buttons[j]->get_button_clip()-2)%3 == 0))
	    buttons[j]->set_button_clip(j*3);
	}
      }

      if(menuEvent.type == SDL_QUIT){
	runMenu = false;
      }

      if(submitButton->get_button_clip() == LOCK_SUBMIT){

	wc = wurmButton->get_button_clip();
	pc = portalButton->get_button_clip();
	fc = fighterButton->get_button_clip();
	gc = golemButton->get_button_clip();
	nc = necroButton->get_button_clip();

	if(wc == LOCK_WURM or pc == LOCK_PORTAL or fc == LOCK_FIGHTER or gc == LOCK_GOLEM or nc == LOCK_NECRO){
	  if(wc == LOCK_WURM)
	    return_var =  1;
	  else if(pc == LOCK_PORTAL)
	    return_var = 2;
	  else if(fc == LOCK_FIGHTER)
	    return_var = 3;
	  else if(gc == LOCK_GOLEM)
	    return_var = 4;
	  else if(nc == LOCK_NECRO)
	    return_var = 5;
	  else
	    return_var = -1;
	  runMenu = false;
	}
	else{
	  submitButton->set_button_clip(STD_SUBMIT);
	  submitButton->set_button_dfclip(STD_SUBMIT);
	}

      }
    }
    SDL_Flip(screen);
  }
  delete wurmButton;
  delete portalButton;
  delete fighterButton;
  delete golemButton;
  delete necroButton;
  delete submitButton;
  clean_up_menu();
  return return_var;
}
