#include "ShowcaseGame.h"
#include <random>

void ShowcaseGame::Init(Renderer* p_pRenderer)
{

	m_pTestTexture = new Texture("TestTexture.bmp", p_pRenderer);
}

void ShowcaseGame::Draw(Renderer* p_pRenderer)
{
	for (int i = 0; i < 500000; i++)
	{
		int x = rand() % 800;
		int y = rand() % 600;

		//SDL_RenderCopy(_pRenderer->GetRenderer(), _pTexture->GetTexture(), &Rect(0, 0, 400, 400), &Rect(x - 10, y-10, 20, 20));
		p_pRenderer->DrawTexture(m_pTestTexture, Rect(x - 10, y - 10, 20, 20));


		// Level Background zeichnen
		// Level Zeichnen
		// Character zeichnen
		// Interface zeichnen
	}
}