#pragma once

#include "IGame.h"

#include <Box2D\Box2D.h>

#include "Level.h"

class SDLGame : public IGame, b2ContactListener
{
	void Init(Renderer* p_pRenderer) override;
	void Update(float p_DeltaTime) override;
	void Draw(Renderer* p_pRenderer) override;

public:
	virtual void BeginContact(b2Contact* contact) override;
	virtual void EndContact(b2Contact* contact) override;


private:
	b2World* m_pPhysicsSpace;

	b2Body* TestBody;
	b2Body* TestLevel;
	b2Body* TestLevel2;

	Level* m_pTestSection;

	int WaterOverlapCount;

	Texture* m_pTestTexture;
};