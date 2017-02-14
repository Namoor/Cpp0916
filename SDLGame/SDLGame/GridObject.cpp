#include "GridObject.h"

GridObject::GridObject(Texture* p_pTexture, b2World* p_pPhysicsSpace, int TileX, int TileY, int PosX, int PosY, bool Collider)
	: BackgroundObject(p_pTexture, p_pPhysicsSpace, Rect(2 + 64 * TileX, 2 + 64 * TileY, 63, 63), Rect(PosX * 64, PosY * 64, 64, 64), Collider)
{

}