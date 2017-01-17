#include <iostream>
using namespace std;
#include "SDLInclude.h"

#include "Rect.h"

#include "Texture.h"
#include "Renderer.h"

int main(int ArgC, char* ArgV[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		cout << "Error while initializing video";
		return 1;
	}

	SDL_Window* _Window = SDL_CreateWindow("TestWindow", 50, 50, 800, 600, SDL_WindowFlags::SDL_WINDOW_SHOWN);
	if (_Window == nullptr)
	{
		cout << "Error while initializing window";
		return 1;
	}

	
	Renderer* _pRenderer = new Renderer(_Window);

	//SDL_Surface* _pTestSurface = SDL_LoadBMP("TestTexture.bmp");
	//SDL_Texture* _TestImage = SDL_CreateTextureFromSurface(_Renderer, _pTestSurface);
	
	Texture* _pTexture = new Texture("TestTexture.bmp", _pRenderer);

	while (true)
	{
		SDL_PollEvent(NULL);
	
		//SDL_RenderClear(_pRenderer->GetRenderer());
		_pRenderer->Clear();

		for (int i = 0; i < 500000; i++)
		{
			int x = rand() % 800;
			int y = rand() % 600;

			//SDL_RenderCopy(_pRenderer->GetRenderer(), _pTexture->GetTexture(), &Rect(0, 0, 400, 400), &Rect(x - 10, y-10, 20, 20));
			_pRenderer->DrawTexture(_pTexture, Rect(0, 0, 400, 400), Rect(x - 10, y - 10, 20, 20));
		}

		//SDL_RenderPresent(_pRenderer->GetRenderer());
		_pRenderer->Present();
	}

	return 0;
}