#pragma once
#include "Renderer.h"
#include "Texture.h"
#include <Box2D\Box2D.h>
#include <list>
#include "BackgroundObject.h"

class LevelSection
{
public:
	void Init(Renderer* p_pRenderer, b2World* p_pPhysicsSpace);

	void Update(float DeltaTime);

	void Draw(Renderer* p_pRenderer, b2Vec2 CameraPosition);

private:
	Texture* m_pTextureAtlas;

	std::list<BackgroundObject*> m_Objects;
};