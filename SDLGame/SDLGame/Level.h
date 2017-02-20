#pragma once
#include "Renderer.h"
#include <Box2D\Box2D.h>
#include "LevelSection.h"

class Level
{
public:
	void Init(Renderer* p_pRenderer, b2World* p_pPhysicsSpace);

	void Update(float DeltaTime);

	void Draw(Renderer* p_pRenderer, b2Vec2 CameraPosition);

private:
	LevelSection* m_Sections[9];
	

	Texture* m_pTextureAtlas;
};