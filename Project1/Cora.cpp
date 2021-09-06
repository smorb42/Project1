

#include "Cora.hpp"


Cora::Cora()
{
}

Cora::~Cora()
{
}


SDL_Rect Cora::Update(int i, int scale)
{
	SDL_Rect dest, tileR;
	dest.h = 24 * scale;
	dest.w = 24 * scale;
	dest.x = 0 * scale;

	tileR.h = 24;
	tileR.w = 24;
	tileR.x = i * 24;

	return dest, tileR;
}
