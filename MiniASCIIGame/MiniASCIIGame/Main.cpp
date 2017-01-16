#include "Level.h"
#include <iostream>
using namespace std;

bool IsPathable(char p_Character, int KeyCount)
{
	switch (p_Character)
	{
	case '#':
		return false;

	case 'D':
		return KeyCount > 0;

	default:
		return true;
	}
}

void DisplayStatusBar(int KeyCount)
{
	cout << "Keycount: " << KeyCount << "\n";
}

void main()
{
	Level* _Level = new Level();

	int PlayerXPos = 5;
	int PlayerYPos = 5;
	int KeyCount = 0;

	while (true)
	{
		system("cls");

		// Zeichnen
		DisplayStatusBar(KeyCount);

		_Level->DrawLevel(PlayerXPos, PlayerYPos);

		// Input
		char Input;
		cin >> Input;

		if (Input == 'd' && IsPathable(_Level->GetBackground(PlayerXPos + 1, PlayerYPos), KeyCount))
		{
			PlayerXPos++;
		}
		if (Input == 'a'&& IsPathable(_Level->GetBackground(PlayerXPos - 1, PlayerYPos), KeyCount))
		{
			PlayerXPos--;
		}
		if (Input == 'w'&& IsPathable(_Level->GetBackground(PlayerXPos, PlayerYPos - 1), KeyCount))
		{
			PlayerYPos--;
		}
		if (Input == 's'&& IsPathable(_Level->GetBackground(PlayerXPos, PlayerYPos + 1), KeyCount))
		{
			PlayerYPos++;
		}

		char _CurrentCharacter = _Level->GetBackground(PlayerXPos, PlayerYPos);

		if (_CurrentCharacter == 'K')
		{
			KeyCount++;
			_Level->SetBackground(PlayerXPos, PlayerYPos, '.');
		}

		if (_CurrentCharacter == 'D')
		{
			KeyCount--;
			_Level->SetBackground(PlayerXPos, PlayerYPos, '.');
		}
		if (_CurrentCharacter == 'T')
		{
			system("cls");
			DisplayStatusBar(KeyCount);
			_Level->DrawLevel(PlayerXPos, PlayerYPos);

			cout << "Schatz gefunden, victory!" << "\n";
			break;
		}
	}

	delete _Level;
}















