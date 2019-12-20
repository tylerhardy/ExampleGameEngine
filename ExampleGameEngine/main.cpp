#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int FrameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("HardyEngine", 800, 640, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();		// handle any user inputs
		game->update();				// update all object eg. positions etc.
		game->render();				// render changes to the display

		frameTime = SDL_GetTicks() - frameStart;

		if (FrameDelay > frameTime)
		{
			SDL_Delay(FrameDelay - frameTime);
		}
	}

	game->clean();

	return 0;
}