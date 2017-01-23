#pragma once

#include "Renderer.h"
#include "Texture.h"
#include "IGame.h"

class ShowcaseGame : public IGame
{
public:
	void Init(Renderer* p_pRenderer) override;
	void Draw(Renderer* p_pRenderer) override;
	void Update(float p_DeltaTime) override;

	float X;
	float Y;

private:
	Texture* m_pTestTexture;
};