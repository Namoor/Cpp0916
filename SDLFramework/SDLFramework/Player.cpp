#include "Player.h"
#include "Input.h"

Player::Player(Renderer* p_pRenderer)
{
	X = 100;
	Y = 100;
	m_pMarioTexture = new SpriteSheetAnimation("marioAnim.png", p_pRenderer);

	m_Idle = new AnimationClip(6, 2, 3);
	m_Walking = new AnimationClip(5, 3, 4);

	m_pMarioTexture->PlayAnimation(m_Walking);

}

void Player::Draw(Renderer* p_pRenderer)
{
	m_pMarioTexture->Draw(p_pRenderer, GetCollisionRect());
}

void Player::Update(float p_DeltaTime)
{

	m_pMarioTexture->PlayAnimation(m_Idle);

	if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_W))
	{
		Y -= p_DeltaTime * 150;
		m_pMarioTexture->PlayAnimation(m_Walking);
	}
	if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_S))
	{
		Y += p_DeltaTime * 150;
		m_pMarioTexture->PlayAnimation(m_Walking);
	}
	if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_A))
	{
		X -= p_DeltaTime * 150;
		m_pMarioTexture->PlayAnimation(m_Walking);
	}
	if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_D))
	{
		X += p_DeltaTime * 150;
		m_pMarioTexture->PlayAnimation(m_Walking);
	}


	m_pMarioTexture->Update(p_DeltaTime);

	int MaxX = 800 - GetCollisionRect().w;
	int MaxY = 600 - GetCollisionRect().h;

	if (X < 0)
		X = 0;
	if (Y < 0)
		Y = 0;
	if (X > MaxX)
		X = MaxX;
	if (Y > MaxY)
		Y = MaxY;
}


Rect Player::GetCollisionRect()
{
	return Rect(X, Y, 80, 80);
}
