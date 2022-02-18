#include "utils.hpp"

utilsRequests::utilsRequests(TTF_Font* font, SDL_Renderer* renderer) {
	this->font = font;
	this->renderer = renderer;
}

SDL_Rect utilsRequests::printStringCenter(std::string text, int y, int addToX, bool printRect)
{
	SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), SDL_Color{ 255, 255, 255, 255 });
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	int t_w;
	int t_h;
	SDL_QueryTexture(texture, nullptr, nullptr, &t_w, &t_h);
	SDL_Rect rect{ (500 / 2 - t_w / 2) + addToX ,y,t_w,t_h };
	SDL_RenderCopy(renderer, texture, nullptr, &rect);
	if (printRect)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawRect(renderer, &rect);
	}
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	return rect;
}