#include "Font.h"

#include <iostream>
using namespace std;

Font::Font(char* FontName)
{
	_Font = TTF_OpenFont(FontName, 24);

	if (_Font == nullptr)
	{
		cout << FontName << "konnte nicht geladen werden: " << TTF_GetError() << "\n";
	}
}