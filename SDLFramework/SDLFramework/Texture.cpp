#include "Texture.h"
#include "Renderer.h"
#include <SDL_image.h>
#include <iostream>

Texture::Texture(char* p_pFileName, Renderer* p_pRenderer)
{
	// Je nach Fileendung 
	
	// .bmp
	//SDL_Surface* _pTestSurface = SDL_LoadBMP(p_pFileName);
	//m_pTexture = SDL_CreateTextureFromSurface(p_pRenderer->GetRenderer(), _pTestSurface);

	m_pTexture = IMG_LoadTexture(p_pRenderer->GetRenderer(), p_pFileName);
	if(m_pTexture == nullptr)
	{
		std::cout << "[Error] Couldn't load Texture " << p_pFileName << ": " << IMG_GetError() << "\n";
	}
}



Texture::~Texture()
{
	SDL_DestroyTexture(m_pTexture);
}

SDL_Texture* Texture::GetTexture()
{
	return m_pTexture;
}