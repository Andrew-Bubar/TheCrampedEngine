#include "textures.h"

SDL_Texture* textures::loadTex(const char* fileName, SDL_Renderer* ren) {

	SDL_Surface* tsurf = IMG_Load(fileName);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tsurf);
	SDL_FreeSurface(tsurf);

	return tex;
}