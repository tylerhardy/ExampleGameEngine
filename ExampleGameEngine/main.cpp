#include "Game.h"


Game* game = nullptr;

int main(int argc, char* argv[])
{
	game = new Game();
	game->init("HardyEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running())
	{
		game->handleEvents();		// handle any user inputs
		game->update();				// update all object eg. positions etc.
		game->render();				// render changes to the display
	}

	game->clean();

	return 0;
}