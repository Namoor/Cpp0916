#pragma once
#include "Renderer.h"
#include "Texture.h"
#include <Box2D\Box2D.h>
#include <list>
#include "BackgroundObject.h"

class LevelSection
{
public:
	void Init(Renderer* p_pRenderer, b2World* p_pPhysicsSpace, Texture* p_pTextureAtlas, char* LevelName, int XSection, int YSection, int EntranceMask);

	void Update(float DeltaTime);

	void Draw(Renderer* p_pRenderer, b2Vec2 CameraPosition);

	~LevelSection();

private:
	Texture* m_pTextureAtlas;

	std::list<BackgroundObject*> m_Objects;
	int m_XSection;
	int m_YSection;

public:
	int EntranceMask;
};