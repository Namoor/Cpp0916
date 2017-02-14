#pragma once

#include "IGame.h"

#include <Box2D\Box2D.h>

#include "LevelSection.h"

class SDLGame : public IGame
{
	void Init(Renderer* p_pRenderer) override;
	void Update(float p_DeltaTime) override;
	void Draw(Renderer* p_pRenderer) override;

private:
	b2World* m_pPhysicsSpace;

	b2Body* TestBody;
	b2Body* TestLevel;
	b2Body* TestLevel2;

	LevelSection* m_pTestSection;

	Texture* m_pTestTexture;
};