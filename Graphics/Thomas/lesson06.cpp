#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>

using namespace std;

// The attributes of the screen

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

//The image pointers
SDL_Surface* dots = NULL;
SDL_Surface* screen = NULL;

SDL_Event event;

SDL_Rect clip[4];

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
	 Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0x64, 0x64, 0x64);

	 //Set all pixels of a color R 0x64, G 0x64, B 0x64 to be transparent
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
   SDL_WM_SetCaption("Event test", NULL);

   //If everything initialized fine
   return true;
}

bool load_files()
{
   //Load the image
   dots = load_image("dots.png");

   //If there was an error in loading the image
   if(dots == NULL)
      return false;

   //If everythign loaded fine
   return true;
}

void clean_up()
{
   //Free the image
   SDL_FreeSurface(dots);

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

   //clip range for the top left
   clip[0].x = 0;
   clip[0].y = 0;
   clip[0].w = 100;
   clip[0].h = 100;

   //clip range for the top right
   clip[1].x = 100;
   clip[1].y = 0;
   clip[1].w = 100;
   clip[1].h = 100;

   //clip range for the bottom left
   clip[2].x = 0;
   clip[2].y = 100;
   clip[2].w = 100;
   clip[2].h = 100;

   //clip range for the bottom right
   clip[3].x = 100;
   clip[3].y = 100;
   clip[3].w = 100;
   clip[3].h = 100;

   //Fill the screen white
   SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

   apply_surface(0, 0, dots, screen, &clip[0]);
   apply_surface(540, 0, dots, screen, &clip[1]);
   apply_surface(0, 380, dots, screen, &clip[2]);
   apply_surface(540, 380, dots, screen, &clip[3]);
   //Apply the surface to the screen

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
