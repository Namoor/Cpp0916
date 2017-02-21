#include "SDLGame.h"

#include "Texture.h"
#include "Input.h"


void SDLGame::Init(Renderer* p_pRenderer)
{
	WaterOverlapCount = 0;

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
		b2Vec2 ShapePoints[8];
		ShapePoints[0] = b2Vec2(0.4f, 0.5f);
		ShapePoints[1] = b2Vec2(0.45f, 0.1f);
		ShapePoints[2] = b2Vec2(0.45f, -0.1f);
		ShapePoints[3] = b2Vec2(0.4f, -0.5f);
		ShapePoints[4] = b2Vec2(-0.4f, -0.5f);
		ShapePoints[5] = b2Vec2(-0.45f, -0.1f);
		ShapePoints[6] = b2Vec2(-0.45f, 0.1f);
		ShapePoints[7] = b2Vec2(-0.4f, 0.5f);


		_Shape.Set(ShapePoints, 8);

		b2FixtureDef _Fixture;
		_Fixture.shape = &_Shape;
		_Fixture.density = 10;
		_Fixture.friction = 0;
		_Fixture.filter.maskBits = 1;

		TestBody->CreateFixture(&_Fixture);


		b2PolygonShape _Trigger;
		_Trigger.SetAsBox(0.4f, 0.4f);

		b2FixtureDef _TriggerFixture;
		_TriggerFixture.isSensor = true;
		_TriggerFixture.density = 0;
		_TriggerFixture.shape = &_Trigger;
		_TriggerFixture.filter.maskBits = 2;
		TestBody->CreateFixture(&_TriggerFixture);
	}

	m_pPhysicsSpace->SetContactListener(this);


	m_pTestSection = new Level();
	m_pTestSection->Init(p_pRenderer, m_pPhysicsSpace);

	//{
	//	b2BodyDef _Def;
	//	_Def.position.Set(-5, 8);
	//	TestLevel = m_pPhysicsSpace->CreateBody(&_Def);
	//
	//
	//	b2PolygonShape _Shape;
	//	_Shape.SetAsBox(8.0f, 0.5f);
	//
	//	b2FixtureDef _Fixture;
	//	_Fixture.shape = &_Shape;
	//	_Fixture.density = 10;
	//
	//	TestLevel->CreateFixture(&_Fixture);
	//}
	//
	//{
	//	b2BodyDef _Def;
	//	_Def.position.Set(14, 8);
	//	TestLevel2 = m_pPhysicsSpace->CreateBody(&_Def);
	//
	//
	//	b2PolygonShape _Shape;
	//	_Shape.SetAsBox(8.0f, 0.5f);
	//
	//	b2FixtureDef _Fixture;
	//	_Fixture.shape = &_Shape;
	//	_Fixture.density = 10;
	//
	//	TestLevel2->CreateFixture(&_Fixture);
	//}

}

void SDLGame::BeginContact(b2Contact* contact)
{
	b2Fixture* _FixtureA = contact->GetFixtureA();
	b2Fixture* _FixtureB = contact->GetFixtureB();

	if (_FixtureA->IsSensor() || _FixtureB->IsSensor())
	{
		WaterOverlapCount++;
	}
}

void SDLGame::EndContact(b2Contact* contact)
{
	b2Fixture* _FixtureA = contact->GetFixtureA();
	b2Fixture* _FixtureB = contact->GetFixtureB();

	if (_FixtureA->IsSensor() || _FixtureB->IsSensor())
	{
		WaterOverlapCount--;
	}
}

void SDLGame::Update(float p_DeltaTime)
{
	if (p_DeltaTime > 0.1f)
		p_DeltaTime = 0.1f;

	m_pPhysicsSpace->Step(p_DeltaTime, 1, 1);

	b2Vec2 _Pos = TestBody->GetPosition();
	b2Vec2 _Vel = TestBody->GetLinearVelocity();
	_Vel.x = 0;

	if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_G))
	{
		if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_W))
		{
			_Vel.y = -10.0f;
		}
		if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_S))
		{
			_Vel.y = 10.0f;
		}

		

		if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_D))
		{
			_Vel.x = 15;
		}

		if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_A))
		{
			_Vel.x = -15;
		}

	}
	else
	{


		if (WaterOverlapCount > 0)
		{
			_Vel.y *= 0.9f;
			if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_W))
			{
				_Vel.y -= 0.5f;
			}
		}

		if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_D))
		{
			_Vel.x = 3;
		}

		if (Input::IsKeyDown(SDL_Scancode::SDL_SCANCODE_A))
		{
			_Vel.x = -3;
		}

		if (Input::IsKeyPressed(SDL_Scancode::SDL_SCANCODE_SPACE) && _Vel.y > -0.1f &&_Vel.y < 0.1f)
		{
			_Vel.y = -8;
		}

	}

	TestBody->SetLinearVelocity(_Vel);

	m_pTestSection->Update(p_DeltaTime, TestBody->GetPosition().x , TestBody->GetPosition().y);
}

void SDLGame::Draw(Renderer* p_pRenderer)
{
	b2Vec2 _Pos = TestBody->GetPosition();
	m_pTestSection->Draw(p_pRenderer, b2Vec2(_Pos.x * 64 - 400, _Pos.y * 64 - 400));


	p_pRenderer->DrawTexture(m_pTestTexture, Rect(_Pos.x * 64 - 32 - (_Pos.x * 64 - 400), _Pos.y * 64 - 32 - (_Pos.y * 64 - 400), 64, 64));


	//_Pos = TestLevel->GetPosition();
	//p_pRenderer->DrawTexture(m_pTestTexture, Rect(_Pos.x * 64 - 512, _Pos.y * 64 - 32, 64 * 16, 64));
	//
	//_Pos = TestLevel2->GetPosition();
	//p_pRenderer->DrawTexture(m_pTestTexture, Rect(_Pos.x * 64 - 512, _Pos.y * 64 - 32, 64 * 16, 64));
}

