#include "Game.hpp"

Game* game = nullptr;

int main(int argc, const char *argv[])
{
	
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;
	int trueframeTime = 0;


	game = new Game();
	
	game->init("aGAme", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running()) {

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update(trueframeTime);
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

		trueframeTime = SDL_GetTicks() - frameStart;
	}
	
	game->clean();


	return 0;
}