#include <iostream>
using namespace std;
#include "SDLInclude.h"

#include "Rect.h"

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

	SDL_Renderer* _Renderer = SDL_CreateRenderer(_Window, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED | SDL_RendererFlags::SDL_RENDERER_PRESENTVSYNC);
	if (_Renderer == nullptr)
	{
		cout << "Error while initializing renderer";
		return 1;
	}

	SDL_Surface* _pTestSurface = SDL_LoadBMP("TestTexture.bmp");
	SDL_Texture* _TestImage = SDL_CreateTextureFromSurface(_Renderer, _pTestSurface);

	while (true)
	{
		SDL_PollEvent(NULL);
	
		SDL_RenderClear(_Renderer);

		for (int i = 0; i < 10000; i++)
		{
			int x = rand() % 800;
			int y = rand() % 600;

			SDL_RenderCopy(_Renderer, _TestImage, &Rect(0, 0, 400, 400), &Rect(x - 10, y-10, 20, 20));

		}





		SDL_RenderPresent(_Renderer);
	}

	return 0;
}