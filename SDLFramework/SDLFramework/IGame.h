#pragma once
#include "Renderer.h"

class IGame
{
public:
	virtual void Init(Renderer* p_pRenderer) = 0;
	virtual void Draw(Renderer* p_pRenderer) = 0;
};