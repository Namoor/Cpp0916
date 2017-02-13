#pragma once
#include "SDLInclude.h"
#include "Vector2.h"

class Input
{
public:

	static bool IsKeyDown(SDL_Scancode p_Key);
	static bool IsKeyPressed(SDL_Scancode p_Key);
	static bool IsKeyReleased(SDL_Scancode p_Key);



	static bool IsMouseDown(int Button);
	static bool IsMousePressed(int Button);
	static bool IsMouseReleased(int Button);
	static Vector2 GetMousePosition();



	void ParseEvent(SDL_Event p_Event);
	void FlushKeys();

private:
	static bool KeyIsDown[256];
	static bool KeyWasDown[256];

	static bool MouseIsDown[3];
	static bool MouseWasDown[3];

	static int MousePosX;
	static int MousePosY;
};
