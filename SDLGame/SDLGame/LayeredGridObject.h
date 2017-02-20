#pragma once

#include "GridObject.h"


class LayeredGridObject : public GridObject
{
public:
	LayeredGridObject(Texture* p_pTexture, b2World* p_pPhysicsSpace, int TileX, int TileY, int PosX, int PosY, int CollisionLayer);

};