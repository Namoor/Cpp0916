#pragma once
#include "SDLInclude.h"
#include "Vector2.h"
#include "Renderer.h"
#include "Texture.h"
#include "Rect.h"

class Fireball
{
private:
	Vector2 Position;
	Vector2 Direction;

	Texture* m_pFireballTexture;

public:
	Fireball(Renderer* p_pRenderer);

	void Update(float DeltaTime);
	void Render(Renderer* p_pRenderer);

	Rect GetCollisionRect();

};