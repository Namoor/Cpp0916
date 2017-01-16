#pragma once


class Level
{
public:
	Level();

	void DrawLevel(int PlayerXPos, int PlayerYPos);

	char GetBackground(int x, int y);
	void SetBackground(int x, int y, char value);

private:
	char* m_pLevelData;
};