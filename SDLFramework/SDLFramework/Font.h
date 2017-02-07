#pragma once

#include <SDL_ttf.h>


class Font
{
public:
	Font(char* FontName);

	TTF_Font* _Font;
};