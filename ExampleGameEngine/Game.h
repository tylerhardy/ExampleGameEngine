#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game
{

public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen); // Constructor

	void handleEvents();
	void update();							// Go through game objects and update them 
	bool running() { return isRunning; };	// Let the main function know that the game is still running
	void render();							// Render to screen
	void clean();							// Memory Management

private:
	int cnt = 0;
	bool isRunning;							// Ask the game class if it is running, if true it will run the loop again
	SDL_Window* window;
	SDL_Renderer* renderer;
};