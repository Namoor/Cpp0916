#include "Level.h"


void Level::Init(Renderer* p_pRenderer, b2World* p_pPhysicsSpace)
{

	srand(0);

	m_pRenderer = p_pRenderer;
	m_pPhysicsSpace = p_pPhysicsSpace;

	m_pTextureAtlas = new Texture("Tileset.png", p_pRenderer);

	GenerateCell(0, 0);
	GenerateCell(1, 0);
	GenerateCell(2, 0);

	GenerateCell(0, 1);
	GenerateCell(1, 1);
	GenerateCell(2, 1);

	GenerateCell(0, 2);
	GenerateCell(1, 2);
	GenerateCell(2, 2);


	CurrentXOffset = 0;
	CurrentYOffset = 0;
}

void Level::Update(float DeltaTime, int PlayerX, int PlayerY)
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


	int RelativeX = PlayerX - CurrentXOffset;
	int RelativeY = PlayerY - CurrentYOffset;

	if (RelativeX > 64)
	{
		delete m_Sections[0];
		m_Sections[0] = m_Sections[1];
		m_Sections[1] = m_Sections[2];
		m_Sections[2] = nullptr;

		delete m_Sections[3];
		m_Sections[3] = m_Sections[4];
		m_Sections[4] = m_Sections[5];
		m_Sections[5] = nullptr;

		delete m_Sections[6];
		m_Sections[6] = m_Sections[7];
		m_Sections[7] = m_Sections[8];
		m_Sections[8] = nullptr;

		CurrentXOffset += 32;

		GenerateCell(2, 0);
		GenerateCell(2, 1);
		GenerateCell(2, 2);


	}
	if (RelativeX < 32)
	{
		delete m_Sections[2];
		m_Sections[2] = m_Sections[1];
		m_Sections[1] = m_Sections[0];
		m_Sections[0] = nullptr;

		delete m_Sections[5];
		m_Sections[5] = m_Sections[4];
		m_Sections[4] = m_Sections[3];
		m_Sections[3] = nullptr;

		delete m_Sections[8];
		m_Sections[8] = m_Sections[7];
		m_Sections[7] = m_Sections[6];
		m_Sections[6] = nullptr;

		CurrentXOffset -= 32;

		GenerateCell(0, 0);
		GenerateCell(0, 1);
		GenerateCell(0, 2);


	}


	// Y
	if (RelativeY > 64)
	{
		delete m_Sections[0];
		m_Sections[0] = m_Sections[3];
		m_Sections[3] = m_Sections[6];
		m_Sections[6] = nullptr;

		delete m_Sections[1];
		m_Sections[1] = m_Sections[4];
		m_Sections[4] = m_Sections[7];
		m_Sections[7] = nullptr;

		delete m_Sections[2];
		m_Sections[2] = m_Sections[5];
		m_Sections[5] = m_Sections[8];
		m_Sections[8] = nullptr;

		CurrentYOffset += 32;

		GenerateCell(0, 2);
		GenerateCell(1, 2);
		GenerateCell(2, 2);


	}
	if (RelativeY < 32)
	{
		delete m_Sections[6];
		m_Sections[6] = m_Sections[3];
		m_Sections[3] = m_Sections[0];
		m_Sections[0] = nullptr;

		delete m_Sections[7];
		m_Sections[7] = m_Sections[4];
		m_Sections[4] = m_Sections[1];
		m_Sections[1] = nullptr;

		delete m_Sections[8];
		m_Sections[8] = m_Sections[5];
		m_Sections[5] = m_Sections[2];
		m_Sections[2] = nullptr;

		CurrentYOffset -= 32;

		GenerateCell(0, 0);
		GenerateCell(1, 0);
		GenerateCell(2, 0);


	}
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


void Level::GenerateCell(int X, int Y)
{
	bool EntranceTop;
	bool EntranceBot;
	bool EntranceLeft;
	bool EntranceRight;

	// Oben
	if (Y <= 0 || m_Sections[X + (Y - 1) * 3] == nullptr)
		EntranceTop = rand() % 100 < 70;
	else
		EntranceTop = (m_Sections[X + (Y - 1) * 3]->EntranceMask & 1) > 0;

	// Rechts
	if (X >= 2 || m_Sections[(X + 1) + (Y)* 3] == nullptr)
		EntranceRight = rand() % 100 < 70;
	else
		EntranceRight = (m_Sections[(X + 1) + (Y)* 3]->EntranceMask & 8) > 0;

	// Unten
	if (Y >= 2 || m_Sections[(X)+(Y + 1) * 3] == nullptr)
		EntranceBot = rand() % 100 < 70;
	else
		EntranceBot = (m_Sections[X + (Y + 1) * 3]->EntranceMask & 4) > 0;

	// Links
	if (X <= 0 || m_Sections[(X - 1) + (Y)* 3] == nullptr)
		EntranceLeft = rand() % 100 < 70;
	else
		EntranceLeft = (m_Sections[(X - 1) + (Y)* 3]->EntranceMask & 2) != 0;

	int Mask = 0;
	if (EntranceTop)
		Mask |= 4;
	if (EntranceBot)
		Mask |= 1;
	if (EntranceRight)
		Mask |= 2;
	if (EntranceLeft)
		Mask |= 8;

	m_Sections[X + Y * 3] = new LevelSection();
	m_Sections[X + Y * 3]->Init(m_pRenderer, m_pPhysicsSpace, m_pTextureAtlas, "Level1111.bmp", CurrentXOffset + X * 32, CurrentYOffset + Y * 32, Mask);


}