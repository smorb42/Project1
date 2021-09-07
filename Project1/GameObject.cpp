#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);

	xpos = x;
	ypos = y;
}

void GameObject::Update(int trueframeTime)
{

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

Vector2 multAdd(Vector2 addvector,Vector2 multvector, int w) {
	addvector.x += multvector.x * w;
	addvector.y += multvector.y * w;
	return addvector;
}

bool PhysicsObject::AABBvsAABB(AABB a, AABB b)
{
	// Exit with no intersection if found separated along an axis
	if (a.max.x < b.min.x or a.min.x > b.max.x) return false;
	if (a.max.y < b.min.y or a.min.y > b.max.y) return false;

	// No separating axis found, therefor there is at least one overlapping axis
	return true;
}


void  PhysicsObject::UpdatePhysics(int trueframeTime)
{
	mOldPosition = mPosition;
	mOldSpeed = mSpeed;

	mWasOnGround = mOnGround;
	mPushedRightWall = mPushesRightWall;
	mPushedLeftWall = mPushesLeftWall;
	mWasAtCeiling = mAtCeiling;

	mPosition = multAdd(mPosition, mSpeed , trueframeTime);

	if (mPosition.y < 0.0f)
	{
		mPosition.y = 0.0f;
		mOnGround = true;
	}
	else
		mOnGround = false;



}