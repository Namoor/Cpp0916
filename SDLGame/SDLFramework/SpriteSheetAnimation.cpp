#include "SpriteSheetAnimation.h"
#include "Texture.h"


SpriteSheetAnimation::SpriteSheetAnimation(char* Filename, Renderer* p_pRenderer)
{
	m_pTexture = new Texture(Filename, p_pRenderer);

	CurrentAnimationFrame = 0;
	TimeTillNextAnimationFrame = 0;
}


void SpriteSheetAnimation::Update(float p_DeltaTime)
{
	if (CurrentAnimation != nullptr)
	{
		TimeTillNextAnimationFrame -= p_DeltaTime;
		if (TimeTillNextAnimationFrame <= 0)
		{
			TimeTillNextAnimationFrame += 0.2f;
			CurrentAnimationFrame++;
		}
	}
	if (CurrentAnimationFrame >= CurrentAnimation->FrameCount)
		CurrentAnimationFrame = 0;
}

void SpriteSheetAnimation::PlayAnimation(AnimationClip* p_pAnimation)
{
	CurrentAnimation = p_pAnimation;
}

void SpriteSheetAnimation::Draw(Renderer* p_Renderer, Rect p_Destination)
{
	if (CurrentAnimation != nullptr)
		p_Renderer->DrawTexture(m_pTexture, Rect((CurrentAnimation->XStart + CurrentAnimationFrame) * 40, 40 * CurrentAnimation->YStart, 39, 40), p_Destination);
}