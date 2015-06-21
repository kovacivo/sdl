#ifndef __TextureManager__
#define __TextureManager__

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <string>
#include <map>
#include <iostream>

using namespace std;

class TextureManager
{
	public:
		TextureManager() {}
		~TextureManager() {}

		bool load(string fileName,string id, SDL_Renderer* pRenderer);

		// draw
		void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

		// drawframe
		void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

		std::map<std::string, SDL_Texture*> m_textureMap;

	private:
		int m_currentFrame;
};

#endif
