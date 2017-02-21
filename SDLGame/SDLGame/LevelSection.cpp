#include "LevelSection.h"
#include "GridObject.h"
#include "LayeredGridObject.h"


LevelSection::~LevelSection()
{
	for (auto _It = m_Objects.begin(); _It != m_Objects.end(); _It++)
	{
		delete *_It;
	}
}

void LevelSection::Init(Renderer* p_pRenderer, b2World* p_pPhysicsSpace, Texture* p_pTextureAtlas, char* LevelNameold, int XSection, int YSection, int Mask)
{
	m_pTextureAtlas = p_pTextureAtlas;
	int i = 0;

	m_XSection = XSection;
	m_YSection = YSection;

	EntranceMask = Mask;

	//while (i++ < 32)
	//	m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 12, 1, i, 4, true));
	//m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 12, 1, 1, 4, true));
	//m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 12, 1, 2, 4, true));
	//m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 12, 1, 3, 4, true));
	//m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 12, 1, 4, 4, true));
	//m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 12, 1, 5, 4, true));
	//m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 12, 1, 6, 4, true));
	//m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 12, 1, 7, 4, true));
	//m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 12, 1, 8, 4, true));
	//m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 12, 1, 9, 4, true));

	//m_Objects.push_back(new BackgroundObject(m_pTextureAtlas, p_pPhysicsSpace, Rect(2 + 64 * 12, 2 + 64, 63, 63), Rect(128.1, 900, 64, 64), true));

	// 255 / 000 / 000 Stone
	// 000 / 255 / 255 Obsidian
	// 255 / 000 / 255 Pillar
	// 255 / 255 / 000 Dark Stone
	// 000 / 255 / 000 Dirt
	// 000 / 000 / 255 Water
	// 000 / 128 / 255 WaterWithStone
	// 255 / 255 / 255 Nothing

	int VariationCount[16];
	VariationCount[0] = 1;
	VariationCount[1] = 1;
	VariationCount[2] = 1;
	VariationCount[3] = 1;
	VariationCount[4] = 1;
	VariationCount[5] = 1;
	VariationCount[6] = 1;
	VariationCount[7] = 1;
	VariationCount[8] = 1;
	VariationCount[9] = 1;
	VariationCount[10] = 1;
	VariationCount[11] = 1;
	VariationCount[12] = 1;
	VariationCount[13] = 1;
	VariationCount[14] = 1;
	VariationCount[15] = 2;

	int Variation = rand() % VariationCount[Mask];
	
	char LevelName[16];
	LevelName[0] = 'L';
	LevelName[1] = 'e';
	LevelName[2] = 'v';
	LevelName[3] = 'e';
	LevelName[4] = 'l';

	LevelName[5] = (Mask & 8) != 0 ? '1' : '0';
	LevelName[6] = (Mask & 4) != 0 ? '1' : '0';
	LevelName[7] = (Mask & 2) != 0 ? '1' : '0';
	LevelName[8] = (Mask & 1) != 0 ? '1' : '0';

	LevelName[9] = 'V';
	LevelName[10] = 48 + Variation;

	LevelName[11] = '.';
	LevelName[12] = 'b';
	LevelName[13] = 'm';
	LevelName[14] = 'p';
	LevelName[15] = 0;
	SDL_Surface* _Surface = SDL_LoadBMP(LevelName);

	unsigned char* _TexData = (unsigned char*)_Surface->pixels;

	for (int y = 0; y < 32; y++)
		for (int x = 0; x < 32; x++)
		{
			unsigned char B = *_TexData;
			unsigned char G = *(_TexData + 1);
			unsigned char R = *(_TexData + 2);

			unsigned char BAbove = y > 0 ? *(_TexData - 96 + 0) : 0;
			unsigned char GAbove = y > 0 ? *(_TexData - 96 + 1) : 0;
			unsigned char RAbove = y > 0 ? *(_TexData - 96 + 2) : 0;
			unsigned char BBelow = y < 31 ? *(_TexData + 96 + 0) : 0;
			unsigned char GBelow = y < 31 ? *(_TexData + 96 + 1) : 0;
			unsigned char RBelow = y < 31 ? *(_TexData + 96 + 2) : 0;


			// Stone
			if (R == 255 && G == 0 && B == 0)
			{
				m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 12 + rand() % 4, 1, XSection + x, YSection + y, true));
			}
			// DarkStone
			if (R == 255 && G == 255 && B == 0)
			{
				m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 6 + rand() % 5, 2, XSection + x, YSection + y, true));
			}
			// Obsidian
			if (R == 0 && G == 255 && B == 255)
			{
				m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 1 + rand() % 5, 1, XSection + x, YSection + y, true));
			}


			// WaterStone
			if (R == 0 && G == 128 && B == 255)
			{
				if (RAbove == 0 && GAbove == 128 && BAbove && 255)
					m_Objects.push_back(new LayeredGridObject(m_pTextureAtlas, p_pPhysicsSpace, 2 + rand() % 4, 4, XSection + x, YSection + y, 2));
				else
					m_Objects.push_back(new LayeredGridObject(m_pTextureAtlas, p_pPhysicsSpace, 2 + rand() % 4, 3, XSection + x, YSection + y, 2));
			}
			// Water
			if (R == 0 && G == 0 && B == 255)
			{
				if (RAbove == 0 && GAbove == 0 && BAbove && 255)
					m_Objects.push_back(new LayeredGridObject(m_pTextureAtlas, p_pPhysicsSpace, 1, 4, XSection + x, YSection + y, 2));
				else
					m_Objects.push_back(new LayeredGridObject(m_pTextureAtlas, p_pPhysicsSpace, 1, 3, XSection + x, YSection + y, 2));
			}

			// Dirt
			if (R == 0 && G == 255 && B == 0)
			{
				if (RAbove == 255 && GAbove == 255 && BAbove == 255)
				{
					srand(x);
					m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 2 + rand() % 4, 2, XSection + x, YSection + y, true));
				}
				else
					if (RBelow == 0 && GBelow == 255 && BBelow == 0)
					{
						srand(x);
						m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 3 + rand() % 4, 0, XSection + x, YSection + y, true));
					}
					else
					{
						srand(x);
						m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 8 + rand() % 4, 0, XSection + x, YSection + y, true));
					}
			}

			if (R == 255 && G == 000 && B == 255)
			{
				if (RAbove == 255 && GAbove == 000 && BAbove == 255)
				{
					if (RBelow == 255 && GBelow == 000 && BBelow == 255)
					{
						m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 10, 1, XSection + x, YSection + y, true));
					}
					else
					{
						m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 11, 1, XSection + x, YSection + y, true));
					}
				}
				else
				{
					m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 9, 1, XSection + x, YSection + y, true));
				}
			}
			


			_TexData += 3;
		}

}

void LevelSection::Update(float DeltaTime)
{

}

void LevelSection::Draw(Renderer* p_pRenderer, b2Vec2 CameraPosition)
{
	for (auto _It = m_Objects.begin(); _It != m_Objects.end(); _It++)
	{
		(*_It)->Draw(p_pRenderer, CameraPosition);
	}
}