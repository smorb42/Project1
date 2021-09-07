#pragma once
#include "Game.hpp"

//Texture and object managment

class GameObject {

public:
	GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~GameObject();
	
	void Update(int trueframeTime);
	void Render();

protected:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};

//Defining Vectors


struct Vector2
{

	float x;
	float y;

};

struct AABB
{
	Vector2 min;
	Vector2 max;
};


// objects with physics

class PhysicsObject : public GameObject {
	

public:

	using GameObject::GameObject;


	// functions
	bool AABBvsAABB(AABB a, AABB b);
	void UpdatePhysics(int trueframeTime);

	// movment

	Vector2 mOldPosition;
	Vector2 mPosition;

	Vector2 mOldSpeed;
	Vector2 mSpeed;

	Vector2 mScale;

	AABB mAABB;

	Vector2 mAABBOffset;

	// pos state

	bool mPushedRightWall;
	bool mPushesRightWall;

	bool mPushedLeftWall;
	bool mPushesLeftWall;

	bool mWasOnGround;
	bool mOnGround;

	bool mWasAtCeiling;
	bool mAtCeiling;

private:



};

class Character : public PhysicsObject
{


};
