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


SDL_Renderer* Renderer::GetRenderer()
{
	return m_pRenderer;
}