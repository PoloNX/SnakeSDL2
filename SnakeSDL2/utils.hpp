#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <string>

class utilsRequests
{
private:
	SDL_Renderer* renderer;
	TTF_Font* font;

public:
	utilsRequests(TTF_Font* font, SDL_Renderer* renderer);

	SDL_Rect printStringCenter(std::string text, int y, int addToX, bool printRect);
	void printRect(int x, int y, int w, int h, SDL_Color color, bool fill);
}; 
