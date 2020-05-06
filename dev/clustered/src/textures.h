#pragma once
#include "Game.h"

class textures {

public:
	static SDL_Texture* loadTex(const char* filePath, SDL_Renderer* ren);
};