#include "Game.h"
#include "TextureManager.h"
#include <iostream>

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	// attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
		if (m_pWindow != 0) // window init success
		{
			std::cout << "window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0) // renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer,	0, 0, 0, 255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}


	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	std::cout << "init success\n";
	m_bRunning = true; // everything inited successfully, start the main loop

	//m_textureManager.load("assets/animate-alpha.png", "animate", m_pRenderer);
	if(!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
	{
		return false;
	}

	//SDL_Surface* pTempSurface = SDL_LoadBMP("assets/animate.bmp");
	//SDL_Surface* pTempSurface = IMG_Load("assets/animate-alpha.png");
	//m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	//SDL_FreeSurface(pTempSurface);
	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

	//m_sourceRectangle.w = 128;
	//m_sourceRectangle.h = 82;
	
	//m_destinationRectangle.x = m_sourceRectangle.x = 0;
	//m_destinationRectangle.y = m_sourceRectangle.y = 0;
		
	//m_destinationRectangle.w = m_sourceRectangle.w;
	//m_destinationRectangle.h = m_sourceRectangle.h;

	return true;
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::update()
{
	//m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Game::render()
{
	//SDL_RenderClear(m_pRenderer); // clear the renderer to 	the draw color
	//SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle,	&m_destinationRectangle);
	//SDL_RenderPresent(m_pRenderer); // draw to the screen

	//SDL_RenderClear(m_pRenderer);
	//SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_HORIZONTAL); // pass in the horizontal flip
	//SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_NONE); // pass in the horizontal flip
	//SDL_RenderPresent(m_pRenderer);

	SDL_RenderClear(m_pRenderer);
	//m_textureManager.draw("animate", 0,0, 128, 82, m_pRenderer);
	TheTextureManager::Instance()->draw("animate", 0,0, 128, 82, m_pRenderer);
	//m_textureManager.drawFrame("animate", 100,100, 128, 82, 1, m_currentFrame, m_pRenderer);
	TheTextureManager::Instance()->drawFrame("animate", 100,100, 128, 82, 1, m_currentFrame,  m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				m_bRunning = false;
				break;
			default:
				break;
		}
	}
}
