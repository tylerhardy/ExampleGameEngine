#include "SDL.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	cout << "Window Initialization..." << endl;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);

	SDL_Delay(3000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	cout << "Window Initialization done" << endl;

	return 0;
}