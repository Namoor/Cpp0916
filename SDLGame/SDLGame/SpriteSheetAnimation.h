#pragma once
#include "Renderer.h"
#include "AnimationClip.h"


class SpriteSheetAnimation
{
public:
	AnimationClip* CurrentAnimation;

	SpriteSheetAnimation(char* Filename, Renderer* p_pRenderer);

	void Update(float p_DeltaTime);

	void PlayAnimation(AnimationClip* p_pAnimation);

	void Draw(Renderer* p_Renderer, Rect p_Destination);

private:
	Texture* m_pTexture;
	int CurrentAnimationFrame;
	float TimeTillNextAnimationFrame;
};