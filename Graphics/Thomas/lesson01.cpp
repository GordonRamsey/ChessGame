#include <SDL/SDL.h>

int main(int argc, char* args[])
{
   //The images
   SDL_Surface* chess = NULL;
   SDL_Surface* screen = NULL;

   //Start SDL
   SDL_Init(SDL_INIT_EVERYTHING);

   //Set up screen
   screen = SDL_SetVideoMode(800, 800, 32, SDL_SWSURFACE);

   //Load image
   chess = SDL_LoadBMP("Chess_Board.bmp");

   //Apply image to the screen
   SDL_BlitSurface(chess, NULL, screen, NULL);

   //Update Screen
   SDL_Flip(screen);

   //Pasue
   SDL_Delay(10000); // 10 sec

   //Free the loaded image
   SDL_FreeSurface(chess);

   //Quit SDL
   SDL_Quit();

   return 0;
}
