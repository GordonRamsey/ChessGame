#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>

class StringInput
{
  private:
    std::string str;

    SDL_Surface *text;

  public:
    StringInput();

    ~StringInput();

    void setSurface(SDL_Surface* surf);
    std::string getText();
    void addChar(char c);
    void reset();

    void handle_input(SDL_Event event, TTF_Font* font, SDL_Color textColor);

    void show_centered();
};

