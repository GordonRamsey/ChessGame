#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Piece
{
   private:
      SDL_Rect box;
      SDL_Rect* clip;

   public:
      Piece(int x, int y);
      void setPos(int x, int y);
      void setClip(int x);
      void handle_events();
      void show();
};

int CLIP_PAWN = 0;
int CLIP_ROOK = 1;
int CLIP_BISHOP = 2;
int CLIP_KNIGHT = 3;
int CLIP_QUEEN = 4;
int CLIP_KING = 5;

// The attributes of the screen
const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 512;
const int SCREEN_BPP = 32;

//The image pointers
SDL_Surface* board = NULL;
SDL_Surface* piece = NULL;
SDL_Surface* piece2 = NULL;
SDL_Surface* screen = NULL;

//Event Driven
SDL_Event event;
SDL_Rect clips[6];

//The selected piece
Piece* selected = NULL;
vector<Piece> pieces;

void set_clips()
{
   clips[CLIP_PAWN].x = 0;
   clips[CLIP_PAWN].y = 0;
   clips[CLIP_PAWN].w = 32;
   clips[CLIP_PAWN].h = 32;

   clips[CLIP_ROOK].x = 32;
   clips[CLIP_ROOK].y = 0;
   clips[CLIP_ROOK].w = 32;
   clips[CLIP_ROOK].h = 32;

   clips[CLIP_BISHOP].x = 64;
   clips[CLIP_BISHOP].y = 0;
   clips[CLIP_BISHOP].w = 32;
   clips[CLIP_BISHOP].h = 32;

   clips[CLIP_KNIGHT].x = 96;
   clips[CLIP_KNIGHT].y = 0;
   clips[CLIP_KNIGHT].w = 32;
   clips[CLIP_KNIGHT].h = 32;

   clips[CLIP_QUEEN].x = 128;
   clips[CLIP_QUEEN].y = 0;
   clips[CLIP_QUEEN].w = 32;
   clips[CLIP_QUEEN].h = 32;

   clips[CLIP_KING].x = 160;
   clips[CLIP_KING].y = 0;
   clips[CLIP_KING].w = 32;
   clips[CLIP_KING].h = 32;
}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL)
{
   //Make a temporary rectangle to hld the offsets
   SDL_Rect offset;

   //Give the offsets to the rectangle
   offset.x = x;
   offset.y = y;

   //Blit the surface
   SDL_BlitSurface(source, clip, destination, &offset);

}

Piece::Piece(int x, int y)
{
   //Set the button's attributes
   box.x = x;
   box.y = y;
   box.w = 32;
   box.h = 32;
   clip = &clips[CLIP_PAWN]; //XXX
}

void Piece::handle_events()
{
   int x = 0, y = 0;

   if(event.type == SDL_MOUSEBUTTONDOWN){
      if(event.button.button == SDL_BUTTON_LEFT){
	 x = event.button.x;
	 y = event.button.y;

	 if((x > box.x) and (x < box.x + box.w) and (y > box.y) and (y < box.y + box.h)){
	    clip = &clips[CLIP_PAWN]; //XXX
	    selected = this;
	 }
      }
   }
}

void Piece::show()
{
   apply_surface(box.x, box.y, piece, screen, clip);
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

SDL_Surface *load_image(string filename) //file is the image to be loaded
{
   //Temporary storage for the image that's loaded
   SDL_Surface* loadedImage = NULL; // what we get when loaded

   //The optimized image that will be used
   SDL_Surface* optimizedImage = NULL; // what we will be using

   //Load the image
   loadedImage = IMG_Load(filename.c_str());

   //If nothign went wrong loading the image
   if(loadedImage != NULL){
      //Create an optimized image
      optimizedImage = SDL_DisplayFormat(loadedImage);

      //Free the old image
      SDL_FreeSurface(loadedImage);

      //If the image was optimized just fine
      if(optimizedImage != NULL){
	 //Map the colokey
	 Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0xFF, 0xFF, 0xFF);

	 //Set all pixels of a color R 0xFF, G 0xFF, B 0xFF (white) to be transparent
	 SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
      }
   }
   //Return the optimized image
   return optimizedImage;
}

bool init()
{
   //Initialize all SDL subsystems
   if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
      return false;

   //Set up the screen
   screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

   //If there was an error in the setting up the screen
   if(screen==NULL)
      return false;

   //SEt the window caption
   SDL_WM_SetCaption("Two Player Gentleman's Chess", NULL);

   //If everything initialized fine
   return true;
}

bool load_files()
{
   board = load_image("twoPlayerBoard.png");
   if(board == NULL)
      return false;

   piece = load_image("basicPieces.png");
   if(piece == NULL)
      return false;

   piece2 = load_image("basicPieces2.png");
   if(piece2 == NULL)
      return false;

   //If everythign loaded fine
   return true;
}

void clean_up()
{
   SDL_FreeSurface(board);
   SDL_FreeSurface(piece);
   SDL_FreeSurface(piece2);

   SDL_Quit();
}

void generatePieces()
{
   for(int i=0; i<8; ++i){
      for(int j=0; j<2; ++j){
	 Piece newPiece = Piece(i*32+128, j*32+160);
      }
   }

   for(int i=0; i<8; ++i){
      for(int j=0; j<2; ++j){
	 Piece newPiece = Piece(i*32+128, j*32+320);
      }
   }
}

int main(int argc, char* args[])
{
   //Makesure the program waits for a quit
   bool quit = false;
   int x, y;

   //Initialize
   if(init() == false)
      return 1;

   //Load the file
   if(load_files() == false)
      return 1;

   //Fill the screen white
   SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

   //Place board
   apply_surface(0, 0, board, screen);

   set_clips();
   generatePieces();

   //While the user hasn't quit
   while(quit == false){
      //While there's an event to handle
      while(SDL_PollEvent(&event)){
	 if(event.type == SDL_MOUSEBUTTONDOWN){
	    if(selected != NULL){
	       x = event.button.x;
	       y = event.button.y;

	       selected->setPos(x-16,y-16);
	       selected->setClip(CLIP_PAWN);
	       selected = NULL;
	       continue;
	    }
	 }

	 for(int i=0; i<pieces.size(); ++i)
	    pieces[i].handle_events();

	 for(int i=0; i<pieces.size(); ++i)
	    pieces[i].show();

	 //If teh user has Xed out the window
	 if(event.type == SDL_QUIT){
	    //Quit the program
	    quit = true;
	 }
	 //Update the screen
	 if(SDL_Flip(screen) == -1)
	    return 1;

      }
   }
   //Free the surface and quit SDL
   clean_up();

   return 0;
}

/*
//Place pawns 1
apply_surface(128, 160, piece, screen, &clips[0]);
apply_surface(160, 160, piece, screen, &clips[0]);
apply_surface(192, 160, piece, screen, &clips[0]);
apply_surface(224, 160, piece, screen, &clips[0]);
apply_surface(256, 160, piece, screen, &clips[0]);
apply_surface(288, 160, piece, screen, &clips[0]);
apply_surface(320, 160, piece, screen, &clips[0]);
apply_surface(352, 160, piece, screen, &clips[0]);

//Place back row 1
apply_surface(128, 128, piece, screen, &clips[1]);
apply_surface(160, 128, piece, screen, &clips[3]);
apply_surface(192, 128, piece, screen, &clips[2]);
apply_surface(224, 128, piece, screen, &clips[5]);
apply_surface(256, 128, piece, screen, &clips[4]);
apply_surface(288, 128, piece, screen, &clips[2]);
apply_surface(320, 128, piece, screen, &clips[3]);
apply_surface(352, 128, piece, screen, &clips[1]);

//Place pawn set 2
apply_surface(128, 320, piece2, screen, &clips[0]);
apply_surface(160, 320, piece2, screen, &clips[0]);
apply_surface(192, 320, piece2, screen, &clips[0]);
apply_surface(224, 320, piece2, screen, &clips[0]);
apply_surface(256, 320, piece2, screen, &clips[0]);
apply_surface(288, 320, piece2, screen, &clips[0]);
apply_surface(320, 320, piece2, screen, &clips[0]);
apply_surface(352, 320, piece2, screen, &clips[0]);

apply_surface(128, 352, piece2, screen, &clips[1]);
apply_surface(160, 352, piece2, screen, &clips[3]);
apply_surface(192, 352, piece2, screen, &clips[2]);
apply_surface(224, 352, piece2, screen, &clips[4]);
apply_surface(256, 352, piece2, screen, &clips[5]);
apply_surface(288, 352, piece2, screen, &clips[2]);
apply_surface(320, 352, piece2, screen, &clips[3]);
apply_surface(352, 352, piece2, screen, &clips[1]);
 */
