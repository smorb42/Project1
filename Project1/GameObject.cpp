#include "GameObject.h"
#include "TextureManager.hpp"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);

	xpos = x;
	ypos = y;
}

void GameObject::Update()
{
	xpos++;

	srcRect.h = 24;
	srcRect.w = 24;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 3;
	destRect.h = srcRect.h * 3;
}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}


//Physics




bool Physics::AABBvsAABB(AABB a, AABB b)
{
	// Exit with no intersection if found separated along an axis
	if (a.max.x < b.min.x or a.min.x > b.max.x) return false;
	if (a.max.y < b.min.y or a.min.y > b.max.y) return false;

	// No separating axis found, therefor there is at least one overlapping axis
	return true;
}
