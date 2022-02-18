#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <string>

class eventRequests
{
private:
	SDL_Rect startR;
	SDL_Rect exitR;
public:
	eventRequests(SDL_Rect startR, SDL_Rect exitR);
	void eventMenu();
};
