#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int x, int y, int width, int height, bool fullscreen);
	void update();
	void render();
	void clean();
	void events();
	
	bool running() { return isRunning; }

private:
	int cnt;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

};

