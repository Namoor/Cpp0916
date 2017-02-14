#pragma once
#include "Renderer.h"
#include <Box2D\Box2D.h>

class BackgroundObject
{
public:
	BackgroundObject(Texture* p_pTexture, b2World* p_pPhysicsSpace, Rect SourceRect, Rect Destination, bool Collider);

	void Draw(Renderer* p_pRenderer, b2Vec2 p_Camera);

private:
	Texture* m_pTexture;
	Rect Source;
	Rect Destination;
};