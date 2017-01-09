#pragma once

#include "Fahrzeug.h"
#include "IUpdateable.h"

class Auto : public Fahrzeug, IUpdateable
{
public:
	Auto();
	~Auto();

	virtual void Drive() override;

	virtual int GetWheelCount() override;

	virtual void Update() override;

	void MakeNoise();

	int GetTankLevel();
protected:
	int TankLevel;

	int* Radanzahl;

};