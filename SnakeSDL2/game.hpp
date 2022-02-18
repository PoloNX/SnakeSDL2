#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <string>

class gameRequests
{
private:
	SDL_Renderer* renderer;
	TTF_Font* font;
public:
	gameRequests(SDL_Renderer* renderer, TTF_Font* font);
	void printSnake();
	void printGrid();
};
