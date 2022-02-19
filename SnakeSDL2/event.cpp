#include "event.hpp"
#include <iostream>

eventRequests::eventRequests() {

}

bool IsInRectangle(int x, int y, const SDL_Rect& rect)
{
	return (x > rect.x) && (x <= rect.x + rect.w) &&
		(y > rect.y) && (y <= rect.y + rect.h);
}

SDL_Event event;

int eventRequests::eventMenu(SDL_Rect startR, SDL_Rect exitR)	//return 2 = start the game.
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

int eventRequests::eventSnake(int direction)	//return 1 = right, 2 = left, 3 = up, 4 = down
{
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT) {
			SDL_Quit();
		}
		switch (event.type) {

		case SDL_KEYDOWN:
			if ((event.key.keysym.sym == SDLK_RIGHT) or direction == 1)
			{
				return 1;
			}

			else if ((event.key.keysym.sym == SDLK_LEFT) or direction == 2)
			{
				return 2;
			}

			else if ((event.key.keysym.sym == SDLK_UP) or direction == 3)
			{
				return 3;
			}

			else if ((event.key.keysym.sym == SDLK_DOWN) or direction == 4)
			{
				return 4;
			}

			else
				return 0;
		}
	}
}