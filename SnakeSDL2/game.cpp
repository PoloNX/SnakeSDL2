#include "game.hpp"
#include "utils.hpp"

gameRequests::gameRequests(SDL_Renderer* renderer, TTF_Font* font) {
	this->renderer = renderer;
	this->font = font;
}

bool isOpen = true;

void gameRequests::printGrid()
{
	int grid_cell_size = 50;
	int grid_width = 450;
	int grid_height = 450;
	// + 1 so that the last grid lines fit in the screen.
	int window_width = (grid_width * grid_cell_size) + 1;
	int window_height = (grid_height * grid_cell_size) + 1;

	SDL_SetRenderDrawColor(renderer, 44, 44, 44, 255);
	for (int x = 25; x < 1 + grid_width * grid_cell_size; x += grid_cell_size) {
		SDL_RenderDrawLine(renderer, x, 25, x, window_height);
	}
	for (int y = 25; y < 1 + grid_height * grid_cell_size ; y += grid_cell_size) {
		SDL_RenderDrawLine(renderer, 25, y, window_width, y);
	}
}

void gameRequests::printSnake()
{


	while (isOpen)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		utilsRequests utils2(font, renderer);
		printGrid();
		utils2.printRect(25, 25, 450, 447, SDL_Color{ 255, 255, 255, 255 }, false);
		utils2.printRect(473, 25, 500, 447, SDL_Color{ 0, 0, 0, 255 }, true);
		utils2.printRect(25, 476, 450, 447, SDL_Color{ 0, 0, 0, 255 }, true);
		utils2.printStringCenter("points : ", 3, 0, false);


		SDL_RenderPresent(renderer);
	}
}