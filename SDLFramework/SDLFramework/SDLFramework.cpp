#include "SDLFramework.h"
#include <iostream>
#include <SDL_image.h>



using namespace std;

void SDLFramework::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		cout << "Error while initializing video\n";
		return;
	}

	m_pWindow = SDL_CreateWindow("TestWindow", 50, 50, 800, 600, SDL_WindowFlags::SDL_WINDOW_SHOWN);
	if (m_pWindow == nullptr)
	{
		cout << "Error while initializing window\n";
		return;
	}


	m_pRenderer = new Renderer(m_pWindow);

	m_pInput = new Input();

	if(IMG_Init(IMG_InitFlags::IMG_INIT_JPG | IMG_InitFlags::IMG_INIT_PNG) != (IMG_InitFlags::IMG_INIT_JPG | IMG_InitFlags::IMG_INIT_PNG))
	{
		cout << "Error while initializing SDL_image\n";
		return;
	}

}

void SDLFramework::Run(IGame* p_pGame)
{
	//ShowcaseGame* _pGame = new ShowcaseGame();

	m_TimeSinceGameStart = clock();

	//SDL_Surface* _pTestSurface = SDL_LoadBMP("TestTexture.bmp");
	//SDL_Texture* _TestImage = SDL_CreateTextureFromSurface(_Renderer, _pTestSurface);
	p_pGame->Init(m_pRenderer);

	while (true)
	{
		m_pInput->FlushKeys();


		SDL_Event _Event;
		while(SDL_PollEvent(&_Event) == 1)
		{
			if(_Event.type == SDL_EventType::SDL_QUIT)
			{
				return;
			}

			if (_Event.type == SDL_EventType::SDL_KEYDOWN || _Event.type == SDL_EventType::SDL_KEYUP)
			{
				m_pInput->ParseEvent(_Event);
			}

		}



		clock_t _Now = clock();
		float DeltaTime = _Now - m_TimeSinceGameStart;
		m_TimeSinceGameStart = _Now;

		p_pGame->Update(DeltaTime  / CLOCKS_PER_SEC);

		//SDL_RenderClear(_pRenderer->GetRenderer());
		m_pRenderer->Clear();

		p_pGame->Draw(m_pRenderer);

		//SDL_RenderPresent(_pRenderer->GetRenderer());
		m_pRenderer->Present();
	}
}