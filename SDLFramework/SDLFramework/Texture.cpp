#include "Texture.h"
#include "Renderer.h"

Texture::Texture(char* p_pFileName, Renderer* p_pRenderer)
{
	// Je nach Fileendung 
	
	// .bmp
	SDL_Surface* _pTestSurface = SDL_LoadBMP(p_pFileName);
	m_pTexture = SDL_CreateTextureFromSurface(p_pRenderer->GetRenderer(), _pTestSurface);
}

SDL_Texture* Texture::GetTexture()
{
	return m_pTexture;
}