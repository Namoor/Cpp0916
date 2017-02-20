#include "Level.h"


void Level::Init(Renderer* p_pRenderer, b2World* p_pPhysicsSpace)
{
	m_pTextureAtlas = new Texture("Tileset.png", p_pRenderer);

	m_Sections[0] = new LevelSection();
	m_Sections[0]->Init(p_pRenderer, p_pPhysicsSpace, m_pTextureAtlas, "Level0110.bmp", 0,0);
	m_Sections[1] = new LevelSection();
	m_Sections[1]->Init(p_pRenderer, p_pPhysicsSpace, m_pTextureAtlas, "Level1001.bmp", 32, 0);
	m_Sections[2] = new LevelSection();
	m_Sections[2]->Init(p_pRenderer, p_pPhysicsSpace, m_pTextureAtlas, "Level0101.bmp" , 64, 0);

	m_Sections[3] = new LevelSection();
	m_Sections[3]->Init(p_pRenderer, p_pPhysicsSpace, m_pTextureAtlas, "Level0011.bmp" , 0, 32);
	m_Sections[4] = new LevelSection();
	m_Sections[4]->Init(p_pRenderer, p_pPhysicsSpace, m_pTextureAtlas, "Level1111.bmp", 32,32);
	m_Sections[5] = new LevelSection();
	m_Sections[5]->Init(p_pRenderer, p_pPhysicsSpace, m_pTextureAtlas, "Level1101.bmp", 64,32);

	m_Sections[6] = new LevelSection();
	m_Sections[6]->Init(p_pRenderer, p_pPhysicsSpace, m_pTextureAtlas, "Level0110.bmp", 0 ,64);
	m_Sections[7] = new LevelSection();
	m_Sections[7]->Init(p_pRenderer, p_pPhysicsSpace, m_pTextureAtlas, "Level1110.bmp", 32,64);
	m_Sections[8] = new LevelSection();
	m_Sections[8]->Init(p_pRenderer, p_pPhysicsSpace, m_pTextureAtlas, "Level1100.bmp", 64,64);
}

void Level::Update(float DeltaTime)
{
	m_Sections[0]->Update(DeltaTime);
	m_Sections[1]->Update(DeltaTime);
	m_Sections[2]->Update(DeltaTime);
	m_Sections[3]->Update(DeltaTime);
	m_Sections[4]->Update(DeltaTime);
	m_Sections[5]->Update(DeltaTime);
	m_Sections[6]->Update(DeltaTime);
	m_Sections[7]->Update(DeltaTime);
	m_Sections[8]->Update(DeltaTime);
}

void Level::Draw(Renderer* p_pRenderer, b2Vec2 CameraPosition)
{
	m_Sections[0]->Draw(p_pRenderer, CameraPosition);
	m_Sections[1]->Draw(p_pRenderer, CameraPosition);
	m_Sections[2]->Draw(p_pRenderer, CameraPosition);
	m_Sections[3]->Draw(p_pRenderer, CameraPosition);
	m_Sections[4]->Draw(p_pRenderer, CameraPosition);
	m_Sections[5]->Draw(p_pRenderer, CameraPosition);
	m_Sections[6]->Draw(p_pRenderer, CameraPosition);
	m_Sections[7]->Draw(p_pRenderer, CameraPosition);
	m_Sections[8]->Draw(p_pRenderer, CameraPosition);
}