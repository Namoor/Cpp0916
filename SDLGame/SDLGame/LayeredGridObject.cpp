#include "LayeredGridObject.h"

#include <Box2D\Box2D.h>

LayeredGridObject::LayeredGridObject(Texture* p_pTexture, b2World* p_pPhysicsSpace, int TileX, int TileY, int PosX, int PosY, int CollisionLayer)
	: GridObject(p_pTexture, p_pPhysicsSpace, TileX, TileY, PosX, PosY, false)
{
	Rect Destination(PosX * 64, PosY * 64, 64, 64);

	b2BodyDef _Def;
	_Def.position.Set((Destination.x + Destination.w / 2.0f) / 64.0f, (Destination.y + Destination.h / 2.0f) / 64.0f);
	_Object = p_pPhysicsSpace->CreateBody(&_Def);


	b2PolygonShape _Shape;
	_Shape.SetAsBox(Destination.w * 0.5f / 64.0f, Destination.h * 0.5f / 64.0f);

	b2FixtureDef _Fixture;
	_Fixture.shape = &_Shape;
	_Fixture.density = 10;
	_Fixture.filter.categoryBits = CollisionLayer;
	


	_Object->CreateFixture(&_Fixture);
}