#include "ShowcaseGame.h"
#include <random>

#include "Input.h"

void ShowcaseGame::Init(Renderer* p_pRenderer)
{
	X = 100;
	Y = 100;
	m_pMarioTexture = new Texture("Mario.png", p_pRenderer);
	m_pFireballTexture = new Texture("Fireball.png", p_pRenderer);
}

void ShowcaseGame::Update(float p_DeltaTime) 
{
	if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_W))
		Y-= p_DeltaTime * 100;
	if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_S))
		Y+= p_DeltaTime * 100;
	if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_A))
		X-= p_DeltaTime * 100;
	if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_D))
		X+= p_DeltaTime * 100;
}

void ShowcaseGame::Draw(Renderer* p_pRenderer)
{
	p_pRenderer->DrawTexture(m_pMarioTexture, Rect(X - 10, Y - 10, 40, 60));
	//p_pRenderer->DrawTexture(m_pFireballTexture, Rect(X - 10, Y - 10, 300, 261));

}