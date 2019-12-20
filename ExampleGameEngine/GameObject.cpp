#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y)
{
	// Create object texture
	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;
}

void GameObject::Update()
{
	// Pass in update code
	xpos++;
	ypos++;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void GameObject::Render()
{
	// Pass in Render code
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}