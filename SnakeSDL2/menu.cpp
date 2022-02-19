#include "menu.hpp"
#include "utils.hpp"
#include "event.hpp"
#include "game.hpp"

menuRequests::menuRequests(TTF_Font* font, SDL_Renderer* renderer) {
	this->font = font;
	this->renderer = renderer;
}

void menuRequests::printStartMenu()
{	
	utilsRequests utils1(font, renderer);
	utils1.printStringCenter("snake", 50, 0, false);
	SDL_Rect startR = utils1.printStringCenter("Start", 250, -100, true);
	SDL_Rect exitR = utils1.printStringCenter("Exit", 250, 100, true);
	eventRequests event1;
	if (event1.eventMenu(startR, exitR) == 2)
	{
		gameRequests game1(renderer, font);
		game1.printSnake();
	}
}