#pragma once

#include "Renderer.h"
#include "Texture.h"
#include "SpriteSheetAnimation.h"

class Player
{
public:
	Player(Renderer* p_pRenderer);
	void Draw(Renderer* p_pRenderer);
	void Update(float p_DeltaTime);

	Rect GetCollisionRect();

private:
	SpriteSheetAnimation* m_pMarioTexture;
	AnimationClip* m_Idle;
	AnimationClip* m_Walking;

	float X;
	float Y;

	int CurrentAnimationFrame;
	float TimeTillNextAnimationFrame;


};