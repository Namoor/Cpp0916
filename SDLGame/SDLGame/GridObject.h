#pragma once

#include "BackgroundObject.h"

class GridObject : public BackgroundObject
{
public:
	GridObject(Texture* p_pTexture, b2World* p_pPhysicsSpace, int TileX, int TileY, int PosX, int PosY, bool Collider);
};
