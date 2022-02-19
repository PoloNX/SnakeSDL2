#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <string>

class eventRequests
{
private:

public:
	eventRequests();
	int eventMenu(SDL_Rect startR, SDL_Rect exitR);
	int eventSnake(int direction);
};
