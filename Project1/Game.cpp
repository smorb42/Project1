#include "Game.hpp"
#include "TextureManager.hpp"
#include "Cora.hpp"
#include "GameObject.hpp"

PhysicsObject* player;
GameObject* fT;

Game::Game() 
{}
Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{

	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}


	cnt = 0;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialized..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created..." << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 200, 200, 200, 100);
			std::cout << "Renderer created..." << std::endl;
		}
	
		isRunning = true;
	} else {
		isRunning = false;
	}



	player = new PhysicsObject("cora.png", renderer, 0, 90);
	fT = new GameObject("tile.png", renderer, 100, 70);

}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type){
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break;
	}

}

void Game::update(int trueframeTime)
{

	player->Update(trueframeTime);
	fT->Update(trueframeTime);

	cnt++;
	if (cnt == 14)
	{
		cnt = 10;
	};
	
}

void Game::render()
{
	SDL_RenderClear(renderer);

	player->Render();
	fT->Render();

	SDL_RenderPresent(renderer);

}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	if (window)
	std::cout << "Game Cleaned..." << std::endl;
	


}

bool Game::running()
{
	return isRunning;
}