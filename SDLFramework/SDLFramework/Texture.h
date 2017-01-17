#pragma once

#include "SDLInclude.h"


class Renderer;

class Texture
{
private:
	SDL_Texture* m_pTexture;

public:
	Texture(char* p_pFileName, Renderer* p_pRenderer);

public:
	SDL_Texture* GetTexture();
};
