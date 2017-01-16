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

void DisplayStatusBar(int KeyCount, int HP)
{
	cout << "Keycount: " << KeyCount << " HP: " << HP << "\n";
}

void main()
{
	Level* _Level = new Level();

	int PlayerXPos = 5;
	int PlayerYPos = 5;
	int KeyCount = 0;
	int HP = 100;

	while (true)
	{
		system("cls");

		// Zeichnen
		DisplayStatusBar(KeyCount, HP);

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
			DisplayStatusBar(KeyCount, HP);
			_Level->DrawLevel(PlayerXPos, PlayerYPos);

			cout << "Schatz gefunden, victory!" << "\n";
			break;
		}

		if (_CurrentCharacter == 'E')
		{
			int EnemyHP = 100;

			system("cls");

			while (EnemyHP > 0)
			{
				DisplayStatusBar(KeyCount, HP);
				cout << "EnemyHP: " << EnemyHP << "\n";
				cout << "Your Action: ";

				char Action;
				cin >> Action;

				switch (Action)
				{
				case 'a':
					EnemyHP -= 20;
					cout << "Ihr schlagt den Gegner für 20 Schaden\n";
					break;
				case 'h':
					HP += 50;
					if (HP > 100)
						HP = 100;
					cout << "Ihr heilt euch für bis zu 50 HP\n";

					break;
				}

				if (EnemyHP > 0)
				{
					HP -= 20;
					cout << "Gegner schlägt euch für 20 Schaden \n";

					if (HP <= 0)
					{
						// Verloren
						system("cls");
						DisplayStatusBar(KeyCount, HP);
						cout << "Ihr habt alle Leben verloren und sterbt\n";
						return;
					}
				}
			}

			_Level->SetBackground(PlayerXPos, PlayerYPos, '.');
		}
	}

	delete _Level;
}















