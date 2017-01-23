#include "Input.h"


bool Input::KeyIsDown[];
bool Input::KeyWasDown[];

bool Input::MouseIsDown[];
bool Input::MouseWasDown[];

int Input::MousePosX;
int Input::MousePosY;

bool Input::IsKeyDown(SDL_Scancode p_Key)
{
	return KeyIsDown[p_Key];
}

bool Input::IsKeyPressed(SDL_Scancode p_Key)
{
	return KeyIsDown[p_Key] && !KeyWasDown[p_Key];
}

bool Input::IsKeyReleased(SDL_Scancode p_Key)
{
	return !KeyIsDown[p_Key] && KeyWasDown[p_Key];
}


bool Input::IsMouseDown(int Button)
{
	return MouseIsDown[Button];
}

bool Input::IsMousePressed(int Button)
{
	return MouseIsDown[Button] && !MouseWasDown[Button];
}

bool Input::IsMouseReleased(int Button)
{
	return !MouseIsDown[Button] && MouseWasDown[Button];
}


Vector2 Input::GetMousePosition()
{
	return Vector2(MousePosX, MousePosY);
}

void Input::FlushKeys()
{
	for (int x = 0; x < 256; x++)
	{
		KeyWasDown[x] = KeyIsDown[x];
	}

	for (int x = 0; x < 3; x++)
	{
		MouseWasDown[x] = MouseIsDown[x];
	}

	Uint32 _MouseState = SDL_GetMouseState(&MousePosX, &MousePosY);

	if ((_MouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) > 0)
	{
		MouseIsDown[0] = true;
	}
	else
	{
		MouseIsDown[0] = false;
	}
	if ((_MouseState & SDL_BUTTON(SDL_BUTTON_MIDDLE)) > 0)
	{
		MouseIsDown[1] = true;
	}
	else
	{
		MouseIsDown[1] = false;
	}
	if ((_MouseState & SDL_BUTTON(SDL_BUTTON_RIGHT)) > 0)
	{
		MouseIsDown[2] = true;
	}
	else
	{
		MouseIsDown[2] = false;
	}

}



void Input::ParseEvent(SDL_Event p_Event)
{
	if(p_Event.type == SDL_EventType::SDL_KEYDOWN)
	{
		KeyIsDown[p_Event.key.keysym.scancode] = true;
	}
	else
	{
		KeyIsDown[p_Event.key.keysym.scancode] = false;
	}
}