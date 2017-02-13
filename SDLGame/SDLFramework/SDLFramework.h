#pragma once

#include "SDLInclude.h"
#include "Renderer.h"
#include "Input.h"

#include <time.h>


#include "IGame.h"

class SDLFramework
{
private:
	Renderer* m_pRenderer;
	SDL_Window* m_pWindow;
	Input* m_pInput;
	clock_t m_TimeSinceGameStart;

public:
	void Init();

	void Run(IGame* p_pGame);
};