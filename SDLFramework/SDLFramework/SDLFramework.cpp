#include "SDLFramework.h"
#include <iostream>


using namespace std;

void SDLFramework::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		cout << "Error while initializing video";
		return;
	}

	m_pWindow = SDL_CreateWindow("TestWindow", 50, 50, 800, 600, SDL_WindowFlags::SDL_WINDOW_SHOWN);
	if (m_pWindow == nullptr)
	{
		cout << "Error while initializing window";
		return;
	}


	m_pRenderer = new Renderer(m_pWindow);
}

void SDLFramework::Run(IGame* p_pGame)
{
	//ShowcaseGame* _pGame = new ShowcaseGame();



	//SDL_Surface* _pTestSurface = SDL_LoadBMP("TestTexture.bmp");
	//SDL_Texture* _TestImage = SDL_CreateTextureFromSurface(_Renderer, _pTestSurface);
	p_pGame->Init(m_pRenderer);

	while (true)
	{
		SDL_PollEvent(NULL);

		//SDL_RenderClear(_pRenderer->GetRenderer());
		m_pRenderer->Clear();

		p_pGame->Draw(m_pRenderer);

		//SDL_RenderPresent(_pRenderer->GetRenderer());
		m_pRenderer->Present();
	}
}