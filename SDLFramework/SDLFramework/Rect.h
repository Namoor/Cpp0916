#pragma once
#include "SDLInclude.h"

class Rect : public SDL_Rect
{
public:
	Rect(int x, int y, int h, int w);
	Rect();
};