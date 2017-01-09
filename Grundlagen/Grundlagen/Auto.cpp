#include "Auto.h"

#include <iostream>
using namespace std;

Auto::Auto()
{
	//cout << "Neues Auto erstellt\n";
	TankLevel = 10;

	Radanzahl = new int();
	*Radanzahl = 4;
}

Auto::~Auto()
{
	if (Radanzahl != nullptr)
	{
		delete Radanzahl;
		Radanzahl = nullptr;
	}
}

int Auto::GetWheelCount()
{
	return 4;
}

void Auto::Update()
{

}

void Auto::Drive()
{
	cout << "Das Auto fährt";
}

void Auto::MakeNoise()
{
	cout << "Das Auto macht \"VROOM\"\n";
}

int Auto::GetTankLevel()
{
	return TankLevel;
}