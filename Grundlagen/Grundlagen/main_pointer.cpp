#include "Auto.h"

#include <iostream>
using namespace std;

void DoStuff(int* x)
{
	*x = 4;
}


struct Player
{
	int Level;
	int HP;
	int Mana;
};

void main()
{
	int i = 0;
	int* x = &i;

	int* y = new int();

	Player* _Player1 = new Player();
	_Player1->Level = 1;

	while (true)
	{
		Auto* _pAuto = new Auto();

		delete _pAuto;
		_pAuto = nullptr;
	}

	//_pAuto->Drive();
	//_pAuto->MakeNoise();
	//cout << "Tank Level vom Auto: " << _pAuto->GetTankLevel() << "\n";

	//x = (int*)4; // Pointer auf Adresse 4 zeigen lassen

	// nullptr == Adresse 0
	//if (x != nullptr)
	//	*x = 4;

	delete _Player1;
	_Player1 = nullptr;
	delete y;
	y = nullptr;
}