#include "BackgroundObject.h"


BackgroundObject::BackgroundObject(Texture* p_pTexture, b2World* p_pPhysicsSpace, Rect SourceRect, Rect DestinationRect, bool Collider)
{
	m_pTexture = p_pTexture;
	Source = SourceRect;
	Destination = DestinationRect;

	if (Collider)
	{
		b2BodyDef _Def;
		_Def.position.Set((Destination.x + Destination.w / 2.0f) / 64.0f, (Destination.y + Destination.h / 2.0f) / 64.0f);
		_Object = p_pPhysicsSpace->CreateBody(&_Def);


		b2PolygonShape _Shape;
		_Shape.SetAsBox(Destination.w * 0.5f / 64.0f, Destination.h * 0.5f / 64.0f);

		b2FixtureDef _Fixture;
		_Fixture.shape = &_Shape;
		_Fixture.density = 10;
		
		_Object->CreateFixture(&_Fixture);
	}
	else
	{
		_Object = nullptr;
	}
}


BackgroundObject::~BackgroundObject()
{
	if (_Object != nullptr)
	{
		_Object->GetWorld()->DestroyBody(_Object);
	}
}


void BackgroundObject::Draw(Renderer* p_pRenderer, b2Vec2 p_Camera)
{
	p_pRenderer->DrawTexture(m_pTexture, Source, Rect(Destination.x - p_Camera.x, Destination.y - p_Camera.y, Destination.w, Destination.h));
}