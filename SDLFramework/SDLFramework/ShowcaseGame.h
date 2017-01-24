#pragma once

#include "Renderer.h"
#include "Texture.h"
#include "IGame.h"
#include "Vector2.h"
#include <list>
#include "Fireball.h"

using namespace std;

class ShowcaseGame : public IGame
{
public:
	void Init(Renderer* p_pRenderer) override;
	void Draw(Renderer* p_pRenderer) override;
	void Update(float p_DeltaTime) override;

	float X;
	float Y;

	list<Fireball*> m_Fireballs;

	float m_TimeToNextFireball;

private:
	Texture* m_pMarioTexture;
	Texture* m_pFireballTexture;
	Renderer* m_pRenderer;
};