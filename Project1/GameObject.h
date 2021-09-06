#pragma once
#include "Game.hpp"

//Texture and object managment

class GameObject {

public:
	GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~GameObject();
	
	void Update();
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

class Physics : public GameObject {



public:
	bool AABBvsAABB(AABB a, AABB b);



private:



};
