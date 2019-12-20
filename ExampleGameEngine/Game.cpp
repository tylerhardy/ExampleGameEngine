#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* player;
GameObject* enemie;
SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialized!..." << std::endl;
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}

		Game::renderer = SDL_CreateRenderer(window, -1, 0);
		if (Game::renderer)
		{
			SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}

	player = new GameObject("assets/player.png", 0, 0);
	enemie = new GameObject("assets/enemie.png", 50, 50);

}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Game::update()  // Update positions
{
	cnt++;
	std::cout << cnt << std::endl;

	player->Update();
	enemie->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	player->Render();
	enemie->Render();
	// This is where we would add stuff to render
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}