#include "Fireball.h"
#include <random>

Fireball::Fireball(Renderer* p_pRenderer)
{
	Position.X = rand() % 800 - 800;
	Position.Y = -600 - 0.75f * Position.X; // rand() % 600 - 600;

	Direction.X = 100;
	Direction.Y = 100;

	m_pFireballTexture = new Texture("Fireball.png", p_pRenderer);
}


Fireball::~Fireball()
{
	if (m_pFireballTexture != nullptr)
	{
		delete m_pFireballTexture;
		m_pFireballTexture = nullptr;
	}
}

void Fireball::Update(float DeltaTime)
{
	Position.X += Direction.X * DeltaTime;
	Position.Y += Direction.Y * DeltaTime;
}

void Fireball::Render(Renderer* p_pRenderer)
{
	p_pRenderer->DrawTexture(m_pFireballTexture, Rect(Position.X, Position.Y, 30, 30));
}


Rect Fireball::GetCollisionRect()
{
	return Rect(Position.X, Position.Y, 30, 30);
}