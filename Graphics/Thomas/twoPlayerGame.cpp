#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>

using namespace std;

// The attributes of the screen

const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 512;
const int SCREEN_BPP = 32;

//The image pointers
SDL_Surface* board = NULL;
SDL_Surface* piece = NULL;
SDL_Surface* piece2 = NULL;
SDL_Surface* screen = NULL;

SDL_Event event;

SDL_Rect clip[6];

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
   //Load the image
   board = load_image("twoPlayerBoard.png");

   //If there was an error in loading the image
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
   //Free the image
   SDL_FreeSurface(board);
   SDL_FreeSurface(piece);
   SDL_FreeSurface(piece2);


   //Quit SDL
   SDL_Quit();
}

int main(int argc, char* args[])
{
   //Makesure the program waits for a quit
   bool quit = false;

   //Initialize
   if(init() == false)
      return 1;

   //Load the file
   if(load_files() == false)
      return 1;

   //clip range for the pawn
   clip[0].x = 0;
   clip[0].y = 0;
   clip[0].w = 32;
   clip[0].h = 32;

   //clip range for the rook
   clip[1].x = 32;
   clip[1].y = 0;
   clip[1].w = 32;
   clip[1].h = 32;

   //clip range for the bishop
   clip[2].x = 64;
   clip[2].y = 0;
   clip[2].w = 32;
   clip[2].h = 32;

   //clip range for the knight
   clip[3].x = 96;
   clip[3].y = 0;
   clip[3].w = 32;
   clip[3].h = 32;

   //clip range for the queen
   clip[4].x = 128;
   clip[4].y = 0;
   clip[4].w = 32;
   clip[4].h = 32;

   //clip range for the king
   clip[5].x = 160;
   clip[5].y = 0;
   clip[5].w = 32;
   clip[5].h = 32;
 
   //Fill the screen white
   SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
   //Place board
   apply_surface(0, 0, board, screen);
   //Place pawns 1
   apply_surface(128, 160, piece, screen, &clip[0]);
   apply_surface(160, 160, piece, screen, &clip[0]);
   apply_surface(192, 160, piece, screen, &clip[0]);
   apply_surface(224, 160, piece, screen, &clip[0]);
   apply_surface(256, 160, piece, screen, &clip[0]);
   apply_surface(288, 160, piece, screen, &clip[0]);
   apply_surface(320, 160, piece, screen, &clip[0]);
   apply_surface(352, 160, piece, screen, &clip[0]);

   //Place back row 1
   apply_surface(128, 128, piece, screen, &clip[1]);
   apply_surface(160, 128, piece, screen, &clip[3]);
   apply_surface(192, 128, piece, screen, &clip[2]);
   apply_surface(224, 128, piece, screen, &clip[5]);
   apply_surface(256, 128, piece, screen, &clip[4]);
   apply_surface(288, 128, piece, screen, &clip[2]);
   apply_surface(320, 128, piece, screen, &clip[3]);
   apply_surface(352, 128, piece, screen, &clip[1]);

   //Place pawn set 2
   apply_surface(128, 320, piece2, screen, &clip[0]);
   apply_surface(160, 320, piece2, screen, &clip[0]);
   apply_surface(192, 320, piece2, screen, &clip[0]);
   apply_surface(224, 320, piece2, screen, &clip[0]);
   apply_surface(256, 320, piece2, screen, &clip[0]);
   apply_surface(288, 320, piece2, screen, &clip[0]);
   apply_surface(320, 320, piece2, screen, &clip[0]);
   apply_surface(352, 320, piece2, screen, &clip[0]);
   
   apply_surface(128, 352, piece2, screen, &clip[1]);
   apply_surface(160, 352, piece2, screen, &clip[3]);
   apply_surface(192, 352, piece2, screen, &clip[2]);
   apply_surface(224, 352, piece2, screen, &clip[4]);
   apply_surface(256, 352, piece2, screen, &clip[5]);
   apply_surface(288, 352, piece2, screen, &clip[2]);
   apply_surface(320, 352, piece2, screen, &clip[3]);
   apply_surface(352, 352, piece2, screen, &clip[1]);

   //Update the screen
   if(SDL_Flip(screen) == -1)
      return 1;

   //While the user hasn't quit
   while(quit == false){
      //While there's an event to handle
      while(SDL_PollEvent(&event)){
	 //If teh user has Xed out the window
	 if(event.type == SDL_QUIT){
	    //Quit the program
	    quit = true;
	 }
      }
   }
   //Free the surface and quit SDL
   clean_up();

   return 0;
}
