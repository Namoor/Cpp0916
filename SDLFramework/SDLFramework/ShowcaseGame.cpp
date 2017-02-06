#include "ShowcaseGame.h"
#include <random>

#include "Input.h"

void ShowcaseGame::Init(Renderer* p_pRenderer)
{


	m_pPlayer = new Player(p_pRenderer);

	m_pFireballTexture = new Texture("Fireball.png", p_pRenderer);
	m_pLifeTexture = new Texture("hearth.png", p_pRenderer);
	LifeCount = 3;

	m_TimeToNextFireball = 1.0f;

	m_pRenderer = p_pRenderer;
}

void ShowcaseGame::Update(float p_DeltaTime)
{
	m_pPlayer->Update(p_DeltaTime);

	if (m_TimeToNextFireball < 0.0f)
	{
		// Fireball Spawnen
		m_Fireballs.push_back(new Fireball(m_pRenderer));

		m_TimeToNextFireball += 0.1f;
	}
	m_TimeToNextFireball -= p_DeltaTime;

	bool _ResetGame = false;

	std::list<Fireball*> _ToDelete;
	Rect Coll2 = m_pPlayer->GetCollisionRect();

	for each(Fireball* _Fireball in m_Fireballs)
	{
		_Fireball->Update(p_DeltaTime);

		//Check collision with other Fireball
		Rect Coll1 = _Fireball->GetCollisionRect();

		if (Coll1.x > 800 || Coll1.y > 600)
		{
			_ToDelete.push_back(_Fireball);
			continue;
		}

		// Collision Axis X
		if (Coll1.x + Coll1.w > Coll2.x && Coll1.x < Coll2.x + Coll2.w)
		{
			if (Coll1.y + Coll1.h > Coll2.y && Coll1.y < Coll2.y + Coll2.h)
			{
				LifeCount--;
				_ToDelete.push_back(_Fireball);
			}
		}

	}

	for each(Fireball* _Fireball in _ToDelete)
	{
		m_Fireballs.remove(_Fireball);
		delete _Fireball;
	}


	if (LifeCount <= 0)
	{
		ResetGame();
	}

}

void ShowcaseGame::ResetGame()
{
	LifeCount = 3;


	for each(Fireball* _Fireball in m_Fireballs)
	{
		delete _Fireball;
	}

	m_Fireballs.clear();
}

void ShowcaseGame::Draw(Renderer* p_pRenderer)
{
	// Character zeichnen
	m_pPlayer->Draw(p_pRenderer);

	for (int x = 0; x < LifeCount; x++)
	{
		p_pRenderer->DrawTexture(m_pLifeTexture, Rect(x * 40, 0, 40, 40));
	}

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