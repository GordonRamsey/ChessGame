#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include "bridge.h"
#include "../../Engine/piece.h"

using namespace std;


const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 512;
const int SCREEN_BPP = 32;

int SPRITE_SIZE = 32;
int BORDER_SIZE = 128;

//Slices for our sprite sheet
int CLIP_PAWN = 0;
int CLIP_ROOK = 1;
int CLIP_BISHOP = 2;
int CLIP_KNIGHT = 3;
int CLIP_QUEEN = 4;
int CLIP_KING = 5;

//Our connection to the server
Socket s_socket;
SocketSet socketSet;

//The surfaces
SDL_Surface *board = NULL;
SDL_Surface *pieceSheet1 = NULL; //Player1s sprite sheet
SDL_Surface *pieceSheet2 = NULL; //Player 2
//SDL_Surface *pieceSheet3 = NULL; //Player 3
//SDL_Surface *pieceSheet4 = NULL; //Player 4
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

SDL_Rect clips[6];

//Our "held" piece
Piece* selected = NULL;
vector<Piece> pieces;
int player_num; //Our player num relevent to the current game


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

void Piece::handle_events()
{
  int x = 0, y = 0;

  if(event.type == SDL_MOUSEBUTTONDOWN)
  {
    if(event.button.button == SDL_BUTTON_LEFT)
    {
      x = event.button.x;
      y = event.button.y;

      if ((x > box.x) && (x < box.x + box.w) && (y > box.y) && (y < box.y + box.h))
      {
	if(selected == NULL){
	  //clip = &clips[CLIP_SELECTED];
	  selected = this;
	}
      }
    }
  }
}

void Piece::show()
{
  apply_surface(box.x, box.y, sheet, screen, clip);
}

void Piece::setClip(int x)
{
  clip = &clips[x];
}

void Piece::setTeam(int x)
{
  if(x == 0)
    sheet = pieceSheet1;
  else
    sheet = pieceSheet2;
}

void set_clips()
{
  clips[CLIP_PAWN].x = 0;
  clips[CLIP_PAWN].y = 0;
  clips[CLIP_PAWN].w = SPRITE_SIZE;
  clips[CLIP_PAWN].h = SPRITE_SIZE;

  //clip range for the rook
  clips[CLIP_ROOK].x = SPRITE_SIZE;
  clips[CLIP_ROOK].y = 0;
  clips[CLIP_ROOK].w = SPRITE_SIZE;
  clips[CLIP_ROOK].h = SPRITE_SIZE;

  //clip range for the bishop
  clips[CLIP_BISHOP].x = SPRITE_SIZE*2;
  clips[CLIP_BISHOP].y = 0;
  clips[CLIP_BISHOP].w = SPRITE_SIZE;
  clips[CLIP_BISHOP].h = SPRITE_SIZE;

  //clip range for the knight
  clips[CLIP_KNIGHT].x = SPRITE_SIZE*3;
  clips[CLIP_KNIGHT].y = 0;
  clips[CLIP_KNIGHT].w = SPRITE_SIZE;
  clips[CLIP_KNIGHT].h = SPRITE_SIZE;

  //clip range for the queen
  clips[CLIP_QUEEN].x = SPRITE_SIZE*4;
  clips[CLIP_QUEEN].y = 0;
  clips[CLIP_QUEEN].w = SPRITE_SIZE;
  clips[CLIP_QUEEN].h = SPRITE_SIZE;

  //clip range for the king
  clips[CLIP_KING].x = SPRITE_SIZE*5;
  clips[CLIP_KING].y = 0;
  clips[CLIP_KING].w = SPRITE_SIZE;
  clips[CLIP_KING].h = SPRITE_SIZE;

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

  SDL_WM_SetCaption("NetChess", NULL);

  return true;
}

bool load_files()
{
  //Load the image
  board = load_image("twoPlayerBoard.png");
  pieceSheet1 = load_image("basicPieces.png");
  pieceSheet2 = load_image("basicPieces2.png");

  if(board == NULL)
  {
    return false;
  }
  else if (pieceSheet1 == NULL || pieceSheet2 == NULL)
  {
    return false;
  }

  return true;
}

void clean_up()
{
  SDL_FreeSurface(board);
  SDL_FreeSurface(pieceSheet1);
  SDL_FreeSurface(pieceSheet2);

  SDL_Quit();
}

void generatePieces()
{
  int it = 0;
  for(int j=0;j<2;j++){
    for(int i=0;i<8;i++){
      Piece newPiece = Piece(i*SPRITE_SIZE+BORDER_SIZE, j*SPRITE_SIZE+BORDER_SIZE, it); 
      it++;
      newPiece.setTeam(0);
      if(j == 1)
	newPiece.setClip(CLIP_PAWN);
      else{
	if(i==0 || i ==7)
	  newPiece.setClip(CLIP_ROOK);
	if(i==1 || i ==6)
	  newPiece.setClip(CLIP_KNIGHT);
	if(i==2 || i ==5)
	  newPiece.setClip(CLIP_BISHOP);
	if(i==4)
	  newPiece.setClip(CLIP_KING);
	if(i==3)
	  newPiece.setClip(CLIP_QUEEN);
      }
      newPiece.getSpot();
      pieces.push_back(newPiece);
    }
  }
  for(int j=2;j>0;j--){
    for(int i=0;i<8;i++){
      Piece newPiece = Piece(i*SPRITE_SIZE+BORDER_SIZE, j*SPRITE_SIZE+(SPRITE_SIZE*5 + BORDER_SIZE), it); 
      it++;
      newPiece.setTeam(1);
      if(j == 1)
	newPiece.setClip(CLIP_PAWN);
      else{
	if(i==0 || i ==7)
	  newPiece.setClip(CLIP_ROOK);
	if(i==1 || i ==6)
	  newPiece.setClip(CLIP_KNIGHT);
	if(i==2 || i ==5)
	  newPiece.setClip(CLIP_BISHOP);
	if(i==4)
	  newPiece.setClip(CLIP_KING);
	if(i==3)
	  newPiece.setClip(CLIP_QUEEN);
      }
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

void netProcess(string msg)
{
  int index, last;
  index = msg.find(" ");
  string cmd = msg.substr(0,index);
  index++;
  
  if(cmd == "MOVE")
  {
    last = index;
    index = msg.find(" ",index);
    string num = msg.substr(last,index-last);
    index++;
    
    last = index;
    index = msg.find(" ",index);
    string s_x= msg.substr(last,index-last);
    
    index++;
    string s_y = msg.substr(index,msg.length()-index);
    int i_num = atoi(num.c_str());

    for(unsigned int i=0;i<pieces.size();i++){
      if(pieces[i].getNum() == i_num){
	pieces[i].setPos(atoi(s_x.c_str()), atoi(s_y.c_str()));
	break;
      }
    }
  }//If- MOVE
  else if(cmd == "REDY")   
  {
    last = index;
    index = msg.find(" ",index);
    string num = msg.substr(last,index-last);
    player_num = atoi(num.c_str());

  }//If- REDY
  else
  {
    cerr << "Unknown command received" << endl;
  }

}

int main ( int argc, char* argv[] )
{
  bool quit = false;
  int x,y;

  // Error check
  if (argc < 2 || argc >= 3)
  {
    cout << "Please retry and enter the ip address"
      << " and a port number." << endl
      << "Example: Frodo 8000" << endl
      << "Shutting Down." << endl;
    return 1;
  }

  //Attempt connection to server. s_socket will be connection socket.
  if(connectServer(argc, argv) == -1)
    return 1;

  //run initialiation and asset loading
  if(init() == false)
    return 1;
  if(load_files() == false)
    return 1;
  set_clips();
  generatePieces();

//// --------------
//// MAIN GAME LOOP
//// --------------
  //While the user hasn't quit
  while(quit == false)
  {

//// ----------
//// SDL EVENTS
//// ----------
    //While theres an event to handle
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_MOUSEBUTTONDOWN)
      {
	if(selected != NULL){//If we are trying to move a piece
	  x = event.button.x;
	  y = event.button.y;

	  //Snap location to grid
	  x = x - x%SPRITE_SIZE;
	  y = y - y%SPRITE_SIZE;

	  //XXX: [Engine] Translate to grid coords

	  //XXX: [Engine] Perform check 
	  //If valid continue
	  //If invalid ignore the command

	  //XXX: [Engine] Send MOVE/CAPT command to server

	  //selected->setPos(x,y);
	  //selected->setClip(CLIP_DEFAULT);

	  stringstream ss;
	  //ss.str("");
	  //ss << selected->getNum() << " " << x << " " << y;
	  ss.str("");
	  ss << "MOVE " << selected->getNum() << x << " " << y;

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

//// ------------------
//// NETWORK CONNECTION
//// ------------------
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
      int bytes = s_socket.readString(msg,64);
      cerr << "Message Received:" << msg << " | " << bytes << endl;

      netProcess(msg);
    }//if- socket has event

//// -------
//// DRAWING
//// -------
    //Make window white instead of black - obselete
    SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

    //Apply the board to the screen
    apply_surface(0, 0, board, screen, NULL);

    //Show() pieces
    for(unsigned int i=0;i<pieces.size();i++)
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
