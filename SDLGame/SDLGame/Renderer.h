#pragma once
#include "SDLInclude.h"
#include "Rect.h"

#include "Font.h"

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
	void DrawTexture(Texture* p_pTexture, Rect p_DestinationRect);
	void DrawText(Font* p_pFont, char* p_pString,SDL_Color p_Color, int xPos, int yPos);

public:
	SDL_Renderer* GetRenderer();
};
