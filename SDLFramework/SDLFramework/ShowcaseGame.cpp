#include "ShowcaseGame.h"
#include <random>

#include "Input.h"

void ShowcaseGame::Init(Renderer* p_pRenderer)
{
	X = 100;
	Y = 100;
	m_pMarioTexture = new Texture("Mario.png", p_pRenderer);
	m_pFireballTexture = new Texture("Fireball.png", p_pRenderer);

	m_TimeToNextFireball = 1.0f;

	m_pRenderer = p_pRenderer;
}

void ShowcaseGame::Update(float p_DeltaTime)
{
	if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_W))
		Y -= p_DeltaTime * 150;
	if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_S))
		Y += p_DeltaTime * 150;
	if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_A))
		X -= p_DeltaTime * 150;
	if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_D))
		X += p_DeltaTime * 150;

	if (m_TimeToNextFireball < 0.0f)
	{
		// Fireball Spawnen
		m_Fireballs.push_back(new Fireball(m_pRenderer));

		m_TimeToNextFireball += 0.1f;
	}
	m_TimeToNextFireball -= p_DeltaTime;

	bool ResetGame = false;

	for each(Fireball* _Fireball in m_Fireballs)
	{
		_Fireball->Update(p_DeltaTime);

		//Check collision with other Fireball
		Rect Coll1 = _Fireball->GetCollisionRect();
		Rect Coll2(X, Y, 40, 60);

		// Collision Axis X
		if(Coll1.x + Coll1.w > Coll2.x && Coll1.x < Coll2.x + Coll2.w)
		{
			if (Coll1.y + Coll1.h > Coll2.y && Coll1.y < Coll2.y + Coll2.h)
			{
				ResetGame = true;
			}
		}

	}


}

void ShowcaseGame::Draw(Renderer* p_pRenderer)
{
	// Character zeichnen
	p_pRenderer->DrawTexture(m_pMarioTexture, Rect(X, Y, 40, 60));


	// Fireballs zeichnen
	for each(Fireball* _Fireball in m_Fireballs)
	{
		_Fireball->Render(p_pRenderer);
	}

	//for (auto _It = m_Fireballs.begin();_It != m_Fireballs.end();_It++)
	//{
	//	Vector2 _Vector = *_It;
	//	p_pRenderer->DrawTexture(m_pFireballTexture, Rect(_Vector.X - 10, _Vector.Y - 10, 30, 26));
	//}
}