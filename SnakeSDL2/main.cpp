#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include "menu.hpp"

int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();


	bool isOpen = true;
	TTF_Font* font = TTF_OpenFont("C:\\Windows\\Fonts\\HOOG0555.TTF", 30);
	SDL_Window* pWindow = SDL_CreateWindow("snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
	SDL_SetRenderDrawBlendMode(pRenderer, SDL_BLENDMODE_BLEND);
	menuRequests menu1(font, pRenderer);

	while (isOpen)
	{
		SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
		SDL_RenderClear(pRenderer);
		menu1.printStartMenu();
		SDL_RenderPresent(pRenderer);
	}
	TTF_Quit();
	return 0;
}




