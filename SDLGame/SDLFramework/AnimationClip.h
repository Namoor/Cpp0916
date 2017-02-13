#pragma once


class AnimationClip
{
public:
	AnimationClip(int p_XStart, int p_YStart, int p_FrameCount);

	int XStart;
	int YStart;

	int FrameCount;
};