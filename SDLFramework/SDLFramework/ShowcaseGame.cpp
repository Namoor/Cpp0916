#include "ShowcaseGame.h"
#include <random>

#include "Input.h"

void ShowcaseGame::Init(Renderer* p_pRenderer)
{
	X = 100;
	Y = 100;
	m_pTestTexture = new Texture("TestTexture.bmp", p_pRenderer);
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
	p_pRenderer->DrawTexture(m_pTestTexture, Rect(X - 10, Y - 10, 20, 20));
}