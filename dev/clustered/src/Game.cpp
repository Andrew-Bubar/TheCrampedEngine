#include "Game.h"
#include "textures.h"

SDL_Texture* playertex;
SDL_Rect srcR, destR;

//constructer
Game::Game() {

}

//deconstructer
Game::~Game() {

}

//initionalizer
void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen) {

	//getting the basic window to run and show color
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		//setting up fullscreen
		int flags = 0;
		if (fullscreen) {
			flags = SDL_WINDOW_FULLSCREEN;
		}

		//debuging
		std::cout << "subsystem started" << std::endl;

		//creating the window
		window = SDL_CreateWindow(title, x, y, width, height, flags);
		if (window) {
			std::cout << "window is born" << std::endl;
		}

		//making an sdl renderer/using it
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "rendering is born" << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	//handle textures
	playertex = textures::loadTex("Art\sprites\player\idle\player-idle-1.png", renderer);
	if (playertex == NULL) {
		std::cout << "image error: " << IMG_GetError() << std::endl;
	}
} 

//process window events
void Game::events() {

	SDL_Event eve;
	SDL_PollEvent(&eve);

	switch (eve.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

//updating the game
void Game::update() {

	cnt++;
	destR.h = 64;
	destR.w = 64;

	destR.x = cnt;

	std::cout << "The CNT: " << cnt << std::endl;
}

//render the graphics
void Game::render() {

	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, playertex, NULL, &destR);

	SDL_RenderPresent(renderer);
}

//removing created stuff
void Game::clean() {

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "system cleaned" << std::endl;
}