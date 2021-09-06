#ifndef Cora_hpp
#define Cora_hpp


#include "game.hpp"

class Cora
{
public:
	Cora();
	~Cora();

	SDL_Rect Update(int i, int scale);




private:
	int xC;
	int yC;

};

#endif