#pragma once
#include "SDLInclude.h"
#include "Rect.h"

class Texture;

class Renderer
{
private:
	SDL_Renderer* m_pRenderer;

public:
	Renderer(SDL_Window* p_pWindow);

public:
	void Clear();
	void Present();
	void DrawTexture(Texture* p_pTexture, Rect p_SourceRect, Rect p_DestinationRect);

public:
	SDL_Renderer* GetRenderer();
};
