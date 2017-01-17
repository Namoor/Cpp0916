#pragma once

#include "SDLInclude.h"
#include "Renderer.h"


#include "IGame.h"

class SDLFramework
{
private:
	Renderer* m_pRenderer;
	SDL_Window* m_pWindow;

public:
	void Init();

	void Run(IGame* p_pGame);
};