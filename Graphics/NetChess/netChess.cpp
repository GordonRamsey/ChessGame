#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include "Net_Assets/Socket.h"
#include "Net_Assets/SocketSet.h"

using namespace std;


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;

int CLIP_DEFAULT = 0;
int CLIP_SELECTED = 1;

class Piece
{
  private:
    SDL_Rect box;
    SDL_Rect* clip;
    int num;

  public:
    Piece(int x, int y, int num);
    void setPos(int x, int y);
    void setClip(int x);
    int  getNum();
    void handle_events();
    void show();
};

//Our connection to the server
Socket s_socket;
SocketSet socketSet;

//The surfaces
SDL_Surface *board = NULL;
SDL_Surface *pieceSheet = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

SDL_Rect clips[2];

//Our "held" piece
Piece* selected = NULL;
std::vector<Piece> pieces;


void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL)
{
  //Temp rectangle to hold the offset
  SDL_Rect offset;

  //Get the offset
  offset.x = x;
  offset.y = y;

  //blit the surface
  SDL_BlitSurface( source, clip, destination, &offset );
}

void set_clips()
{
  clips[CLIP_DEFAULT].x = 0;
  clips[CLIP_DEFAULT].y = 0;
  clips[CLIP_DEFAULT].w = 80;
  clips[CLIP_DEFAULT].h = 80;

  clips[CLIP_SELECTED].x = 80;
  clips[CLIP_SELECTED].y = 0;
  clips[CLIP_SELECTED].w = 80;
  clips[CLIP_SELECTED].h = 80;
}

Piece::Piece(int x, int y, int it)
{
  box.x = x;
  box.y = y;
  box.w = 80;
  box.h = 80;

  num = it;

  clip = &clips[CLIP_DEFAULT];
}

void Piece::handle_events()
{
  int x = 0, y = 0;

  if(event.type == SDL_MOUSEBUTTONDOWN)
  {
    //If we click on a piece
    if(event.button.button == SDL_BUTTON_LEFT)
    {
      x = event.button.x;
      y = event.button.y;

      if ((x > box.x) && (x < box.x + box.w) && (y > box.y) && (y < box.y + box.h))
      {
	if(selected == NULL){
	  clip = &clips[CLIP_SELECTED];
	  selected = this;
	}
      }
    }
  }
}

void Piece::show()
{
  apply_surface(box.x, box.y, pieceSheet, screen, clip);
}

void Piece::setPos(int x, int y)
{
  box.x = x;
  box.y = y;
}

void Piece::setClip(int x)
{
  clip = &clips[x];
}

int Piece::getNum()
{
  return num;
}

SDL_Surface *load_image( std::string filename )
{
  SDL_Surface* loadedImage = NULL;
  SDL_Surface* optimizedImage = NULL;

  //Load image
  loadedImage = IMG_Load( filename.c_str() );
  if( loadedImage != NULL )
  {
    //Optimize image
    optimizedImage = SDL_DisplayFormat( loadedImage );
    if(optimizedImage != NULL){
      Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0xFF, 0xFF, 0xFF);
      SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
    }

    //Free old image
    SDL_FreeSurface( loadedImage );
  }
  return optimizedImage;
}

bool init()
{
  //Initialize all SDL subsystems
  if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
  {
    return false;
  }

  //Set up the screen
  screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
  if(screen == NULL)
  {
    return false;
  }

  SDL_WM_SetCaption("Game Test", NULL);

  return true;
}

bool load_files()
{
  //Load the image
  board = load_image("chessboard.png");
  pieceSheet = load_image("piece.png");

  if(board == NULL)
  {
    return false;
  }
  else if (pieceSheet == NULL)
  {
    return false;
  }

  return true;
}

void clean_up()
{
  SDL_FreeSurface(board);
  SDL_FreeSurface(pieceSheet);

  SDL_Quit();
}

void generatePieces()
{
  int it = 0;
  for(int i=0;i<8;i++){
    for(int j=0;j<2;j++){
      Piece newPiece = Piece(i*80, j*80, it);
      it++;
      pieces.push_back(newPiece);
    }
  }
  
  for(int i=0;i<8;i++){
    for(int j=0;j<2;j++){
      Piece newPiece = Piece(i*80, j*80+480, it);
      it++;
      pieces.push_back(newPiece);
    }
  }
}

int connectServer(int argc, char* argv[])
{
  s_socket.open(argv[1], argv[2]);
  s_socket.joinGroup(&socketSet);
  
  if(!s_socket.isClosed())
    return 0;
  printf("Cannot establish connection to server\n");
  return -1;
}

int main ( int argc, char* argv[] )
{
  if(connectServer(argc, argv) == -1)
    return 1;
  //We should have "socket" as our connection now

  bool quit = false;
  int x,y;

  //run initialiation and asset loading
  if(init() == false){
    return 1;
  }
  if(load_files() == false){
    return 1;
  }
  set_clips();
  generatePieces();

  //While the user hasn't quit
  while(quit == false)
  {
    //While theres an event to handle
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_MOUSEBUTTONDOWN)
      {
	if(selected != NULL){
	  x = event.button.x;
	  y = event.button.y;

	  selected->setPos(x-40,y-40);
	  selected->setClip(CLIP_DEFAULT);

	  stringstream ss;
	  ss.str("");
	  ss << selected->getNum() << " " << x-40 << " " << y-40;
	  s_socket.writeString(ss.str());
	  
	  selected = NULL;
	  continue;
	}
      }

      for(unsigned int i=0;i<pieces.size();i++)
	pieces[i].handle_events();

      if(event.type == SDL_QUIT)
      {
	quit = true;
      }

    }//While- SDL_PollEvent
    
    //Connection
    if(s_socket.isClosed()){
      printf("Lost connection with server\n");
      return 1;
    }
    socketSet.wait(0);
    if(s_socket.hasEvent())
    {
      //Do appropriate things with server message
      //Message: <num> <x> <y>
      string msg = "DEFAULT";
      int bytes = s_socket.readString(msg,24);
      cerr << "Message Received:" << msg << endl;

      int index, last;
      index = msg.find(" ");
      string num = msg.substr(0,index);
      index++;
      last = index;
      index = msg.find(" ",index);
      string s_x = msg.substr(last,index-last);
      index++;
      string s_y = msg.substr(index,msg.length()-index);
      int i_num = atoi(num.c_str());


      for(unsigned int i=0;i<pieces.size();i++){
	if(pieces[i].getNum() == i_num){
	  pieces[i].setPos(atoi(s_x.c_str()), atoi(s_y.c_str()));
	  break;
	}
      }
    }//if- socket has event

    //Drawing
    //Make window white instead of black
    SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

    //Apply te surface to the screen
    apply_surface(0, 0, board, screen, NULL);

    //Show() pieces
    for(int i=0;i<pieces.size();i++)
      pieces[i].show();

    //Update screen
    if(SDL_Flip( screen ) == -1){
      return 1;
    }

  }//While- Quit == false
  //Free space and quit SDL
  clean_up();

  return 0;
}
