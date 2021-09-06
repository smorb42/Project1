#ifndef Game_hpp
#define Game_hpp

#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game {

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();
	const int scale = 3;

private:
	int cnt = 0;
	bool isRunning = true;
	SDL_Window *window;
	SDL_Renderer* renderer;

};


#endif /* Game_hpp */ 