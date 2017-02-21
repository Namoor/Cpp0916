#pragma once
#include "Renderer.h"
#include <Box2D\Box2D.h>
#include "LevelSection.h"



class Level
{
public:
	void Init(Renderer* p_pRenderer, b2World* p_pPhysicsSpace);

	void Update(float DeltaTime, int PlayerX, int PlayerY);

	void Draw(Renderer* p_pRenderer, b2Vec2 CameraPosition);

	void GenerateCell(int X, int Y);

private:
	LevelSection* m_Sections[9];

	int CurrentXOffset;
	int CurrentYOffset;
	
	Renderer* m_pRenderer;
	b2World* m_pPhysicsSpace;
	Texture* m_pTextureAtlas;
};