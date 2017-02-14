#include "LevelSection.h"
#include "GridObject.h"

void LevelSection::Init(Renderer* p_pRenderer, b2World* p_pPhysicsSpace)
{
	m_pTextureAtlas = new Texture("Tileset.png", p_pRenderer);
	int i = 0;

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
	SDL_Surface* _Surface = SDL_LoadBMP("Level0.bmp");

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
				m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 12 + rand() % 4, 1, x, y, true));
			}
			// DarkStone
			if (R == 255 && G == 255 && B == 0)
			{
				m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 6 + rand() % 5, 2, x, y, true));
			}
			// Obsidian
			if (R == 0 && G == 255 && B == 255)
			{
				m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 1 + rand() % 5, 1, x, y, true));
			}


			// WaterStone
			if (R == 0 && G == 128 && B == 255)
			{
				if (RAbove == 0 && GAbove == 128 && BAbove && 255)
					m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 2 + rand() % 4, 4, x, y, false));
				else
					m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 2 + rand() % 4, 3, x, y, false));
			}
			// Water
			if (R == 0 && G == 0 && B == 255)
			{
				if (RAbove == 0 && GAbove == 0 && BAbove && 255)
					m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 1, 4, x, y, false));
				else
					m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 1, 3, x, y, false));
			}

			// Dirt
			if (R == 0 && G == 255 && B == 0)
			{
				if (RAbove == 255 && GAbove == 255 && BAbove == 255)
				{
					srand(x);
					m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 2 + rand() % 4, 2, x, y, true));
				}
				else
					if (RBelow == 0 && GBelow == 255 && BBelow == 0)
					{
						srand(x);
						m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 3 + rand() % 4, 0, x, y, true));
					}
					else
					{
						srand(x);
						m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 8 + rand() % 4, 0, x, y, true));
					}
			}

			if (R == 255 && G == 000 && B == 255)
			{
				if (RAbove == 255 && GAbove == 000 && BAbove == 255)
				{
					if (RBelow == 255 && GBelow == 000 && BBelow == 255)
					{
						m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 10, 1, x, y, true));
					}
					else
					{
						m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 11, 1, x, y, true));
					}
				}
				else
				{
					m_Objects.push_back(new GridObject(m_pTextureAtlas, p_pPhysicsSpace, 9, 1, x, y, true));
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