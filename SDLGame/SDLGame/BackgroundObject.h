#pragma once
#include "Renderer.h"
#include "Texture.h"
#include <Box2D\Box2D.h>

class BackgroundObject
{
public:
	BackgroundObject(Texture* p_pTexture, b2World* p_pPhysicsSpace, Rect SourceRect, Rect Destination, bool Collider);

	void Draw(Renderer* p_pRenderer, b2Vec2 p_Camera);

	~BackgroundObject();

private:
	Texture* m_pTexture;
	Rect Source;
	Rect Destination;
protected:
	b2Body* _Object;
};