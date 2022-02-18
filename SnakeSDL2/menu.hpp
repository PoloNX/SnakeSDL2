#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <string>

class menuRequests
{
private:
	SDL_Renderer* renderer;
	TTF_Font* font;
public:
	menuRequests(TTF_Font* font, SDL_Renderer* renderer);

	void printStartMenu();
};
