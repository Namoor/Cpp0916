#include <iostream>
using namespace std;
#include "SDLInclude.h"

#include "Rect.h"

#include "Texture.h"
#include "Renderer.h"

#include "ShowcaseGame.h"
#include "SDLFramework.h"

int main(int ArgC, char* ArgV[])
{
	SDLFramework* _pFramework = new SDLFramework();
	_pFramework->Init();

	_pFramework->Run(new ShowcaseGame());

	return 0;
}