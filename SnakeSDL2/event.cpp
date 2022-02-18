#include "event.hpp"
#include <iostream>

eventRequests::eventRequests(SDL_Rect startR, SDL_Rect exitR) {
	this->startR = startR;
	this->exitR = exitR;
}

bool IsInRectangle(int x, int y, const SDL_Rect& rect)
{
	return (x > rect.x) && (x <= rect.x + rect.w) &&
		(y > rect.y) && (y <= rect.y + rect.h);
}

SDL_Event event;

int eventRequests::eventMenu()	//return 2 = start the game.
{
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT or (event.type == SDL_MOUSEBUTTONUP and IsInRectangle(event.button.x, event.button.y, exitR)))
		{
			SDL_Quit();
		}

		if (event.type == SDL_MOUSEBUTTONUP and IsInRectangle(event.button.x, event.button.y, startR))
		{
			std::cout << "1\n";
			return 2;
		}
	}
}