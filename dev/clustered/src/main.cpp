#include "Game.h"

Game* g = nullptr;

int main(int argc, char* argv[]) {

	//set FPS
	const int fps = 60;
	const int frameDelay = 1000 / fps;

	Uint32 framestart;
	int frametime;

	g = new Game();
	g->init("the test for Clustered", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600, false);

	while (g->running()) {

		//fps
		framestart = SDL_GetTicks();

		g->events();
		g->update();
		g->render();

		frametime = SDL_GetTicks() - framestart;
		if (frameDelay > frametime) {

			SDL_Delay(frameDelay - frametime);
		}
	}

	g->clean();

	return 0;
}