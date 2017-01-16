#include "Rect.h"

Rect::Rect(int x, int y, int h, int w)
{
	this->x = x;
	this->y = y;
	this->h = h;
	this->w = w;
}

Rect::Rect()
{
	this->x = 0;
	this->y = 0;
	this->h = 0;
	this->w = 0;
}