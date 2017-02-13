#include "SDLGame.h"

#include "Texture.h"


void SDLGame::Init(Renderer* p_pRenderer)
{
	m_pTestTexture = new Texture("Test.png", p_pRenderer);

	b2Vec2 gravity(0, 9.81f);


	m_pPhysicsSpace = new b2World(gravity);

	{
		b2BodyDef _Def;
		_Def.position.Set(2, 0);
		_Def.fixedRotation = true;
		_Def.type = b2BodyType::b2_dynamicBody;

		TestBody = m_pPhysicsSpace->CreateBody(&_Def);

		b2PolygonShape _Shape;
		_Shape.SetAsBox(0.5f, 0.5f);

		b2FixtureDef _Fixture;
		_Fixture.shape = &_Shape;
		_Fixture.density = 10;
		TestBody->CreateFixture(&_Fixture);
	}

	{
		b2BodyDef _Def;
		_Def.position.Set(-2.4f, 8);
		TestLevel = m_pPhysicsSpace->CreateBody(&_Def);


		b2PolygonShape _Shape;
		_Shape.SetAsBox(4.0f, 0.5f);

		b2FixtureDef _Fixture;
		_Fixture.shape = &_Shape;
		_Fixture.density = 10;
		
		TestLevel->CreateFixture(&_Fixture);
	}

}

void SDLGame::Update(float p_DeltaTime)
{
	if (p_DeltaTime > 0.1f)
		p_DeltaTime = 0.1f;

	m_pPhysicsSpace->Step(p_DeltaTime, 1, 1);

	b2Vec2 _Pos = TestBody->GetPosition();
	b2Vec2 _Vel = TestBody->GetLinearVelocity();

	int asd = 0;
}

void SDLGame::Draw(Renderer* p_pRenderer)
{

	b2Vec2 _Pos = TestBody->GetPosition();

	p_pRenderer->DrawTexture(m_pTestTexture, Rect(_Pos.x * 64 - 32, _Pos.y * 64 - 32, 64, 64));


	_Pos = TestLevel->GetPosition();
	p_pRenderer->DrawTexture(m_pTestTexture, Rect(_Pos.x * 64 - 256, _Pos.y * 64 - 32, 64* 8, 64 ));
}

