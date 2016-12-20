#pragma once


class Auto
{
public:
	Auto();
	~Auto();

	void Drive();
	void MakeNoise();

	int GetTankLevel();
protected:
	int TankLevel;

	int* Radanzahl;

};