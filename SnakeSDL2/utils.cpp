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
	SDL_Rect rect{ (500 / 2 - t_w / 2) + addToX,y,t_w,t_h };
	SDL_RenderCopy(renderer, texture, nullptr, &rect);
	if (printRect)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_Rect rect1{ ((500 / 2 - t_w / 2) + addToX) - 2,y - 3,t_w,t_h };
		SDL_RenderDrawRect(renderer, &rect1);
	}
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
	return rect;
}

void utilsRequests::printRect(int x, int y, int h, int w, SDL_Color color, bool fill)
{
	SDL_Rect rect{ x, y, w ,h };
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	if (fill)
	{
		SDL_RenderFillRect(renderer, &rect);
	}
	else
	{
		SDL_RenderDrawRect(renderer, &rect);
	}
}