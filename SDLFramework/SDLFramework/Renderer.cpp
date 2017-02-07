#include "Renderer.h"
#include "Texture.h"
#include <iostream>

using namespace std;

Renderer::Renderer(SDL_Window* p_pWindow)
{
	m_pRenderer = SDL_CreateRenderer(p_pWindow, -1, 
		SDL_RendererFlags::SDL_RENDERER_ACCELERATED | SDL_RendererFlags::SDL_RENDERER_PRESENTVSYNC);

	if (m_pRenderer == nullptr)
	{
		cout << "Fehler beim initialisieren des Renderers!" << "\n";
		return;
	}
}


void Renderer::Clear()
{
	SDL_RenderClear(m_pRenderer);
}

void Renderer::Present()
{
	SDL_RenderPresent(m_pRenderer);
}

void Renderer::DrawTexture(Texture* p_pTexture, Rect p_SourceRect, Rect p_DestinationRect)
{
	SDL_RenderCopy(m_pRenderer, p_pTexture->GetTexture(), &p_SourceRect, &p_DestinationRect);
}

void Renderer::DrawTexture(Texture* p_pTexture, Rect p_DestinationRect)
{
	SDL_RenderCopy(m_pRenderer, p_pTexture->GetTexture(), nullptr, &p_DestinationRect);
}


void Renderer::DrawText(Font* p_pFont, char* p_pString, SDL_Color p_Color, int xPos, int yPos)
{
	SDL_Surface* _Surface = TTF_RenderText_Blended(p_pFont->_Font, p_pString, p_Color);

	SDL_Texture* _Texture = SDL_CreateTextureFromSurface(m_pRenderer, _Surface);

	int w, h;
	SDL_QueryTexture(_Texture, nullptr, nullptr, &w, &h);

	SDL_Rect dst;
	dst.w = w;
	dst.h = h;
	dst.x = xPos;
	dst.y = yPos;

	SDL_RenderCopy(m_pRenderer, _Texture, nullptr, &dst);

	SDL_DestroyTexture(_Texture);
	SDL_FreeSurface(_Surface);

}


SDL_Renderer* Renderer::GetRenderer()
{
	return m_pRenderer;
}